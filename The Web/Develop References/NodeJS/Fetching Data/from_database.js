/*
This is how you connect with a database
PostgreSQL is used for this file
Notice the use of async-await. Check from_file.js to understand the motivation behind this approach
*/

const Pool = require("pg").Pool;
const pool = new Pool(
    {
        user: 'pranavchatur',
        password: 'psql',
        host: 'localhost',
        port: 5432,
        database: 'Tutorial' 
    }
)
// Prefer exporting pool and using it in other files rather than fetching all the data in one file only
module.exports = pool

const get_Data = async() => {   //notice the word 'async'
    try{

        //const result = pool.query("SELECT * FROM modules;") THIS DOESN'T DO THE INTENDED
        const result = await pool.query('SELECT * FROM modules;') //notice the word 'await'

        console.log(result); //prints all information about the table as well
        console.log(result.rows) //prints the all the data inside of the table
        console.log(result.rows[0].name) //prints the name attribute of first row of the fetched data
        console.log(result.fields) //prints the fields and the datatype
        //result.rowCount, result.command check pg documentation for more
    }
    catch(error){console.log(error)}
}

const set_Data = async(mod_name,tim_commit) => {
    try{
        await pool.query('INSERT INTO modules (name, how_big) VALUES ($1, $2)',[mod_name,tim_commit])
        console.log(`${mod_name} requires ${tim_commit} minutes to learn. Added to database`)
    }
    catch(error){console.log(error)}
}

// Similar functions can be created for updation and deletion as well



set_Data('path', 15)
set_Data('os', 20)
set_Data('fs', 60)
set_Data('http', 10000)
get_Data()
//Note: They may not run in order, because async-await has not been used