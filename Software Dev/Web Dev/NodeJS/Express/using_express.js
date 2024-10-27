const express = require('express')
const app = express()

//This line automatically imports all the files in the specified folder
//This is the beauty of express
app.use(express.static('./Assets'))

app.all('*',(req,res)=>{
    //error page
    res.status(404).send('<h1>ERROR</h1>')
})

app.listen(5005, ()=> {
    console.log("server listening on port 5005...")
})

//both understanding_need.js and using_express.js provide the same output functionally