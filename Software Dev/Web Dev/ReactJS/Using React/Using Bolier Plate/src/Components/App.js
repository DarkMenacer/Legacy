import React from "react";
import { BrowserRouter, Routes, Route, Outlet } from "react-router-dom";
import HomeComponent from "./Pages/Home";
import Dashboard from "./Pages/Dashboard"
import NewPage from "./Pages/NewPage"
import Parent from "./Pages/Parent";

const App = () => {
    
    return (
        <BrowserRouter>
            <div>HEADER (stays constant) </div>
            <hr/>
            <Routes>
        {/*}    
                <Route path='home' element={<HomeComponent/>}> 
                    <Route path='child' element={<div> Cannot see this page at all</div>}/>
                </Route>
                <Route path='nextpage' element={<NewPage/>} />
                <Route path='*' element={<div><h1>Error!</h1>Change URL to /home</div>}/>

                WRONG WAY TO NEST PAGES
        */}

        {/*
                PAGE NESTED
                <Route path='dashboard' element={<div><h1>The Dashboard</h1><Outlet/></div>}>
                    <Route path='nestedPage' element={
                        <div>
                            <h1>Nested Page</h1>Done using Outlet, but even dashboard is shared
                        </div>}/>
                </Route>
                <Route path='*' element={<div><h1>Error!</h1>Change URL to /dashboard</div>}/>
                BUT NESTED PAGE VISIBLE EVERYWHERE
        */}

        
                <Route path='home' element={<Parent/>}>
                    <Route index element={<HomeComponent/>}/>
                    <Route path='nextpage' element={<NewPage/>} />
                    <Route path='dashboard' element={<Dashboard/>}/>
                </Route>
                <Route path='*' element={<div><h1>Error!</h1>Change URL to /home</div>}/>

            </Routes>
            <hr/>
            <div>FOOTER (stays constant) </div>
        </BrowserRouter>
    );
  }

  export default App;