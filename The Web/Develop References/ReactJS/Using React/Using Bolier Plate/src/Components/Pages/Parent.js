import React from "react";
import { Link, Outlet } from "react-router-dom";

const Parent = () => {

    const hStyle = {
        color: "Maroon",
        textAlign: "center"
    }

    return (
        <>
            <h1 style = {hStyle}>React Tutorial</h1>
            This is the shared layout among all pages
            <nav style={{margin:'10px 0px', backgroundColor:'pink'}}>
                <Link to='/home'>Home</Link>
                <Link to='dashboard' style={{margin:'10px'}}>Dashboard</Link>
            </nav>
            <hr/>
            <Outlet/>
        </>
    );
}
export default Parent;