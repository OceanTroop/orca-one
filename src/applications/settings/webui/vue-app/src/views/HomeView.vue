<template>
  <div class="row">
    <h4 class="title">General</h4>
    <div class="twelve columns">
      <label for="deviceName">Device Name</label>
      <input id="deviceName" class="u-full-width" type="text" v-model="settings.deviceName" minlength="1" />
    </div>
  </div>

  <div class="row">
    <h4 class="title">Wi-Fi Settings</h4>
    <div class="twelve columns">
      <label for="wifiSSID">SSID (Wi-Fi Name)</label>
      <input id="wifiSSID" class="u-full-width" type="text" v-model="settings.wifiSSID" minlength="1" />
    </div>
    <div class="twelve columns">
      <label for="wifiPassword">Password</label>
      <input id="wifiPassword" class="u-full-width" type="password" v-model="settings.wifiPassword" minlength="8" />
    </div>
    <button class="button-primary" @click="validateAndSave">Save</button>
    <div v-html="message"></div>
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

  validateAndSave(): void {
    console.log(this.settings);
    if (!this.settings.deviceName || !this.settings.wifiSSID || this.settings.wifiPassword.length < 8) {
      if (!this.settings.deviceName) {
        this.message = "Device Name cannot be empty.";
      } else if (!this.settings.wifiSSID) {
        this.message = "Wi-Fi SSID cannot be empty.";
      } else if (!this.settings.wifiPassword.length) {
        this.message = "Wi-Fi Password cannot be empty.";
      } else if (this.settings.wifiPassword.length < 8) {
        this.message = "Wi-Fi Password must be at least 8 characters long.";
      }
      return;
    }
    this.save();
  }

  async save(): Promise<void> {
    axios.post("/settings", this.settings).then(() => {
      this.message = "Settings saved! Please reboot device!";
    }).catch((e) => {
      this.message = `<strong>ERROR while save settings:</strong> ${e.message}`;
    });
  }
}

export default toNative(HomeView);
</script>

<style scoped></style>
