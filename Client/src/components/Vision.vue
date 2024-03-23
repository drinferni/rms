<template>
    <div> this is vision </div>
    <button @click="gotohome" > Home </button>

    <button @click="uploadData">Upload</button>
</template>

<script>
import axios from 'axios';

export default {
    name:"visionComp",
    methods : {
        gotohome () {
            this.$emit("home")
        },

        async uploadData () {
            let result = await axios.post("http://localhost:3001/data", {image_id: 1001, image:"231"} )
            console.log(result);
        }
    }
}
</script>

<style>

</style>