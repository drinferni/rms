const express = require('express');
const connecttodb = require ( "./mongo")
const cors = require('cors');

const outputrouter = require("./Routers/OutputRouers");



// importing the express and setting the PORT
const app = express();
app.use(cors());
const PORT = 3000;

// connecting to the port
app.use(express.json());
function connnectionstatus() {
    console.log("connected to port");
}


 app.listen(PORT,connnectionstatus) 

// bringing the routers from of output router
app.use ( outputrouter);

//console.log(connecttodb);

let db

// connectong to the database
connecttodb.connectmondb((ready) => {
       if (ready == 1) db = connecttodb.getinterface();
})

console.log("all routers are ready")