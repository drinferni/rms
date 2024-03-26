const express = require('express');
const cors = require('cors');

const inputrouter = require("./Routers/InputRouters");


const app = express();
app.use(cors());
const PORT = 3000;

app.use(express.json());
function connnectionstatus() {
    console.log("connected");
}

app.listen(PORT,connnectionstatus)

app.use ( inputrouter);

// app.post("/data",(request,response)=>{
//     response.send("images")
// })

app.get("/data",(request,response)=> {
    response.send({"images":10})
})

app.get("/data/10",(request,response)=> {
    response.send({"images":100})
})

app.post("/data",(request,response)=> {
    console.log(request.body);
    response.send(201);
})
console.log("all routers are ready")