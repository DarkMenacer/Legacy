import * as React from "react"
import {Link} from "gatsby"
import SEO from "../components/SEO"

export default function Home() {
  return (
  <div>
    <SEO title={'tutorial'}/>
    <h1 style={{textAlign:'center'}}>Home page</h1>
    In this tutorial, we learn Gatsby with Elsu dog
    <h3>Gatsby is cool (like Elsu dog) </h3>
    <ol>

    <li> Notice, no react-router is needed, Gatsby handles routing itself!
        <b> So independent! Like Elsu dog </b>
    </li>
    <br/>
    <li> Gatsby handles slow loading images beautifully!
        <b> Just like Elsu the German Shepherd handles bhondu sheep</b>
    </li>
    <br/>
    <li> Gatsby uses GraphQL for receiving data!
        <b> Just like Elsu requests for a sausage every night</b>
    </li>
    <br/>
    <li>Gatsby has a sandbox for writing and testing GraphQL queries! 
        <b> Just like Elsu making life comfortable by being obedient</b>
    </li>

    <br/>
    <li>Gatsby can connect with a CMS and decouples data from website!
        <b> Just like Elsu splits all balls into 2 halves</b>
    </li>

    <br/>
    <li>Gatsby can create pages from templates!
        <b> Just like Elsu can identify snacks from smell itself</b>
    </li>

    </ol>

    <div>Let's <Link to='/static-image'>start</Link> this journey</div>
    
  </div>
  )
}
