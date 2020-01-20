#ifndef GAME_H
#define GAME_H
#include <map>
#include <Qthread>

typedef enum Player_tag
{
    PLAYER_USER,
    PLAYER_COMPUTER,
    PLAYER_NONE
}Player_t;

class Game
{
private:
    std::map<size_t, Player_t> m_boardMap;
    Player_t m_currentTurn;
    int m_userScore;
    int m_computerScore;
    bool m_isGameOver;

public:
    Game();
    auto GetBoardMap(){return m_boardMap;}
    int GetScore(Player_t player);
    void AddPlayerMarkToBoard(size_t position, Player_t player);
    size_t GetPositionsAvailable();
    Player_t CheckWin();
    bool CheckWinPattern(Player_t player, const std::vector<size_t> & playerPattern);
    std::vector<size_t> GetPlayerPattern(Player_t player);
    bool GameOver();
    Player_t GetTurn();
    size_t GetComputerMove();
};


//------------------------------------------------------------------------
// Worker thread that calculates Computer's move
//------------------------------------------------------------------------
class ComputerMoveWorker: public QThread
{
Q_OBJECT
private:
    Game* m_gameData;

signals:
    void ComputerMoveAvailable(int move);

public:
    ComputerMoveWorker(Game* gameData) : QThread()
    {
        m_gameData = gameData;
    }

    void run()
    {
        size_t move = m_gameData->GetComputerMove();
        emit ComputerMoveAvailable(static_cast<int>(move));
    }
};

#endif // GAME_H
