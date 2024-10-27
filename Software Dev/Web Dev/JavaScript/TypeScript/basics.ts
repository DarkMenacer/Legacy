console.log("Welcome to TypeScript");
// to run this file, use command `npx tsc basics.ts` and notice how basics.js is created/updated automatically'

//Type Safety in TypeScript

let name : string = "Pranav";
// name = 7; //This gives an error

//Specifying type isn't always necessary, it can also be inferred

let age = 21; //equivalent to let age: number = 21;
// age = "This again gives an error"

//Having multi-types
let contact: number | string;
contact = 123456789;
contact = 'p@c.com';
// contact = false; //This gives an error

let bobby: any; //bobby can be any data type now

const capitaliser = (x: boolean, y: string): string  => {
	if(x == true){return y.toUpperCase();}
	else{return y.toLowerCase();}
}

console.log(capitaliser(true, "timmy"));

//custom types
type Person =  {
	readonly name: string; //can only be read, not changed after initialisation
	age: number;
	studying: boolean;
	student_id?: number //signifies that it is optional
}

const createStudent = (p_name: string, p_age: number): Person => {
	let stud: Person =  {name: p_name, age:p_age, studying: true};
	return stud;
}

//arrays
const residents : Person[] = []
residents.push(createStudent("Pranav", 21));

//enum
enum SeatChoice { AISLE, MIDDLE, WINDOW } //all variables declared SeatChoice only has 3 choices, and first is set to 0
enum Status  {RUNNING = 5, FAILED = -1, COMPLETED = 10, CANCELLED="Task Cancelled"} //Here the key-value pairs are user-defined, not serial starting from 0

//tuple   
let TuplePerson: [string, number,  boolean]
TuplePerson = ["Timmy", 3, false]
// TuplePerson = [false, 3, "Timy"] //Gives an error as order matters in Tuple

//TypeScript also supports classes and interfaces like Java, refer docs for more

export {}
