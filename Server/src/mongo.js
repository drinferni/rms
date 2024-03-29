const { MongoClient} = require("mongodb")

let interface


// making an object with the required functions to connect to the mongodb
mongo = {
    connectmondb : (cb) => {
        MongoClient.connect("mongodb://127.0.0.1:27017/rms")
        .then((client) => {
            interface = client.db();
            console.log("MongoDB connected successfully");
            return cb(1)
        })
        .catch((error) => {
            console.error("Connecting to the database unsuccessful:", error);
        }); 

       
    },
    getinterface : () => interface

    // get and post data
}

module.exports = mongo