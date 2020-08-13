#include <stdio.h>
#include <stdlib.h>

int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
char symbols[3] = {' ', 'X', 'O'};
int player = 1;

void display();
void play(int i, int j);
void changePlayer();
int checkWin();

int main()
{	
	int i, j;
	system("clear");
	display();
	while (checkWin()==0){
		printf("Enter i : ");
		scanf("%d", &i);
		printf("Enter j : ");
		scanf("%d", &j);
		play(i, j);
		display();
		changePlayer();
	}
	int result = checkWin();
	if (result==1 || result==2){
		printf("Player %c has won !\n", symbols[result-1]);
	}
	else{
		printf("Game Draw !\n");
	}
	return 0;
}

void display(){
	system("clear");
	printf("\n");
	for (int i=0; i<3; i++){
		printf("    %c | %c | %c\n", symbols[board[i][0]], symbols[board[i][1]], symbols[board[i][2]]);
		if (i<2){
			printf("   -----------\n");
		}
	}
	printf("\n");
}

void play(int i, int j){
	board[i][j] = player;
}

void changePlayer(){
	player = 2-(player+1)%2;
}

int checkWin(){
	for (int i=0; i<3; i++){
		if (board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][2]!=0){
			return board[i][2];
		}
	}
	for (int j=0; j<3; j++){
		if (board[0][j]==board[1][j] && board[1][j]==board[2][j] && board[2][j]!=0){
			return board[2][j];
		}
	}
	if (board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[2][2]!=0){
		return board[2][2];
	}
	if (board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[2][0]!=0){
		return board[2][0];
	}
	int sum=0;
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			if (board[i][j]!=0){
				sum += board[i][j];
			}
		}
	}
	if (sum==9){
		return 3;
	}
	return 0;
}