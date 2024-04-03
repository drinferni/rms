<template>

<input type="file" id="folderUpload" @click="preprocessfolder">
<button v-if="datasending" @click="senddata">SEND DATA</button>




</template>

<script>

export default {
    name:"UploadComp",
    data() {
        return {
            datasending:1,
            processing:0,
            displayoutput:0,
            folderpath: "",
        }
    },
    methods :{
        async preprocessfolder () {
            document.getElementById('folderUpload').addEventListener('change', function(e) {
                this.folderpath = this.value
                console.log(this.folderpath)
                console.log(e.target.files[0])
            })               
        },
        async senddata () {
            // code to send data to the cloud
            // send sendsignal;
            this.datasend=0;
            this.processing=1;
            this.displayoutput=0;
        } ,
        async processingdata () {
            var signal = 0;
            while (signal == 0) {
            // check the processing signal
            }
            if (signal == 1 ) {
                this.processing=0;
                this.displayoutput=1;
            }
        }
    }
}

</script>