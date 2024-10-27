import React from "react";
import { Link } from "gatsby";
import Bell from "../components/ElsuHomeBell";
import Layout from "../layout/Layout"
import FetchData from "../data/FetchData";
import '../styles/global.css'
import SEO from "../components/SEO";

const ElsuHome = () => {

	return (
        <Layout>
            <SEO title={'Elsuhome'}/>
            <div className="centering background_set">
                <div className="centering">
                    <h1 style={{margin:'0'}}>Elsu's Home: Row House no. <FetchData/> </h1>
                    <span className="small-text-2">The '7' is fetched from gatsby.config, not hard-coded</span>
                </div>
                <h3>Shhh! Dogboy is sleeping</h3>
                <Bell/>
                <h3 style={{margin:'1rem 0 1rem'}}>Oh no! you woke dogboy up</h3>
                <h4 style={{margin:'0'}}>But if you realise, Elsu has taught you Gatsby with this exercise</h4>
                <h4 style={{margin:'0.5rem 0 1rem'}}>Such a great teacher!</h4>

                <div>
                    <span>Go </span> 
                    <Link to='/' className="big-ft">here</Link> for a brief summary of Gatby made by Elsudog himself
                </div>
            </div>
        </Layout>
    );
}

export default ElsuHome;