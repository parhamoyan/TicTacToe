# TicTacToe game

import os
class Game:
    def __init__(self):
        self.board = [[0 for i in range(3)] for j in range(3)]
        self.player = 1
        self.symbols = [" ", "X", "O"]
    
    def display(self):
        print(*[" "*4+"{} | {} | {}\n".format(*[self.symbols[index] for index in self.board[i]]) for i in range(3)], sep=" "*3+"-"*11+"\n")

    def play(self, i, j):
        self.board[i][j] = self.player

    def choiceValidity(self, i, j):
        return 0<=i<=2 and 0<=j<=2 and self.board[i][j]==0

    def checkWin(self):
        all_lists = [column for column in self.board] \
                + [[self.board[i][row] for i in range(3)] for row in range(3)] \
                + [[self.board[i][i] for i in range(3)]] + [[self.board[i][2-i] for i in range(3)]]
        for alist in all_lists:
            if len(set(alist))==1 and list(set(alist))[0]:
                return alist[0]
        if sum([1 for i in range(3) for j in range(3) if self.board[i][j]])==9:
            return 3
        return 0

    def clear(self): 
        if os.name == 'nt':
            os.system('cls') 
        else: 
            os.system('clear')
            
    def start(self):
        self.display()
        while not self.checkWin():
            i = int(input("Enter i : "))
            j = int(input("Enter j : "))
            if self.choiceValidity(i, j):
                self.play(i, j)
                self.player = 2 - (self.player+1)%2
            self.clear()
            self.display()
        if self.checkWin()==3:
            print("Game Draw")
        else:
            print("Player {} has won !".format(self.symbols[self.checkWin()]))

if __name__ == "__main__":
    game = Game()
    game.start()
