<template>
    <div> this is ultrasound </div>
    <button @click="gotohome" > Home </button>
</template>

<script>
export default {
    name:"ultrasoundComp",
    methods : {
        gotohome () {
            this.$emit("home")
        }
    }
}
</script>

<style>

</style>