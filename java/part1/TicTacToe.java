import java.util.Scanner;

public class TicTacToe
{
    private static byte[][] board = new byte[3][3];
    private static byte player = 1;
    public static void main(String[] args)
    {
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                board[i][j] = 0;
            }
        }
        display();
        while (checkWin()==0)
        {
            Scanner scanner = new Scanner(System.in);
            byte i = scanner.nextByte();
            byte j = scanner.nextByte();
            if (choiceValidty(i, j))
                play(i, j);
            display();
            changePlayer();
        }
        if (checkWin()==1){
            System.out.println("Player X has won !");
        }
        else if (checkWin()==2){
            System.out.println("Player O has won !");
        }
        else{
            System.out.println("Game Draw");
        }
    }

    public static void display()
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

    public static boolean choiceValidty(byte i, byte j)
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

    public static void play(byte i, byte j)
    {
        board[i][j] = player;
    }

    public static void changePlayer()
    {
        byte res;
        if (player==1)
            res = 2;
        else
            res = 1;
        player = res;
    }

    public static byte checkWin()
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
