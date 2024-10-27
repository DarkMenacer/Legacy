import { Link } from "gatsby";
import React from "react";
import "../styles/global.css";

const Footer = () => {

	return (
        <div className="head-foot" style={{padding:'0.8rem', margin:'0'}}>
            <h4 style={{margin:'0'}}>Tutorials with Dogby</h4>
            To get in touch with Elsudog, click <Link to='/contact'>here</Link>
        </div>
    );
}

export default Footer;