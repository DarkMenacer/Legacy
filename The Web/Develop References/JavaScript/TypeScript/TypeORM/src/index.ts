import "./datasource.ts";
import express from "express";
import { dogRouter } from "./routes/route_dog.ts";

const app = express();

app.listen(8080, async() => {console.log('Server running on Port 8080');})
app.use(express.json())
app.use(dogRouter)
