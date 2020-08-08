import javax.imageio.ImageIO;
import java.awt.*;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.event.MouseInputAdapter;
import java.awt.event.MouseListener;
import java.awt.event.MouseEvent;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.color;

public class Gui extends JFrame
{
    private Image t;
    private Image[][] images = new Image[3][3];
    private TicTacToe game = new TicTacToe();
    public Gui()
    {
        addMouseListener(new MouseInputAdapter()
        {
            public void mousePressed(MouseEvent e)
            {
                int j = e.getX()/220;
                int i = e.getY()/220;
                if (game.choiceValidty(i, j) && game.checkWin()==0)
                {
                    game.play(i, j);
                    game.changePlayer();
                    repaint();
                    optionPane();
                }
            }
        });
        setTitle("Tic Tac Toe");
        setSize(680,700); // JFrame dimensions
        setLocation(500,100); // JFrame location
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
    public void optionPane()
    {
        if (game.checkWin()!=0){
            if (game.checkWin()==1)
            {
                JOptionPane.showMessageDialog(this, "Player X has won !");
            }
            else if (game.checkWin()==2)
            {
                JOptionPane.showMessageDialog(this, "Player X has won !");
            }
            else
            {
                JOptionPane.showMessageDialog(this, "Game Draw");
            }
        }
    }

    public void paint(Graphics g)
    {
        // draw 4 rectangles
        g.setColor(new Color(100, 100, 100));
        g.fillRect(220, 40, 20, 640);
        g.fillRect(440, 40, 20, 640);
        g.fillRect(20, 240, 640, 20);
        g.fillRect(20, 460, 640, 20);
        
        for (byte i=0; i<3; i++){
            for (byte j=0; j<3; j++){
                if (game.getPlayer(i, j)==1){
                    images[i][j] = Toolkit.getDefaultToolkit().getImage("X_PLAYER.png");;
                    g.drawImage(images[i][j], 30+220*j, 50+220*i, 180, 180, this);
                }
                else if (game.getPlayer(i, j)==2){
                    images[i][j] = Toolkit.getDefaultToolkit().getImage("O_PLAYER.png");;
                    g.drawImage(images[i][j], 30+220*j, 50+220*i,180, 180, this);
                }
            }
        }
    }
    public static void main(String[] args)
    {
        Gui GUI = new Gui();
    }
}
