import { Link } from "gatsby";
import React from "react";
import Layout from "../layout/Layout";
import { graphql } from "gatsby";
import {GatsbyImage, getImage} from "gatsby-plugin-image";
import SEO from "../components/SEO";

const FriendTemplate = ({data}) => {
    const {name, age, info, photo} = data.contentfulFriend;
    const image = getImage(photo)
	return (
    	<Layout>
            <SEO title={name}/>
            <div className="centering background_set">
                <div className="centering contact-card">
                    <div className="small-text-2">These pages are created using a template, not physically</div>
                    <h1 style={{marginTop:'0.1rem'}}>Dialing {name}</h1>
                    <GatsbyImage image={image} alt={`${name}'s photo`}/>
                    <h3 style={{margin:'0.5rem'}}>Age: {age}</h3>
                    <h4 style={{textTransform: 'capitalize', margin:'0.25rem'}}>Likes: {info.likes}</h4>
                    <h5 style={{margin:'0.5rem'}}> Back to the <Link to='/away/work'>Garage</Link> </h5>
                    <div className="small-text-2">There is another actual way to create Pages, Gatsby Node, Not covered here</div>
                </div>
            </div>
        </Layout>
    );
}

export const query = graphql`
  query ($name: String) {
    contentfulFriend(name: {eq: $name}) {
      name
      age
      info {
        likes
        languages
      }
      photo {
        gatsbyImageData(
          placeholder: BLURRED
          width: 300
          layout: CONSTRAINED
          cornerRadius: 200
          backgroundColor: "gainsboro"
        )
      }
    }
  }
`

export default FriendTemplate;