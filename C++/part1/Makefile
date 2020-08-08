output: main.o TicTacToe.o
	g++ main.o TicTacToe.o -o output

main.o: main.cpp
	g++ -c main.cpp

TicTacToe.o: TicTacToe.cpp TicTacToe.hpp
	g++ -c TicTacToe.cpp

clean:
	rm *.o output
