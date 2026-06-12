// let i=1;
// let j=1;
// for(i=1;i<=5;i++){
//     var pattern="";
//     for(j=1;j<=i;j++){
//         pattern=pattern + " *";
//     }
//     console.log(pattern);
// }

// const isReverse= (str) =>{
//     let reverse="";
//     for(let char=str.length-1; char>=0; char--){  
//         reverse=reverse+str[char];
//     }
//     console.log(reverse);
// };
// isReverse("Darpan Pawar");

const isPalindrome= (str) =>{
    let reverse="";
    for(let char=str.length-1; char>=0; char--){
        reverse=reverse+ str[char];
    }
    if(reverse==str){
        console.log("YES");
    }
    else{
        console.log("NO");
    }
};
isPalindrome("DAD");