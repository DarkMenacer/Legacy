import React from "react";
import "../../Styles/Buttonstyle.css"
import CountButton from "../CountButton";
import { Link } from "react-router-dom";

const Home = () => {

    const placeholder = "This is a variable!";

    return (
        <div>
            <h2 style={{color: 'black'}}>Home Page</h2>
                <ul>
                    <li>{placeholder}</li>
                    <li><span>First Button</span><CountButton increment={1} /*signal={red}*/ /></li>
                    <li><span>Second Button</span><CountButton increment={3} /*signal={yellow}*//></li>
                    <li>Try going past 8 on above counters</li>
                </ul>
            <Link to="nextpage">New Page (not Dashboard)</Link>
            
        </div>
    );
}

export default Home;