<template>
  <div v-if="choose" id="master-container">
    <div id="main-container">
      <div id="vision-wrapper">
        <div @click="choosevision" id="Vision">VISION</div>
      </div>
      <div id="ultrasound-wrapper"> j
        <div  @click="chooseultrasound" id="UltraSound">ULTRASOUND</div>
      </div>
    </div>
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

need to add a new text font . add colour and make it good till end of week
<style scoped>

#master-container {
  display: grid;
  height: 100vh;
  width : 100vw;
  grid-template-rows: 1fr ;
  grid-template-columns: 1fr;
  align-items: center;
  align-content: center;
}


#main-container {
  height : 75vh;
  width : 95%;
  display:grid;
  grid-template-rows: repeat(3,1fr);
  grid-template-columns: repeat(5,1fr);
  align-content: space-evenly;
  align-items: stretch;
  justify-items: stretch;

}

#vision-wrapper {
  display : grid;
  grid-template-columns: 1fr;
  grid-template-rows: 1fr;
  align-items : center;
  justify-items : center;
}


#ultrasound-wrapper {
  display : grid;
  grid-template-columns: 1fr;
  grid-template-rows: 1fr;
  align-items : center;
  justify-items : center;
}


#Vision,#UltraSound {
  height : 150px;
  width : 250px;
  display : grid;
  grid-template-columns: 1fr;
  grid-template-rows: 1fr;
  align-items : center;
  justify-items : center;
  border : 5px;
  border-style: solid;


}


</style>