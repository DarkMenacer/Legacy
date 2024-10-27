import React from "react";
import { useStaticQuery, graphql } from "gatsby";

const getData = graphql `
        query {
            site {
            elsu:siteMetadata {
                house_no
                names
                office {
                    location
                    number
                }
            }
            }
        }`

const FetchData = () => {

    //const data = useStaticQuery(getData)
    const {site:{elsu:{house_no}}} = useStaticQuery(getData)

	return (
    	<span>
            {/*data.site.siteMetadata.names*/}
            {house_no}
        </span>
    );
}

export default FetchData;