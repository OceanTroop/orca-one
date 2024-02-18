<template>
  <div class="row">
    <div class="twelve columns">
      <label>Device Name</label>
      <input class="u-full-width" v-model="settings.deviceName" />
    </div>
    <button class="button-primary" @click="save">Save</button>
    <div>{{ message }}</div>
  </div>
</template>

<script lang="ts">
import axios from 'axios';
import Settings from '../models/settings.ts';
import { Component, Vue, toNative } from 'vue-facing-decorator';

@Component({})
class HomeView extends Vue {
  settings: Settings = new Settings();
  message: String = "";

  mounted() {
    this.load();
  }

  async load(): Promise<void> {
    await axios.get("/settings")
      .then(r => {
        this.settings = r.data as Settings;
      });
  }

  async save(): Promise<void> {
    axios.post("/settings", this.settings).then(() => {
      this.message = "Settings saved! Please reboot device!";
    }).catch(() => {
      this.message = "ERROR while save settings!";
    });
  }
}

export default toNative(HomeView);
</script>

<style scoped></style>
