<template>
  <div v-if="choose" id="master-container">
    <div id="main-container">
      <div id="vision-wrapper">
        <div  id="Vision">
            <div id="animation">
             <svg id="vision-anime"  width="484" height="202" viewBox="0 0 484 402" fill="none" xmlns="http://www.w3.org/2000/svg">
              <path d="M251 0.5H234.5L0 402H484L251 0.5Z" fill="#E7EC0B"/>
            </svg>


          </div>
          <div class="button-wrapper">
            <button class="button" @click="choosevision">VISION</button>
          </div>
        </div>
      </div>


      <div id="ultrasound-wrapper">
        <div  id="UltraSound">
          <div id="animation">

          </div>
          <div class="button-wrapper">
            <button class="button" @click="chooseultrasound">ULTRASOUND</button>
          </div>
        </div>
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
  grid-template-rows: repeat(1,1fr);
  grid-template-columns: repeat(2,1fr);
  align-content: space-evenly;
  align-items: stretch;
  justify-items: stretch;

}

#vision-wrapper {
  display : grid;
  grid-template-columns: 1fr;
  grid-template-rows: 9fr 1fr;
  align-items : center;
  justify-items : center;
}


#ultrasound-wrapper {
  display : grid;
  grid-template-columns: 1fr;
  grid-template-rows: 9fr 1fr;
  align-items : center;
  justify-items : center;
}


#Vision,#UltraSound {
  height : 400px;
  width : 500px;
  display : grid;
  grid-template-columns: 1fr;
  grid-template-rows: 1fr;
  align-items : center;
  justify-items : center;
  border : 5px;
  border-style: solid;


}

#vision-anime {
background: url("data:image/svg+xml,%3Csvg width='484' height='202' viewBox='0 0 484 402' fill='none' xmlns='http://www.w3.org/2000/svg'%3E%3Cpath d='M251 0.5H234.5L0 402H484L251 0.5Z' fill='%23E7EC0B'/%3E%3C/svg%3E%0A");
}

</style>