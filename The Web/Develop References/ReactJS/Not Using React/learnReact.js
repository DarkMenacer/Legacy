let num = 0;
var btn = document.getElementById("inc_btn");
var ctr = document.getElementById("counter");

btn.addEventListener('click',()=> {
    num++;
    ctr.innerText = num;
});

/*  Just to add another button, source code doubled
    Bad scalability!
*/
let num1 = 0;
var btn1 = document.getElementById("inc_btn1");
var ctr1 = document.getElementById("counter1");

btn1.addEventListener('click',()=> {
    num1++;
    ctr1.innerText = num1;
});