const drinks = ['Jamun Shake', 'Cold Coffee']

const eatables = require('./data/food')
const GivePrice = require('./data/fxn')
//This is how you import functions and data from other js code, these are imported as modules

drinks.forEach(GivePrice);
GivePrice(eatables.pizza);
//and this is how you invoke them

/*There are 5 built-in modules in node covered here
    1. OS module
    2. Path module
    3. File System module
    4. Events module
    5. HTTP module
    
Each of the above is explored in a seperate js file in this directory itself
*/