console.log("This is how you write something to the console")

let usage = prompt("Do you want an interactive website:");
var month = new Date().toLocaleString('default', {month: 'long'});

if(usage == "Yes"){
    var intr = document.getElementById("Interactive");
    intr.style.display = "block";
    const textbox = document.getElementById("Textbox");
    const button = document.getElementById("Btn");
    button.addEventListener(
        "click", function(){
            if(textbox.value == month){alert("You win!");}
            else{alert("Try Again!");textbox.value = "";}
    });
}

var java_arr = new Array("Java way to define ", 1 , " Array", false);
var pyth_arr = ["Python way to define ", 2, " Array", true];
document.write(java_arr + "<br/>");

// another cooler way to define functions, 
const change_element = (num, arr, elem) => arr[num] = elem;
change_element(7,pyth_arr,"Wow, accessing out of bound elements");
document.write(pyth_arr);


const instruments = [
    {
        name: "Piano",
        family: "Keys",
        price: 100
    },
    {
        name: "Drumset",
        family: "Percussion",
        price: 40
    },
    {
        name: "Guitar",
        family: "Strings",
        price: 10
    }
]


//map function
const costs = instruments.map((x) => {return x.price;})
document.write("<br/><br/>The prices are " + costs)

const convert_name = (item) => {
    h_name = item.name.toUpperCase()
    return `<h4>${h_name}</h4>`
}
const big_name = instruments.map(convert_name)
document.write("<br/>"+"The bignames are " + big_name.join(''))


//filter function
const filter_func = instruments.filter((vadya) => {
    return vadya.price<50;
})
console.log("This is filter function(returns all occurence) ")
console.log(filter_func)


//find function
console.log("\nThis is find function(only return first occurence): ")
console.log(instruments.find((temp) => {return temp.price<50}))


//object destructing (same can be done with arrays)
const Piano = {
    owns: "Korg G1 Air",
    details:{
        color: "Black",
        price: 1.1
    }
}
const {owns: my, details:{color: bobby, price}} = Piano;
document.write("I own a " + my + " whose color is "+ bobby + " and price " + price + "L<br/><br/>");


//rest operator
const Pranav = "Pranav"
const letters = [...Pranav]
document.write(letters.join("--"))
const {owns, ...rest} = Piano
console.log("This is how rest operator works: " + owns + " " + rest.details.color)


//callback functions
const capitalize = (x) => {console.log(x.toUpperCase());}
const quietize = (x) => {console.log(x.toLowerCase());}
const string_formatter = (x,cb) => {cb(x);}
string_formatter("Pranav",capitalize);
string_formatter("Pranav",quietize);


//promises (to avoid callback hell) 
const password = 1;
const prom = new Promise((resolve, reject) => {
    const guess = Math.floor(Math.random()*2);
    console.log("Guess is "+guess)
    if(password === guess){
        resolve("Correct!, .then(cb) is used to access this")
    }
    else{
        reject("Wrong!, .catch(cb) is used to access this")
    }
})
console.log(prom)
prom.then((data)=>console.log(data)).catch((err)=>console.log(err))


//go to async-await.js now