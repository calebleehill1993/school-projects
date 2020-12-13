<template>
<div>
<div>
  <div class="pure-menu pure-menu-horizontal">
    <ul class="pure-menu-list">
      <li class="pure-menu-item"><a @click="select('wins')" href="#" class="pure-menu-link">Wins</a></li>
      <li class="pure-menu-item"><a @click="select('loses')" href="#" class="pure-menu-link">Loses</a></li>
      <li class="pure-menu-item"><a @click="select('wl')" href="#" class="pure-menu-link">Win/Lose Ratio</a></li>
      <li class="pure-menu-item"><a @click="select('kills')" href="#" class="pure-menu-link">Kills</a></li>
      <li class="pure-menu-item"><a @click="select('deaths')" href="#" class="pure-menu-link">Deaths</a></li>
      <li class="pure-menu-item"><a @click="select('kd')" href="#" class="pure-menu-link">Kill/Death Ratio</a></li>
      <li class="pure-menu-item"><a @click="select('assists')" href="#" class="pure-menu-link">Assists</a></li>
    </ul>
  </div>
  <ProductList v-if="viewBy === 'wins'" :players="playersWins" />
  <ProductList v-if="viewBy === 'loses'" :players="playersLoses" />
  <ProductList v-if="viewBy === 'wl'" :players="playersWl" />
  <ProductList v-if="viewBy === 'kills'" :players="playersKills" />
  <ProductList v-if="viewBy === 'deaths'" :players="playersDeaths" />
  <ProductList v-if="viewBy === 'kd'" :players="playersKd" />
  <ProductList v-if="viewBy === 'assists'" :players="playersAssists" />
</div>
<div class="github">
  <a href="https://github.com/calebleehill1993/portfolio/tree/master/playerstats.modernfloppydisk.com">Github Classroom</a>
</div>
</div>
</template>

<script>
import ProductList from "../components/ProductList.vue"
export default {
  name: 'Browse',
  components: {
    ProductList
  },
  data() {
    return {
    }
  },
  computed: {
    playersWins() {
      let sorted = this.$root.$data.players;
      sorted.sort((a, b) => (a.wins < b.wins ? 1 : -1));
      return sorted;
    },
    playersLoses() {
      let sorted = this.$root.$data.players;
      return sorted.sort((a, b) => (a.loses < b.loses ? 1 : -1));
    },
    playersKills() {
      let sorted = this.$root.$data.players;
      return sorted.sort((a, b) => (a.kills < b.kills ? 1 : -1));
    },
    playersAssists() {
      let sorted = this.$root.$data.players;
      return sorted.sort((a, b) => (a.assists < b.assists ? 1 : -1));
    },
    playersDeaths() {
      let sorted = this.$root.$data.players;
      return sorted.sort((a, b) => (a.deaths < b.deaths ? 1 : -1));
    },
    playersWl() {
      let sorted = this.$root.$data.players;
      return sorted.sort((a, b) => (a.wl < b.wl ? 1 : -1));
    },
    playersKd() {
      let sorted = this.$root.$data.players;
      return sorted.sort((a, b) => (a.kd < b.kd ? 1 : -1));
    },
    viewBy() {
      return this.$root.$data.viewBy;
    }
  },
  methods: {
    select(stat) {
      this.$root.$data.viewBy = stat;
    }
  }
}
</script>

<style>

.pure-menu-horizontal {
  display: flex;
  justify-content: space-evenly;
  background: #111111;
}

</style>
