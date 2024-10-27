import { Column, Entity, JoinColumn, JoinTable, ManyToMany, ManyToOne, PrimaryGeneratedColumn } from "typeorm";
import { Dog } from "./Dog";

enum Houses {
    BUNGALOW = 'BUNGALOW',
    ROW_HOUSE = 'ROW_HOUSE',
    FLAT = 'FLAT'
}

@Entity('home') export class Home {
    @PrimaryGeneratedColumn({type:'int'}) house_no: number;

    @Column({type: 'enum', enum: Houses}) style: Houses;

    @Column({type: 'text', unique: true}) address: string;

    @ManyToOne(() => Dog, (dog) => dog.homes) 
    @JoinColumn({name:'dog'}) dog: Dog;     //no seperate table needed

    @ManyToMany( () => Dog )        //need a seperate table for Many-to-Many
    @JoinTable({
        name: 'sharing_homes',
        joinColumn: {name: 'shared_home_no', referencedColumnName: 'house_no'},
        inverseJoinColumn: {name: 'dogs_sharing', referencedColumnName: 'dog_name'}
    })
    sharing_dogs: Dog[]
}