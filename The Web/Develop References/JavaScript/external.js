var usage = prompt("Do you want an interactive website:");
var month = new Date().toLocaleString('default', {month: 'long'});

if(usage == "Yes"){
    var intr = document.getElementById("Interactive");
    intr.style.display = "block";
    var textbox = document.getElementById("Textbox");
    var button = document.getElementById("Btn");
    button.addEventListener("click", function(){
        if(textbox.value == month){alert("You win!");}
        else{alert("Try Again!");textbox.value = "";}
    });
}

var java_arr = new Array("Java way to define", 1 , "Array");
var pyth_arr = ["Python way to define", 11, "Array"];
document.write(java_arr + "<br/>");

function change_element(num, arr, elem){arr[num] = elem;}
change_element(7,pyth_arr,"Wow, accessing out of bound elements");
document.write(pyth_arr);

