var canvas = document.querySelector('#canvas');
var ctx = canvas.getContext("2d");;
var x_img = new Image();
x_img.src = "./X_PLAYER.png";
var o_img = new Image();
o_img.src = "./O_PLAYER.png";
var i, j;
var board = [[0, 0, 0], [0, 0, 0], [0, 0, 0]];
var player = 1;

window.addEventListener('load', () =>{
	canvas.height = 680;
	canvas.width = 680;
  ctx.fillStyle = 'rgb(100, 100, 100)';
	ctx.fillRect(220, 20, 20, 640);
	ctx.fillRect(440, 20, 20, 640);
	ctx.fillRect(20, 220, 640, 20);
	ctx.fillRect(20, 440, 640, 20);
});

canvas.onclick = function(e) {
  i = Math.floor(e.offsetX/220);
  j = Math.floor(e.offsetY/220);
  if (choiceValidity(j, i) && !checkWin()){
    if (player==1){
      ctx.drawImage(x_img, 30+220*i, 30+220*j, 180, 180);
    }
    else{
      ctx.drawImage(o_img, 30+220*i, 30+220*j, 180, 180);
    }
    play(j, i);
    changePlayer();
    console.log(checkWin());
  }
}


function display(){
  console.log(board[0][0], board[0][1], board[0][2]);
  console.log(board[1][0], board[1][1], board[1][2]);
  console.log(board[2][0], board[2][1], board[2][2]);
}

function changePlayer(){
  player = 2-(player+1)%2;
}

function play(i, j){
  board[i][j] = player;
}

function choiceValidity(i, j){
  return board[i][j]==0;
}

function checkWin(){
  for(var i=0; i<3; i++)
  {
    let set = new Set(board[i]);
    if (set.size==1 && Array.from(set)[0]!=0){
      return true;
    }
    var column = [];
    for(var j=0; j<3; j++){
      column.push(board[j][i]);
    }
    let newSet = new Set(column);
    if (newSet.size==1 && Array.from(newSet)[0]!=0){
      return true;
    }
  }
  if (board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[2][2]!=0){
    return true;
  }
  if (board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[2][0]!=0){
    return true;
  }
  return false;
}
