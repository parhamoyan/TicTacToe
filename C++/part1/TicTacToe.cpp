#include <iostream>
#include <stdlib.h>
#include "TicTacToe.hpp"


TicTacToe::TicTacToe()
{
    for (unsigned char i=0; i<3; i++)
        for (unsigned char j=0; j<3; j++)
            board[i][j] = 0;
    player = 1;
}

void TicTacToe::display()
{
    system("clear");
    for (unsigned char i=0; i<3; i++)
    {   
        std::cout << "\t";
        for (unsigned char j=0; j<3; j++)
        {
            if (board[i][j]==0)
                std::cout << '_' << " ";
            else if (board[i][j]==1) // Player X
                std::cout << 'X' << " ";
            else // Player Y
                std::cout << 'O' << " ";
        }
        std::cout << std::endl; // Next Line
    }
    std::cout << std::endl; // Next Line
}

bool TicTacToe::choiceValidity(unsigned short i, unsigned short j)
{
    if (!((0<=i && i<=2)  && (0<=j && j<=2)))
    {
        std::cout << "Invalide choice" << std::endl;
        return false;
    }
    else
    {
        if (board[i][j]!=0)
        {
            std::cout << "Position already used, choose another position." << std::endl;
            return false;
        }
    }
    return true;
}

int TicTacToe::checkWin()
{
    for (unsigned char i=0; i<3; i++)
    {
        if (board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][2]!=0)
            return board[i][2];
    }
    for  (unsigned char j=0; j<3; j++)
    {
        if (board[0][j]==board[1][j] && board[1][j]==board[2][j] && board[2][j]!=0)
            return board[2][j];
    }
    if (board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[2][2]!=0)
        return board[2][2];
    if (board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[2][0]!=0)
        return board[2][0];
    int res = 3;
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (board[i][j]==0)
                res = 0;
        }
    } 
    return res;
}

void TicTacToe::play(unsigned short i, unsigned short j)
{
    board[i][j] = player;
}

void TicTacToe::changePlayer()
{
    player = 2 - (player+1)%2;
}

int TicTacToe::getPlayer()
{
    return player;
}

void TicTacToe::start()
{
    display();
    while (checkWin()==0)
    {
        std::cout << "Player ";
        if (getPlayer()==1)
            std::cout << "X" << std::endl;
        else
            std::cout << "O" << std::endl;
        std::cout << std::endl;
        unsigned short i, j;
        std::cout << "Enter i : ";
        std::cin >> i;
        std::cout << "Enter j : ";
        std::cin >> j;
        if (!(choiceValidity(i,j)))
            continue;
        play(i,j);
        changePlayer();
        display();
    }
    if (checkWin()==1)
    {
        std::cout << "Player X has won !" << std::endl;
    }
    else if (checkWin()==2)
    {
        std::cout << "Player O has won !" << std::endl;
    }
    else
    {
        std::cout << "Game draw" << std::endl;
    }
}
