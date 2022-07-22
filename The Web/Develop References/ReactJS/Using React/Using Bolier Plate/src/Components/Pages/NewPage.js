import React from "react";
import { useNavigate } from "react-router-dom";

const NewPage = () => {

    const navigate = useNavigate();
    const handleClick = () =>{
        navigate('/home');
    }


    return (
        <div>
            Notice the button "Go Back" instead of link
            <div>
            <button onClick={handleClick}>Go Back</button>
            </div>
            
        </div>
    );
}

export default NewPage