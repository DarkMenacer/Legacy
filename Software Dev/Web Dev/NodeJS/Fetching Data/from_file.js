//NOTE: FOR BIG FILES, USE DIFFERENT APPROACH ({createReadStream} = fs, google it for more details, not covered here)

const {readFile} = require('fs')

const getText = (path) => {
    return new Promise((resolve,reject) => {
        readFile(path,'utf-8', (err, data)=>{
            if(err){reject(err)}
            else{resolve(data)}
        })
    })
}

getText('Fetching\ Data/one.txt').then((result_one)=> {
                    getText('Fetching\ Data/two.txt').then((result_two)=>{
                        //console.log(`file data: ${result_one} ${result_two}`)
                        //other operations
                    }).catch((err)=>console.log(err))
                }
            ).catch((err)=>console.log(err));
//Notice how bad this approach is, following approach of async-await is much better

const get_data = async() =>{
    // always wrap in try-catch block
    try{
        const result_one = await getText('Fetching\ Data/one.txt')
        const result_two = await getText('Fetching\ Data/two.txt')
        console.log(`file data: ${result_one} ${result_two}`)
        //SAME OUTPUT AS BEFORE AND CODE IS MUCH CLEANER
    }
    catch(error){console.log(error)}
}
//Still the getText function looks bad, doesn't it, following approach even resolves that


{const { readFile } = require('fs').promises} //Notice the .promises after require
const get_data_promises = async () => {
    try {
        const result_one = await readFile('Fetching\ Data/one.txt', 'utf8')
        const result_two = await readFile('Fetching\ Data/two.txt', 'utf8')
        console.log(`file data: ${result_one} ${result_two}`)
        //SAME OUTPUT AS BEFORE AND CODE IS MUCH CLEANER BUT DOESN'T NEED getText()
    } catch (error) {console.log(error)}
}

//All said and done, still prefer get_data() over get_data_promises because this method is also extendable over databases
//They are more-or-less same after all anyways
get_data()
