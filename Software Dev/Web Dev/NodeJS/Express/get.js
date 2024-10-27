const express = require('express')
const app = express()
const {pizza, noodles} = require('../Modules/data/food')

app.get('/', (req,res)=> {
    res.write('Go to /menu to check how the data can be served to frontend and /food? for query params')
    res.send()
})

//How to send data to frontend
app.get('/menu', (req,res)=> {
    res.json({pizza,noodles})
})

//Query Parameters
app.get('/food', (req, res) => {
    const {recipe} = req.query
    if(recipe === 'pizza'){res.json(pizza)}
    else if(recipe === 'noodles'){res.json(noodles)}
    else{
        res.write('Please search for a specific recipe (pizza or noodles) using ?recipe= or go to /menu')
        res.send()
    }
})

//Route Parameters can be used to serve individual products in an array of products one by one as per need
// '/products/:productID' and then const { productID } = req.params

app.listen(5005, ()=>{
    console.log('server listening on port 5005...')
})