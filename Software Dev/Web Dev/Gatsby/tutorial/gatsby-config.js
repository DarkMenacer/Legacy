/**
 * Configure your Gatsby site with this file.
 *
 * See: https://www.gatsbyjs.com/docs/reference/config-files/gatsby-config/
 */

/**
 * @type {import('gatsby').GatsbyConfig}
 */
const path = require('path')
// resolve("dotenv").config({
//     path: path.resolve(`.env.${process.env.NODE_ENV}`)
// })

require('dotenv').config({ path: path.resolve(`.env.${process.env.NODE_ENV}`) })

module.exports = {

    siteMetadata:{
        names:['Timmy', 'Pluto', 'Anna'],
        house_no: 7,
        office: {
            number: 12,
            location: 'Garage'
        },
    },


    plugins: [
        {
            resolve: `gatsby-source-contentful`,
            options: {
              spaceId: `v2xhe9twwjfq`,
              // Learn about environment variables: https://gatsby.dev/env-vars
              accessToken: process.env.CONTENTFUL_API_KEY,
            },
          },
        `gatsby-plugin-image`,
        `gatsby-plugin-sharp`,
        `gatsby-transformer-sharp`,
        `gatsby-plugin-react-helmet`,
    ],
}
