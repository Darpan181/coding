let gameNum = 5;
let userNum = prompt("Guess the Game number:");
while(userNum != gameNum){
    userNum = prompt("Try again:");
}
console.log("Congratulations! you guessed it right...")