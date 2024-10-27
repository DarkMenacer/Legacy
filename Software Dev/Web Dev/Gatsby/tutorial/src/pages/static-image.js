import React from "react";
import Layout from "../layout/Layout";
import { StaticImage } from "gatsby-plugin-image";
import { navigate } from "gatsby";
import '../styles/global.css'
import SEO from "../components/SEO";

const Gatsby_Images = () => {

	return (
    	<Layout>
            <SEO title={'Park'}/>
            <div className="centering background_set">
                <h2>Welcome to park</h2>
                <StaticImage src='../Assets/Not-Elsu.jpg' placeholder="blurred" width='15rem' as="div"/>
                <span className="small-text-2">Even though image is 700kb originally, gatsby reduces the size as width is reduced</span>
                <h4>You see a German dog but this is not Elsa</h4>
                <h4> Let's visit Elsu for learning Gatsby</h4>
                <button onClick={(e)=>{e.preventDefault();navigate('/away/work')}}>Click to go</button>
            </div>
        </Layout>
    );
}

export default Gatsby_Images;