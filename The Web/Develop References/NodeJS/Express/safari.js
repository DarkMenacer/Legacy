const express = require('express')
const router = express.Router()

const GetFees = (req, res)=> {
    res.send("The fees is 100$")
}

const CheckAvailabilty = (req, res)=>{
    const got_it = Math.random() < 0.5? 1: 0;
    if(got_it){
        res.json({announce: "50% chance of tiger"})
    }
    else{
        res.json({announce: "10% chance of tiger"})
    }
}

router.route('/zone1').get(GetFees).post(CheckAvailabilty)

module.exports = router