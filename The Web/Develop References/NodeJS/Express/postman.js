const express = require('express')
const app = express()

app.use(express.json()); 
//middleware that helps in using res.json()

const Get_man = (req, res) => {
    const {fruit, flower} = req.body
    console.log(fruit, flower)
    res.send('Got it!')
}

const Send_man = (req, res) => {
    const person = {
        name: "Tommy",
        fruit: "Apple",
    }
    res.status(201).json(person)
}

app.get('/one_way_data', Get_man)

app.post('/one_way_data', Send_man)

/* 
This is how the front-end communicates with app.post (using Fetch API, even axios can be used)
    fetch(`/send_data`, {
            method: "POST",
            headers: { "Content-Type": "application/json",},
            body: JSON.stringify({ key1: value1, key2: value2 }),
        }
    ).then((res) => {console.log(res);alert(res)}); 
*/

app.post('/receive_send_data', (req, res) => {
    const {key1, key2} = req.body //this is how data is taken from front-end
    console.log(key1, key2)
    res.json({message:"Yeah, got it man", sucess:true})
})

//There's also app.put() and app.delete() used to update and delete respectively 
//but same can be done by post as well

app.listen(5005, (req, res) => {
    console.log("Server listening on Port 5005");
})

//For simple HTML, refer the John Smilga video form example (https://youtu.be/TNV0_7QRDwY?t=24773)