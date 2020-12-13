<template>
<div class="wrapper">
  <div class="players">
    <div class="player" v-for="player in players" :key="player.id">
      <router-link to="/playerbio">
        <div class="image">
          <img :src="player.avatar" @click="playerPicked(player)" v-bind:style="{backgroundColor: player.background}">
        </div>
        <div class="info">
          <h1>{{player.username}}</h1>
          <h2 v-if="viewBy === 'wins'">WINS: {{player.wins}}</h2>
          <h2 v-if="viewBy === 'loses'">LOSES: {{player.loses}}</h2>
          <h2 v-if="viewBy === 'kills'">KILLS: {{player.kills}}</h2>
          <h2 v-if="viewBy === 'deaths'">DEATHS: {{player.deaths}}</h2>
          <h2 v-if="viewBy === 'kd'">K/D: {{player.kd}}</h2>
          <h2 v-if="viewBy === 'assists'">ASSISTS: {{player.assists}}</h2>
          <h2 v-if="viewBy === 'wl'">W/L: {{player.wl}}</h2>
        </div>
      </router-link>
    </div>
  </div>
</div>
</template>

<script>
export default {
  name: 'ProductList',
  data() {
    return {
    }
  },
  props: {
    players: Array
  },
  computed: {
    viewBy() {
      return this.$root.$data.viewBy;
    }
  },
  methods: {
  playerPicked(player) {
    this.$root.$data.currentPlayer = player;
  }
  }
}
</script>

<style scoped>
.wrapper {
  display: flex;
  align-items: center;
  justify-content: center;
}

.players {
  margin-top: 20px;
  display: flex;
  flex-wrap: wrap;
  justify-content: space-around;
}

.player {
  margin: 10px;
  margin-top: 50px;
  width: 150px;
}

.player img {
  border: 2px solid #111111;
  height: 150px;
  width: 150px;
  object-fit: cover;
}

.player .image {
  display: flex;
  justify-content: center;
  margin-bottom: 0px;
}

.info {
  background: #111111;
  color: #000;
  padding: 1px 0px;
  height: 50px;
}

.info h1 {
  font-size: 75%;
  color: white;
  text-align: center;
}

.info h2 {
  font-size: 75%;
  color: #AC0703;
  text-align: center;
}

.info p {
  margin: 0px;
  font-size: 10px;
}

button {
  height: 50px;
  background: #000;
  color: white;
  border: none;
}

.auto {
  margin-left: auto;
}
</style>
