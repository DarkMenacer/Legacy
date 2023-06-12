import express from "express";
import { Dog } from "../entities/Dog";
import { Connect } from "../datasource";
const router = express.Router();

const data = [
    { dog_name: "Elsu", age: 6, is_bhondu: false },
    { dog_name: "Anna", age: 6, is_bhondu: true },
    { dog_name: "Pluto", age: 3, is_bhondu: true },
]

router.get('/api/dog', async (req, res) => {
    const dogs = await Dog.find({
        select: {dog_name: true, age: true},
        //where: {dog_name:'Elsu'}
    });
    //Other find methods like findBy(), findOne(), also exist
    return res.json(dogs);
})

router.post('/api/dog', async (req, res) => {
    const {dogName, age, bhondu_ka } = req.body;
    const dog = Dog.create({
        dog_name: dogName,
        age,
        is_bhondu: bhondu_ka
    });
    await dog.save();
    return res.json(dog);

})

router.delete('/api/dog/:dogName', async (req, res) => {
    const {dogName} = req.params;
    const response = await Dog.delete(dogName);
    res.json(response);
})

router.get('/api/dog/initialise', async (req, res) => {
    await Connect.createQueryBuilder().delete().from(Dog).execute()
    await Connect.createQueryBuilder().insert().into(Dog).values(data).execute()
    .then(()=>console.log('Data Added successfully')); 
    return res.json("Data initialised successfully");
})

router.get('api/dog/:dogName', async (req, res) => {
    const dog = Connect.createQueryBuilder()
    .select('dog_name').addSelect('age').from(Dog, 'dog_table')
    .where('age >= :minAge',{minAge: 5});
    return res.json(dog);
})


export {router as dogRouter}