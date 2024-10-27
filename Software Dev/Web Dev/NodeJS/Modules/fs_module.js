//Synchronous way of dealing with file system
const {readFileSync, writeFileSync} = require('fs')

const a_file = readFileSync('./fake_folder/fake_file.txt','utf-8')
writeFileSync('./fake_folder/fake_file.txt', 
                `This will be overwritten ${a_file}, use flag to append`,
                {flag:'a'}
            )
//-----


//Async way of doing it
//Callback functions are used, just like callback function executed as soon as eventlistener button is clicked

const {readFile, writeFile} = require('fs')

readFile('./fake_folder/fake_file.txt','utf-8',(err, result)=>{
    if(err){console.log(err);return}
    const first = result


    readFile('./fake_folder/another_fake_file.txt','utf-8', (err, result)=>{
        if(err){console.log(err);return}
        const second = result
    
        writeFile('./fake_folder/another_fake_file.txt', `This will be overwritten ${a_file}, use flag to append`,
                    (err, result) => {
                        if(err){console.log(err);return}
                        console.log('Done with the task\n')
                })

        console.log(`Exiting from ${second} readFile\n`)        
    })


    console.log(`Exiting from ${first} readFile\n`)        
})

console.log('This is how to read/write asynchronously')
console.log('Do you notice the callback hell?')