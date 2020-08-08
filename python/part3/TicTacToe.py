class Game:
    def __init__(self):
        self.board = [[0 for i in range(3)] for j in range(3)]
        self.player = 1
        
    def play(self, i, j):
        self.board[i][j] = self.player

    def choiceValidity(self, i, j):
        return 0<=i<=2 and 0<=j<=2 and self.board[i][j]==0
        
    def changePlayer(self):
        self.player = 2 - (self.player+1)%2
        
    def getPlayer(self):
        return self.player
        
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
