//Note: You'll need browser for complete running of this code
const http = require('http')

const PORT_NUMBER = 5005
console.log(`Check browser port ${PORT_NUMBER} for more (http://localhost:${PORT_NUMBER}/)`)

const server = http.createServer((req, res)=>{
    res.write(`<p>Every time you reload a new request (req) is sent and a new response (res) is generate</p>`)
    console.log('the code wont stop until manually forced to quit as server keeps waiting for more requests')


    if(req.url==='/about'){
        res.write(`<h1> About Page </h1>`)
        res.end('Notice how request parameter is used in the code to reach here and this is not HTML')
    }

    
    res.end()
})
server.listen(PORT_NUMBER)


//Another way for above code is using event-driven approach
http.createServer().on('banana', (req, res)=>{
    console.log("same logic as before can be added here")
}).listen(5006)

