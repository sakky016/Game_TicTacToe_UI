#include <QmessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    m_gameData = nullptr;
    m_userScore = 0;
    m_computerScore = 0;

    ui->setupUi(this);

    // Prepare button mapping
    CreateBoard();

    ui->statusBar->showMessage("Click on 'New Game' to begin");
}

MainWindow::~MainWindow()
{
    delete ui;
}

//--------------------------------------------------------------------------------
// @name                    : CreateBoard
//
// @description             : Prepares the button map
//
// @return                  : Nothing
//--------------------------------------------------------------------------------
void MainWindow::CreateBoard()
{
    m_board.push_back(ui->btnPos1);
    m_board.push_back(ui->btnPos2);
    m_board.push_back(ui->btnPos3);
    m_board.push_back(ui->btnPos4);
    m_board.push_back(ui->btnPos5);
    m_board.push_back(ui->btnPos6);
    m_board.push_back(ui->btnPos7);
    m_board.push_back(ui->btnPos8);
    m_board.push_back(ui->btnPos9);
}

//--------------------------------------------------------------------------------
// @name                    : EnableGame
//
// @description             : Enable/Disable game board buttons
//
// @return                  : Nothing
//--------------------------------------------------------------------------------
void MainWindow::EnableGame(bool bEnable)
{
    auto boardMap = m_gameData->GetBoardMap();
    size_t index = 0;
    for (auto it = m_board.begin(); it != m_board.end(); it++)
    {
        QAbstractButton *btn = *it;
        if (boardMap[index] == PLAYER_NONE)
        {
            btn->setEnabled(bEnable);
        }
        else
        {
            btn->setEnabled(false);
        }

        index++;
    }
}

//--------------------------------------------------------------------------------
// @name                    : UpdateScores
//
// @description             : Updates user and computer scores
//
// @return                  : Nothing
//--------------------------------------------------------------------------------
void MainWindow::UpdateScores()
{
    ui->scoreUser->setText(QString::number(m_userScore));
    ui->scoreComputer->setText(QString::number(m_computerScore));
}

//--------------------------------------------------------------------------------
// @name                    : EnableGame
//
// @description             : Enables all buttons if bEnable is true
//
// @return                  : Nothing
//--------------------------------------------------------------------------------
void MainWindow::InitializeGameBoard()
{
    for (auto it = m_board.begin(); it != m_board.end(); it++)
    {
        QAbstractButton *btn = *it;
        btn->setEnabled(true);
        btn->setText(".");
    }
}

//--------------------------------------------------------------------------------
// @name                    : MarkBoardPosition
//
// @description             : Executed each time a board button is pressed. It
//                            marks the player selection on the board.
//
// @return                  : Nothing
//--------------------------------------------------------------------------------
void MainWindow::MarkBoardPosition(size_t position, Player_t player)
{
    // Update game data
    m_gameData->AddPlayerMarkToBoard(position, player);

    // Update UI
    QString playerMark = (player == PLAYER_USER) ? USER_MARK : COMPUTER_MARK;
    m_board[position]->setText(playerMark);
    m_board[position]->setEnabled(false);    

    // Check win
    Player_t playerWon = m_gameData->CheckWin();
    if (playerWon == PLAYER_USER)
    {
        m_userScore++;
        ui->statusBar->showMessage("Congratulations!!! You Won.");
        QMessageBox msgBox;
        msgBox.setWindowTitle("Congratulations");
        msgBox.setText("You won the game");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }
    else if (playerWon == PLAYER_COMPUTER)
    {
        m_computerScore++;
        ui->statusBar->showMessage("Computer won the game.");
        QMessageBox msgBox;
        msgBox.setWindowTitle("Game Over");
        msgBox.setText("Computer won the game");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }
    else if (m_gameData->GameOver())
    {
        ui->statusBar->showMessage("Game Tied");
        QMessageBox msgBox;
        msgBox.setWindowTitle("Game Over");
        msgBox.setText("Game was tied");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        EnableGame(false);
    }
    else if (player == PLAYER_USER)
    {
        // If this move was user's, the next one should be of computer.
        SimulateComputerMove();
    }
    else
    {
        // DO NOTHING
    }

    UpdateScores();
}

//--------------------------------------------------------------------------------
// @name                    : UpdatePlayerTurn
//
// @description             : Update turn indicator on UI
//
// @return                  : Nothing
//--------------------------------------------------------------------------------
void MainWindow::UpdatePlayerTurn(Player_t player)
{
    if (player == PLAYER_COMPUTER)
    {
        ui->statusBar->showMessage("Computer's turn");

        QPalette paletteUser;
        QPalette paletteComputer;
        paletteComputer.setColor(ui->lblComputerMarker->foregroundRole(), Qt::blue);
        paletteUser.setColor(ui->lblUserMarker->foregroundRole(), Qt::black);

        ui->lblUserMarker->setPalette(paletteUser);
        ui->lblComputerMarker->setPalette(paletteComputer);
        ui->lblMarker1->setText("");
        ui->lblMarker2->setText("^");
    }
    else if (player == PLAYER_USER)
    {
        ui->statusBar->showMessage("Your turn");

        QPalette paletteUser;
        QPalette paletteComputer;
        paletteComputer.setColor(ui->lblComputerMarker->foregroundRole(), Qt::black);
        paletteUser.setColor(ui->lblUserMarker->foregroundRole(), Qt::blue);

        ui->lblUserMarker->setPalette(paletteUser);
        ui->lblComputerMarker->setPalette(paletteComputer);
        ui->lblMarker1->setText("^");
        ui->lblMarker2->setText("");
    }
}

//--------------------------------------------------------------------------------
// @name                    : SimulateComputerMove
//
// @description             : Simulates the computer's move in a separate thread.
//
// @return                  : Nothing
//--------------------------------------------------------------------------------
void MainWindow::SimulateComputerMove()
{
    UpdatePlayerTurn(PLAYER_COMPUTER);

    // Disable user interaction
    EnableGame(false);

    ComputerMoveWorker* worker = new ComputerMoveWorker(m_gameData);
    connect(worker, SIGNAL(ComputerMoveAvailable(int)), this, SLOT(OnComputerMoveAvailable(int)));
    worker->start();
}

//--------------------------------------------------------------------------------
// @name                    : OnComputerMoveAvailable
//
// @description             : Triggered when the computer's move is available.
//
// @return                  : Nothing
//--------------------------------------------------------------------------------
void MainWindow::OnComputerMoveAvailable(int move)
{
    // Mark computer's move on board
    MarkBoardPosition(static_cast<size_t>(move), PLAYER_COMPUTER);

    // Prompt for user move only if game is not over
    if (!m_gameData->GameOver())
    {
        UpdatePlayerTurn(PLAYER_USER);

        // Enable user interaction
        EnableGame(true);
    }
}

//--------------------------------------------------------------------------------
// On Button Clicked: Quit
//--------------------------------------------------------------------------------
void MainWindow::on_btnQuit_clicked()
{
    QApplication::quit();
}

//--------------------------------------------------------------------------------
// On Button Clicked: New Game
//--------------------------------------------------------------------------------
void MainWindow::on_btnNewGame_clicked()
{
    if (m_gameData)
    {
        delete m_gameData;
    }

    m_gameData = new Game();
    InitializeGameBoard();
    EnableGame(true);
    UpdateScores();

    if (m_gameData->GetTurn() == PLAYER_USER)
    {
        UpdatePlayerTurn(PLAYER_USER);
    }
    else
    {
        SimulateComputerMove();
    }
}


//--------------------------------------------------------------------------------
// On Button Clicked: Button 1 through 9
//--------------------------------------------------------------------------------
void MainWindow::on_btnPos1_clicked()
{
    MarkBoardPosition(0, PLAYER_USER);
}

void MainWindow::on_btnPos2_clicked()
{
    MarkBoardPosition(1, PLAYER_USER);
}

void MainWindow::on_btnPos3_clicked()
{
    MarkBoardPosition(2, PLAYER_USER);
}

void MainWindow::on_btnPos4_clicked()
{
    MarkBoardPosition(3, PLAYER_USER);
}

void MainWindow::on_btnPos5_clicked()
{
    MarkBoardPosition(4, PLAYER_USER);
}

void MainWindow::on_btnPos6_clicked()
{
    MarkBoardPosition(5, PLAYER_USER);
}

void MainWindow::on_btnPos7_clicked()
{
    MarkBoardPosition(6, PLAYER_USER);
}

void MainWindow::on_btnPos8_clicked()
{
    MarkBoardPosition(7, PLAYER_USER);
}

void MainWindow::on_btnPos9_clicked()
{
    MarkBoardPosition(8, PLAYER_USER);
}
