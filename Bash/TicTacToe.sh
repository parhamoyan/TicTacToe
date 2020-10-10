#! /bin/bash

board=(" " " " " " " " " " " " " " " " " ")
symbols=("X" "O")
player=1

display(){
    echo "  ${board[0]} | ${board[1]} | ${board[2]}"
    echo "-------------"
    echo "  ${board[3]} | ${board[4]} | ${board[5]}"
    echo "-------------"
    echo "  ${board[6]} | ${board[7]} | ${board[8]}"
}


while true
do
    clear
    display
    echo "Enter i : "
    read i
    echo "Enter j : "
    read j
    echo ${board[i*3+j]}
    if [[ "${board[i*3+j]}" == " " ]]
    then
        board[i*3+j]=${symbols[player-1]}
        player=$(((player)%2+1))
        echo "Player = " "${player}"
    fi
done
