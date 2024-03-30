<template>

    <button @click="gotohome" > Home </button>
    <div v-if="home">
        <div> this is vision </div>
        <button @click="uploadData">Upload</button>
        <button @click="getData">GETDATA</button>
    </div>

    <UploadComp v-if="upload"></UploadComp>
    <GetComp v-if="getdata"></GetComp>


</template>

<script>

import UploadComp from  "./UploadImages.vue"
import GetComp from "./GetImages.vue"
//import { response } from 'express';

export default {
    name:"visionComp",
    components : {
        UploadComp,
        GetComp,
    },
    data () {
        return {
            i:0,
            home:1,
            upload:0,
            getdata:0
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
           this.home = 0;
           this.upload=0;
           this.getdata=1;
        },

        async uploadData() {
            this.home = 0;
           this.upload=1;
           this.getdata=0;
        }

    }
}
</script>

<style>

</style>