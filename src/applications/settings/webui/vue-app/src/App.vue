<script lang="ts">
import { RouterLink, RouterView } from 'vue-router'
import { Component, Vue, toNative } from 'vue-facing-decorator';

@Component({ components: [RouterLink, RouterView] })
class App extends Vue {
}

export default toNative(App);
</script>

<template>
  <!-- <header> -->
  <!-- <img alt="Vue logo" class="logo" src="@/assets/logo.svg" width="125" height="125" /> -->

  <!-- <div class="wrapper"> -->
  <!-- <nav>
        <RouterLink to="/">Home</RouterLink>
      </nav> -->
  <!-- </div> -->
  <!-- </header> -->
  <div class="container">
    <div class="row">
      <div class="twelve columns"></div>
      <h1 class="title">Orca One</h1>
    </div>
    <RouterView />
  </div>
</template>

<style>
@import url('assets/normalize.css');
@import url('assets/skeleton.css');

/* body {
  background-color: black;
  color: greenyellow;
} */
</style>

<style scoped>
.title {
  margin-top: 20px;
}
</style>