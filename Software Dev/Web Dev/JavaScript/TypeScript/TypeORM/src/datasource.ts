import { DataSource } from "typeorm";
import { Dog } from "./entities/Dog";
import { Home } from "./entities/Home";

export const Connect = new DataSource({
    type: 'postgres',
    host: 'Pranavs-MacBook-Pro.local',
    port: 5432,
    database: 'learningtypeorm',
    username: 'pranavchatur',
    password: 'psql',
    entities: [Dog, Home],
    synchronize: true
})

Connect.initialize()
    .then(()=>{console.log('Connected to database successfully')})
    .catch((err) => {console.error("Error during Data Source initialization", err)})
