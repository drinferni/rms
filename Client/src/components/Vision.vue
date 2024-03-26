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
            i:10,
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

        async getData() {
            try {
                const response = await axios.get('http://localhost:3000/data/'+ this.i);
                console.log(response.data); // Assuming you want to log the response data
            } catch (error) {
                console.error('Error fetching data:', error);
            }
        }
    }
}
</script>

<style>

</style>