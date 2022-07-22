const reactContentroot = document.getElementById("root");

/* ReactDOM.render("Hello world",reactContentroot); */

/* const element_using_React= React.createElement("ul",null,[
    React.createElement("li",null,"This is not written in HTML format"),
    React.createElement("li",null,"unlike what the page source code says"),
]);

ReactDOM.render(element_using_React,reactContentroot); */

const Compo = () => {
    const placeholder = "Even placeholders are possible!";
    return (
        <ul>
            <li>Now same thing but written in JSX</li>
            <li>still unlike what the page source code says</li>
            <li>{placeholder}</li>
        </ul>
    );
}

ReactDOM.render(<Compo />, reactContentroot);