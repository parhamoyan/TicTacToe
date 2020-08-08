#include <string>
#include <iostream>

class TicTacToe
{
    private:
        unsigned char board[3][3];
        unsigned char player;
    public:
        TicTacToe();
        void display();
        bool choiceValidity(unsigned short i, unsigned short j);
        int checkWin();
        void play(unsigned short i, unsigned short j);
        void changePlayer();
        int getPlayer();
        void start();
};
