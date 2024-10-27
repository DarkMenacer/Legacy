import React from "react";
import { useForm, ValidationError } from '@formspree/react';
import "../../styles/global.css"
import Layout from "../../layout/Layout";
import { Link } from "gatsby";
import SEO from "../../components/SEO";

const Contact = () => {
    const [state, handleSubmit] = useForm("mwkjpbav");
    if (state.succeeded) {
        return <p>Thanks for joining!</p>;
    }
    return (
        <Layout>
            <SEO title={'contact'}/>
            <form onSubmit={handleSubmit} className="centering background_set">
                <h2 style={{margin:'0 0 0.75rem'}}>Connect with Elsu dog</h2>
                <span className="small-text-2" style={{margin:'0 0 0.75rem'}}>Notice contact folder, and the name index.js</span>
                <div className="contact-card centering">
                    <div className="mail">
                        <label htmlFor="email">Your Email Address: </label>
                        <input id="email" type="email"  name="email"/>
                        <ValidationError  prefix="Email"  field="email" errors={state.errors}/>
                    </div>
                    <div className="mail">
                        <textarea id="message" name="message"/>
                        <ValidationError prefix="Message" field="message"errors={state.errors}/>

                    </div>
                    <button type="submit" disabled={state.submitting} className="bell">Submit</button>
                </div>
                <div className="friend-list">Back to <Link to='/elsuhome'>Elsu's home</Link></div>
            </form>
        </Layout>
    );
  }

export default Contact;