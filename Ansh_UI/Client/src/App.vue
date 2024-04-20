<template>
  <div v-if="choose" id="master-container">
    <div id="main-container">


      <div id="vision-wrapper">
        <div  id="Vision" @mouseenter="startanimevision" @mouseleave="hover1 =false"  @click="choosevision">
          <div id="camera" >
            <img  src="./assets/camera-image.webp" height="75px" width="75px">
          </div>
          <div id="vision-anime">
            <svg   width="490" height="260" viewBox="0 0 490 260" fill="none" xmlns="http://www.w3.org/2000/svg">
              <path :d="imgsize" stroke-width="5px"  stroke="#e8e4c8"></path>
             </svg>
          </div>
          <div id="track-vision">
            <img  src="./assets/13-new.jpg" height="150px" width="500px">
          </div>
        </div>
      </div>


      <div id="ultrasound-wrapper">
        <div  id="UltraSound"  @mouseenter="startanimeult" @mouseleave="hover2 =false"  @click="chooseultrasound">
          <div id="wheel" >
            <img  id="wheelrotate"  src="./assets/wheel.png" height="`160px" width="200px">
          </div>
          <svg id="wave" width="400" height=" 0">
            <circle cx="100" cy="100" r="50" stroke="black" stroke-width="10" fill="none" />
          </svg>
          
          <div id="track-ult">
            <img  src="./assets/13-new.jpg" height="550px" width="500px">
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
      enableVision:0,
      hover1 : false,
      hover2 : false,
      imgsize :"",
      imgsize1 : "M 250 0  H 240  L ",
      height : 0 ,
      diff : 0,
      imgsize2 : "L 250 0  Z",
      angle : 0,

    }
  },
  methods: {
     startanimevision () {
      this.hover1 = true;
      this.height = 0
       this.startlight();
     },
     startanimeult () {
      this.hover2 = true;
      this.startwave();
     },
     startlight() {
    const interval = setInterval(() => {
        this.height += 5;
        this.diff = 260 * this.height;
        this.diff = this.diff / 240;
        var left = 240 - this.diff;
        var right = 250 + this.diff;
        this.imgsize = this.imgsize1 + ' ' + left + ' ' + this.height + " H " + right + ' ' + this.imgsize2;
        console.log(this.imgsize);
        
        if (this.hover1 == false || this.height > 180) {
            clearInterval(interval); 
        }
    }, 1);
},
  startwave () {
    const interval = setInterval(() => {
      console.log(this.angle)
        this.angle = (this.angle + 5) %360
        const element = document.getElementById("wheelrotate")
        element.style.transform = "rotate(" + this.angle + "deg)"
        
        
        if (this.hover2 == false ) {
            this.imgsize  = "";
            clearInterval(interval); 
        }
    }, 1);
  }
,
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
  grid-template-columns: repeat(20,1fr);
  grid-template-rows: repeat(20,1fr);
  align-items : center;
  justify-items : center;
}



#camera {
  grid-area: 2 / 9 / 4 / 13;
}

#vision-anime {
  grid-area: 4 / 2 / 17 / 20;
  z-index : 1;
}

#track-vision {
  grid-area: 10 / 2 / 20 / 20;
}

#wheel {
  grid-area: 4 / 5 / 13 / 17;
}

#wave {
    grid-area : 10 / 1 / 13 / 20;
}

#track-ult {
grid-area: 18 / 2 / 20 / 20;
}



</style>