const http = require('http')
const {readFileSync} = require('fs')

const server = http.createServer((req,res)=>{
    const url = req.url

    if(url === '/'){
        //just passing the html page from files rather than writing html code in res.write()
        const home_page = readFileSync('./Assets/index.html')
        res.writeHead(200, {'content-type' : 'text/html'})
        res.write(home_page)
        res.end()
        //just this won't work, also import styling.css for css and node_logo for image
        //need to manually import all files one by one for that 
    }

    else if(url==='/styling.css'){ //note: here the address is that what html file calls, not with reference to this file
        //importing css style
        const styling = readFileSync('./Assets/styling.css')
        res.writeHead(200, {'content-type' : 'text/css'})
        res.write(styling)
        res.end()
    }

    else if(url === '/node_logo.png'){ //note: here the address is that what html file calls, not with reference to this file
        //import the image
        const node_logo = readFileSync('./Assets/node_logo.png')
        res.writeHead(200, {'content-type' : 'image/png'})
        res.write(node_logo)
        res.end()
    }

    else{
        //error page
        res.writeHead(400,{'content-type' : 'text/html'})
        res.write('<h1>ERROR</h1>')
        res.end()
    }
}).listen(5005)

//As seen, we need to import all assets manually, just to load a single html page, 
//consider what will happen when there are 10 pages each having 5-6 logos and styles
//This is why Express is used