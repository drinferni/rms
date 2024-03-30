<template>

<div>{{ImageID}}</div>
<button @click="getData">NEXT</button>

</template>

<script>
import axios from 'axios';
export default {
    name:"GetComp",
    data() {
        return {
            i:0,
            ImageID:NaN,
            scr:""
        }
    },
    beforeMount() {
       this.getData()
    },
    methods :{
        async getData() {
            try {
                let temp = 'http://localhost:3000/images/' + this.i  ;
                console.log(temp)
                const response = await axios.get(temp);
                console.log(response.data); 
                this.ImageID = response.data[0].imageID
                this.src = response.data[0].url
            } catch (error) {
                console.error('Error fetching data:', error);
            }
            this.i = (this.i + 1)%6
        },
    }
}

</script>