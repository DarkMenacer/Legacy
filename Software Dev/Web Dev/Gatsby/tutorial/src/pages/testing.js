import React from "react";
import { graphql, useStaticQuery} from "gatsby";
import { GatsbyImage, getImage } from "gatsby-plugin-image";

const query = graphql`
  {
    allContentfulFriend {
      nodes {
        name
        age
        photo {
          gatsbyImageData(placeholder: BLURRED, layout: FULL_WIDTH)
        }
      }
    }
  }
`


const Testing = () => {

    const result = useStaticQuery(query)
    const temp = result.allContentfulFriend.nodes

	return (
    	<>
        {temp.map((friend, index) => {
            let g_image = getImage(friend.photo)
            return <>
                <p key={index}>{friend.name} and {friend.age}</p>
                <GatsbyImage image={g_image}/>
            </>
        })}
        </>
    );
}



export default Testing;