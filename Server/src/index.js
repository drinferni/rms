const express = require('express');
const cors = require('cors');
const app = express();
app.use(cors());
const PORT = 3001;

function connnectionstatus() {
    console.log("connected");
}

app.listen(PORT,connnectionstatus)


// app.post("/data",(request,response)=>{
//     response.send("images")
// })

// app.get("/data",(request,response)=> {
//     response.send("images")
// })