<template>

    <button @click="gotohome" > Home </button>
<GetImages></GetImages>



</template>

<script>

//import UploadComp from  "./UploadVideo.vue"
import GetImages from './GetImages.vue';
//import { response } from 'express';

export default {
    name:"visionComp",
    components : {
        GetImages,
    },
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
    }
}
</script>

<style>

</style>