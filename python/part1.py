import os

def display():
    print(*[" "*4+"{} | {} | {}\n".format(*[symbols[index] for index in board[i]]) for i in range(3)], sep=" "*3+"-"*11+"\n")

def play(i, j):
    board[i][j] = player

def choiceValidity(i, j):
    return 0<=i<=2 and 0<=j<=2 and board[i][j]==0

def checkWin():
    all_lists = [column for column in board] \
            + [[board[i][row] for i in range(3)] for row in range(3)] \
            + [[board[i][i] for i in range(3)]] + [[board[i][2-i] for i in range(3)]]
    for alist in all_lists:
        if len(set(alist))==1 and list(set(alist))[0]:
            return alist[0]
    if sum([1 for i in range(3) for j in range(3) if board[i][j]])==9:
        return 3
    return 0

def clear(): 
    if os.name == 'nt':
        os.system('cls') 
    else: 
        os.system('clear')

if __name__ == "__main__":
    board = [[0 for i in range(3)] for j in range(3)]
    player = 1
    symbols = [" ", "X", "O"]
    display()
    while not checkWin():
        i = int(input("Enter i : "))
        j = int(input("Enter j : "))
        if choiceValidity(i, j):
            play(i, j)
        player = 2 - (player+1)%2
        clear()
        display()
    if checkWin()==3:
        print("Game Draw")
    else:
        print("Player {} has won !".format(["X", "O"][checkWin()-1]))
