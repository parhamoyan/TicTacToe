import sys
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QLabel, QMessageBox
from PyQt5.QtGui import QIcon, QPainter, QColor, QBrush, QPen, QMouseEvent, QPixmap
from PyQt5.QtCore import Qt
from TicTacToe import Game

class App(QWidget):
    def __init__(self):
        super().__init__()
        self.game = Game()
        self.title = 'Tic Tac Toe'
        self.left = 10
        self.top = 10
        self.width = 680
        self.height = 680
        self.labels = [[QLabel(self) for i in range(3)] for j in range(3)]
        for i in range(3):
            for j in range(3):
                self.labels[i][j].setGeometry(30+220*i, 20+220*j, 200, 200)
        self.messages = ["Player X has won !", "Player O has won !", "Game Draw"]
        self.initUI()
        
    def initUI(self):
        self.setWindowTitle(self.title)
        self.setGeometry(self.left, self.top, self.width, self.height)
        self.show()
    
    def paintEvent(self, event):
        painter = QPainter(self)
        painter.setPen(QPen(QColor(100,100,100), 0, Qt.SolidLine))
        painter.setBrush(QBrush(QColor(100,100,100), Qt.SolidPattern))
        painter.drawRect(220, 20, 20, 640)
        painter.drawRect(440, 20, 20, 640)
        painter.drawRect(20, 220, 640, 20)
        painter.drawRect(20, 440, 640, 20)
        
    def mousePressEvent(self, event):
        i, j = event.pos().x()//220, event.pos().y()//220
        if self.game.choiceValidity(i, j) and not self.game.checkWin():
            self.game.play(i, j)
            pixmap = QPixmap("{}_PLAYER.png".format(["X", "O"][self.game.getPlayer()-1])).scaled(180, 180)
            self.labels[i][j].setPixmap(pixmap)
            if self.game.checkWin():
                buttonReply = QMessageBox.question(self, 'Message', self.messages[self.game.getPlayer()], QMessageBox.Ok)
            self.game.changePlayer()
            
if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = App()
    sys.exit(app.exec_()) 
