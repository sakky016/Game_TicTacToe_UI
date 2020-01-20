#include "game.h"
#include <iostream>
#include <time.h>
#include <Windows.h>

const std::vector<std::vector<size_t>> WIN_PATTERNS = {
    {0,1,2},
    {3,4,5},
    {6,7,8},
    {0,3,6},
    {1,4,7},
    {2,5,8},
    {0,4,8},
    {2,4,6},
};


Game::Game()
{
    srand(static_cast<int>(time(nullptr)));

    // Initialize scores
    m_userScore = 0;
    m_computerScore = 0;

    m_isGameOver = false;

    // Initialize the board map
    for (size_t i = 0; i < 9; i++)
    {
        m_boardMap[i] = PLAYER_NONE;
    }

    // Randomly decide who plays first
    if (rand() % 100 > 50)
    {
        m_currentTurn = PLAYER_USER;
    }
    else
    {
        m_currentTurn = PLAYER_COMPUTER;
    }
}

//--------------------------------------------------------------------------------
// @name                    : GetTurn
//
// @description             : Determines whose turn is this
//
// @return                  : Player_t
//--------------------------------------------------------------------------------
Player_t Game::GetTurn()
{
    return m_currentTurn;
}

//--------------------------------------------------------------------------------
// @name                    : GetScore
//
// @description             : Fetches score of specified player
//
// @return                  : int
//--------------------------------------------------------------------------------
int Game::GetScore(Player_t player)
{
    return (player == PLAYER_USER) ? m_userScore : m_computerScore;
}

//--------------------------------------------------------------------------------
// @name                    : AddPlayerMarkToBoard
//
// @description             : Mark the player's move on the board. It also
//                            determines if the player has won.
//
// @return                  : Nothing
//--------------------------------------------------------------------------------
void Game::AddPlayerMarkToBoard(size_t position, Player_t player)
{
    if (m_boardMap[position] != PLAYER_NONE)
    {
        assert(0);
    }

    m_boardMap[position] = player;

    if (CheckWin() == PLAYER_USER)
    {
        m_isGameOver = true;
        m_userScore++;
    }
    else if (CheckWin() == PLAYER_COMPUTER)
    {
        m_computerScore++;
        m_isGameOver = true;
    }
    else
    {
        // Check if there is a free spot available
        m_isGameOver = true;
        for (size_t i = 0; i < 9; i++)
        {
            if (m_boardMap[i] == PLAYER_NONE)
            {
                // Free spot available, game is on
                m_isGameOver = false;
                break;
            }
        }
    }
}

//--------------------------------------------------------------------------------
// @name                    : CheckWinPattern
//
// @description             : Check if we have a winning pattern for this player.
//
// @return                  : true/false
//--------------------------------------------------------------------------------
bool Game::CheckWinPattern(Player_t player, const std::vector<size_t> & playerPattern)
{
    // Match with winning patterns
    for (auto it = WIN_PATTERNS.begin(); it != WIN_PATTERNS.end(); it++)
    {
        std::vector<size_t> winPattern = *it;
        int foundIndices = 0;
        for (size_t index = 0; index < winPattern.size(); index++)
        {
            if (std::find(playerPattern.begin(), playerPattern.end(), winPattern[index]) != playerPattern.end())
            {
                foundIndices++;
            }
        }

        if (foundIndices >= 3)
        {
            return true;
        }
    }

    // No match found in win patterns
    return false;
}

//--------------------------------------------------------------------------------
// @name                    : GetPlayerPattern
//
// @description             : Fetches the player's current positions on the board.
//
// @return                  : vector of pattern
//--------------------------------------------------------------------------------
std::vector<size_t> Game::GetPlayerPattern(Player_t player)
{
    std::vector<size_t> userPattern;
    // Prepare pattern of this player
    for (auto it = m_boardMap.begin(); it != m_boardMap.end(); it++)
    {
        if (it->second == player)
        {
            userPattern.push_back(it->first);
        }
    }

    return userPattern;
}

//--------------------------------------------------------------------------------
// @name                    : CheckWin
//
// @description             : Determines who has won the game
//
// @return                  : Player_t who won the game
//--------------------------------------------------------------------------------
Player_t Game::CheckWin()
{
    std::vector<size_t> userPattern = GetPlayerPattern(PLAYER_USER);
    bool userWon = CheckWinPattern(PLAYER_USER, userPattern);
    if (userWon)
    {
        return PLAYER_USER;
    }

    std::vector<size_t> computerPattern = GetPlayerPattern(PLAYER_COMPUTER);
    bool computerWon = CheckWinPattern(PLAYER_COMPUTER, computerPattern);
    if (computerWon)
    {
        return PLAYER_COMPUTER;
    }

    return PLAYER_NONE;
}

//--------------------------------------------------------------------------------
// @name                    : GameOver
//
// @description             :
//
// @return                  : true/false
//--------------------------------------------------------------------------------
bool Game::GameOver()
{
    return m_isGameOver;
}

//--------------------------------------------------------------------------------
// @name                    : GetPositionsAvailable
//
// @description             : Check the number of vacant positions
//
// @return                  : size_t
//--------------------------------------------------------------------------------
size_t Game::GetPositionsAvailable()
{
    size_t count = 0;
    for (auto it = m_boardMap.begin(); it != m_boardMap.end(); it++)
    {
        if (it->second == PLAYER_NONE)
        {
            count++;
        }
    }

    return count;
}

//--------------------------------------------------------------------------------
// @name                    : GetComputerMove
//
// @description             : This function houses the intelligence of computer's
//                            move.
//
// @return                  : position of computer's move on the board.
//--------------------------------------------------------------------------------
size_t Game::GetComputerMove()
{
    size_t move = 0;
    std::vector<size_t> moveCandidates;
    bool bMoveFound = false;

    // Pause this thread to give a feel that computer is thinking
    Sleep(1000);

    // Check all available moves
    for (auto it = m_boardMap.begin(); it != m_boardMap.end(); it++)
    {
        if (it->second == PLAYER_NONE)
        {
            move = it->first;
            moveCandidates.push_back(move);

            // Check if computer can win with this move
            std::vector<size_t> computerPattern = GetPlayerPattern(PLAYER_COMPUTER);
            computerPattern.push_back(move);
            bool bCanComputerWin = CheckWinPattern(PLAYER_COMPUTER, computerPattern);
            if (bCanComputerWin)
            {
                std::cout << "Win targetting move" << std::endl;
                bMoveFound = true;
                return move;
            }

            // Check if User can win. This logic will aim to stop human player
            // from winning.
            std::vector<size_t> userPattern = GetPlayerPattern(PLAYER_USER);
            userPattern.push_back(move);
            bool bCanComputerLoose = CheckWinPattern(PLAYER_USER, userPattern);
            if (bCanComputerLoose)
            {
                std::cout << "Loss avoidance move" << std::endl;
                bMoveFound = true;
                return move;
            }
        }
    }

    // Win not possible, select any random move
    std::cout << "Random move" << std::endl;
    return moveCandidates[rand() % moveCandidates.size()];
}

