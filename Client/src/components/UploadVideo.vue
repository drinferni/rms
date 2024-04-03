<template>

<input v-if="datasending" type="file" @change="onFileChange" multiple="multiple">

<div v-if="processing">
    processing
    <button @click="processingdata">SKIP</button>
</div>

<GetComp v-if="displayoutput"></GetComp>

</template>

<script>
import axios from 'axios';

import GetComp from "./GetImages.vue"

export default {
    name:"UploadComp",
    components : {
        GetComp,
    },
    data() {
        return {
            datasending:1,
            processing:0,
            displayoutput:0,
            folderpath: "",
        }
    },
    methods :{

    onFileChange(event) {
    console.log(event.target.files)
      const file = event.target.files;
      for ( let i =0;i<file.length ;++i) {
        const input = file[i];
        this.uploadFile(input);
      }
      this.uploadFile(file);
    },
    uploadFile(file) {
      const formData = new FormData();
      formData.append('folder', file);

      axios.post('http://localhost:3000/upload', formData)
    
      this.datasending = 0;
      this.processing = 1;

     },
      async processingdata () {
            var signal = 1;
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