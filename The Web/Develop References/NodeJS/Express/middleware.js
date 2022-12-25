const express = require('express')
const app = express()

const middle = (req, res, next) => {
    console.log("Simple function that gets executed for every route it is included in\n");
    next() //Absolutely have to pass to the next middleware, without this, browser won't load
}

app.get("/home", middle, (req, res)=>{
    res.send("HOME PAGE");
})

//can also be passed in app.use()
app.use(middle)

app.listen(5005, (req, res)=>{
    console.log("Server is listening on Port 5005");
})