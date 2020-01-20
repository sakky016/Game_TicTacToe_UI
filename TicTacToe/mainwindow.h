#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "game.h"
#include <QMainWindow>
#include <QtWidgets/QAbstractButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

const QString USER_MARK = "X";
const QString COMPUTER_MARK = "O";

//Q_DECLARE_METATYPE(size_t);

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void CreateBoard();
    void EnableGame(bool bEnable);
    void InitializeGameBoard();
    void UpdateScores();
    void MarkBoardPosition(size_t position, Player_t player);
    void SimulateComputerMove();
    void UpdatePlayerTurn(Player_t player);

private slots:
    void OnComputerMoveAvailable(int move);

    void on_btnQuit_clicked();

    void on_btnNewGame_clicked();

    void on_btnPos1_clicked();

    void on_btnPos2_clicked();

    void on_btnPos3_clicked();

    void on_btnPos4_clicked();

    void on_btnPos5_clicked();

    void on_btnPos6_clicked();

    void on_btnPos7_clicked();

    void on_btnPos8_clicked();

    void on_btnPos9_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<QAbstractButton *> m_board;
    Game * m_gameData;
    int m_userScore;
    int m_computerScore;
};
#endif // MAINWINDOW_H
