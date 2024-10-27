import React, {useState, useEffect} from "react";
import '../Styles/Buttonstyle.css'

const CountButton = (props /* other way as well, use {} */) => {
    /* let counter = 0;
    return <div>
        <div>{counter}</div>
        <button onClick={++counter}>+1</button>
    </div> */
    // DOESN'T WORK, NEED A REACT HOOK called useState

    const [Counter, setCounter] = useState(0);

    const handleClick = () => {
        /* console.log("Clicked"); */
        setCounter(Counter+props.increment);
    }


    useEffect(()=>{
        console.log("Button " + props.increment + " Effect");
    },[Counter, props.increment]);

    useEffect(()=>{
        if(Counter > 8){
            setCounter(0);
        }
    },[Counter, props.increment]);


    return <span>
        <span>  value : {Counter}  </span>
        <button onClick={handleClick}>+{props.increment}</button>
    </span>

}

export default CountButton;