<template>
    <div v-if="choose">
      <button @click="choosevision" id="Vision">VISION</button>
      <button @click="chooseultrasound" id="UltaSound">ULTRASOUND</button>
    </div>
 <visionComp @home="choosechoose" v-if="enableVision"></visionComp>
 <ultrasoundComp @home="choosechoose" v-if="enableUltrasound"></ultrasoundComp>
</template>

<script>
import visionComp from './components/Vision.vue'
import ultrasoundComp from './components/ultrasound.vue'

export default {
  name:"app",
   components : {
       visionComp,
        ultrasoundComp,
   },
  data () {
    return {
      choose:1,
      enableUltrasound:0,
      enableVision:0

    }
  },
  methods : {

    choosevision () {
      this.choose=0
      this.enableVision=1
    },

    chooseultrasound (){
      this.choose=0
      this.enableUltrasound=1
    },

    choosechoose () {
        this.choose=1
        this.enableVision=0
        this.enableUltrasound=0
    },

  },
}

</script>

<style>

</style>