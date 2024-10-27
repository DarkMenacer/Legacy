const give_price = (name) => {
    let price = 0
    //console.log(name)
    for(let i = 0; i < name.length;++i){
        price +=  name[i].charCodeAt();;
    }
    console.log(`The price of ${name} is ${price}`);
}

module.exports = give_price
//this is how you export functions; as modules