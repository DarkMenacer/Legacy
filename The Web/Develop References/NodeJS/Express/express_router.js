const express = require('express')
const app = express()
const safari_router = require('./safari.js')

app.use('/safari',safari_router)

app.listen(5005, ()=>{
    console.log('server listening on port 5005...')
})