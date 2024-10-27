import React from "react";
import { Link } from "gatsby";
import Bell from "../../components/ElsuHomeBell";
import Layout from "../../layout/Layout";
import { graphql } from "gatsby";
import '../../styles/global.css';
import slugify from 'slugify';
import SEO from "../../components/SEO";

const ElsuHome = ({data}) => {

	return (
        <Layout>
            <SEO title={'Garage'}/>
            <div className="centering background_set">
                <h1 style={{margin:'0'}}>Elsu's Garage</h1>
                <h3>Now you are at Elsu's garage</h3>
                <br/>
                <Bell/>
                <br/>
                <div style={{margin:'0.5rem', textAlign:'center'}}>
                    <b>Elsu isn't here :-( </b> 
                    <br/>
                    <b> Try calling Elsu's friends:</b>


                    <div className="friend-list centering"> 
                    {
                    data.allContentfulFriend.nodes.map((friend, index)=>{
                        const slug = slugify(friend.name, {lower:true});
                        return <div key={index} className="friend-name">
                            <Link to = {'/'+slug}  className="big-ft" >{friend.name}</Link> 
                        </div>
                    })
                    }</div>

                    <div className="small-text-2">These names are fetched from Contentful, not hard-coded</div>

                    Everyone feels Dog must be at <Link to='/elsuhome'>home</Link> 
                </div>
                <p style={{margin:'0rem'}}>Except Timmy, he is too small to know how to pick up a phone</p>
            </div>
        </Layout>
    );
}

export const Office_mates = graphql `
    query {
        allContentfulFriend(sort: {name: ASC}) {
          nodes {
            name
          }
        }
      }
    `

export default ElsuHome;