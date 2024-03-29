<template>
    <div> this is vision </div>
    <button @click="gotohome" > Home </button>

    <button @click="uploadData">Upload</button>
    <button @click="getData">GETDATA</button>
</template>

<script>
import axios from 'axios';
//import { response } from 'express';

export default {
    name:"visionComp",
    data () {
        return {
            i:0,
        }
    },
    methods : {
        gotohome () {
            this.$emit("home")
        },

        // async uploadData () {
        //     let result = await axios.post('localhost:3000');
        //     console.log(result);
        // }
        
        // getting data form the mongodb
        async getData() {
            try {
                let temp = 'http://localhost:3000/images/' + this.i  ;
                console.log(temp)
                const response = await axios.get(temp);
                console.log(response.data); 
            } catch (error) {
                console.error('Error fetching data:', error);
            }
            this.i = (this.i + 1)%6
        }
    }
}
</script>

<style>

</style>