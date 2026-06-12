const repeatedFunction = () =>{
    console.log("5 second m rukega");
};

const intervalID = setInterval(repeatedFunction , 1000);

setTimeout(() => {
    clearInterval(intervalID);
} , 5000);