interface Human {
    name: string;
    age: number;
    gender: string;
}

const person = {
    name: "jodnddus",
    age: 18,
    gender: "male"
}

const sayHi = (person: Human): string => {
    return `Helloooooooooooooo ${person.name}, you are ${person.age}, you are a ${person.gender}`;
}

console.log(sayHi(person));

export{};