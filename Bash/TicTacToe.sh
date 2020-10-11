#! /bin/bash

board=(0 0 0 0 0 0 0 0 0)
symbols=(" " "X" "O")
player=1
gameStatus=0

display(){
    echo
    echo "  ${symbols[board[0]]} | ${symbols[board[1]]} | ${symbols[board[2]]}"
    echo "-------------"
    echo "  ${symbols[board[3]]} | ${symbols[board[4]]} | ${symbols[board[5]]}"
    echo "-------------"
    echo "  ${symbols[board[6]]} | ${symbols[board[7]]} | ${symbols[board[8]]}"
    echo
}


checkCase(){
    if [ ${board[$1]} != 0 ] && [ ${board[$1]} == ${board[$2]} ] && [ ${board[$2]} == ${board[$3]} ]
    then
        gameStatus=${board[$1]}
    fi
}

checkWin(){
    # check all rows
    i=0
    while [ ${gameStatus} == 0 ] && [ ${i} -lt 3 ]
    do
        checkCase $(( 3*i )) $(( 3*i+1 )) $(( 3*i+2 ))
        i=$((i+1))
    done
    # check all columns
    i=0
    while [ ${gameStatus} == 0 ] && [ ${i} -lt 3 ]
    do
        checkCase $(( i )) $(( i+3 )) $(( i+6 ))
        i=$((i+1))
    done
    # check all diagonals
    checkCase 0 4 8
    checkCase 2 4 6
}

clear
display
while true
do
    echo "Enter i : "
    read i
    echo "Enter j : "
    read j
    if [[ ${board[i*3+j]} == 0 ]]
    then
        board[i*3+j]=${player}
        player=$(((player)%2+1))
    fi
    clear
    display
    checkWin
    if [ $gameStatus != 0 ]; then
        echo "Player" "${symbols[gameStatus]}" "has won !"
        break
    fi
done
