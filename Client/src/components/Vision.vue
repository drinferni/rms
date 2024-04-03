<template>

    <button @click="gotohome" > Home </button>
    <div v-if="home">
        <div> this is vision </div>
        <button @click="uploadData">Upload</button>
    </div>

    <UploadComp v-if="upload"></UploadComp>


</template>

<script>

import UploadComp from  "./UploadVideo.vue"
//import { response } from 'express';

export default {
    name:"visionComp",
    components : {
        UploadComp,
    },
    data () {
        return {
            i:0,
            home:1,
            upload:0,
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
         uploadData() {
            this.home = 0;
           this.upload=1;
        }

    }
}
</script>

<style>

</style>