import java.util.Scanner;

public class TicTacToe
{
    private byte[][] board = new byte[3][3];
    private byte player = 1;
    public void display()
    {
        for (int i=0; i<3; i++)
        {
            System.out.print(" ");
            for (int j=0; j<3; j++)
            {
                switch (board[i][j])
                {
                    case 0:
                    {
                        System.out.print(" ");
                        break;
                    }
                    case 1:
                    {
                        System.out.print("X");
                        break;
                    }
                    case 2:
                    {
                        System.out.print("O");
                        break;
                    }
                    default:
                        break;
                }
                if (j==2)
                {
                    System.out.print("\n");
                    break;
                }
                System.out.print(" | ");
            }
            if (i==2)
            {
                System.out.print("\n");
                    break;
            }
            System.out.println("-----------");
        }
    }

    public boolean choiceValidty(int i, int j)
    {
        if ((i<0 || i>2) || (j<0 || j>2))
        {
            return false;
        }
        if (board[i][j]!=0)
        {
            return false;
        }
        return true;
    }

    public void play(int i, int j)
    {
        board[i][j] = player;
    }
    public byte getPlayer(int i, int j)
    {
        return board[i][j];
    }

    public void changePlayer()
    {
        byte res;
        if (player==1)
            res = 2;
        else
            res = 1;
        player = res;
    }

    public byte checkWin()
    {
        for (int i=0; i<3; i++)
        {
            if (board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][2]!=0)
                return board[i][2];
        }
        for  (int j=0; j<3; j++)
        {
            if (board[0][j]==board[1][j] && board[1][j]==board[2][j] && board[2][j]!=0)
                return board[2][j];
        }
        if (board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[2][2]!=0)
            return board[2][2];
        if (board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[2][0]!=0)
            return board[2][0];
        byte res = 3;
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
} 
