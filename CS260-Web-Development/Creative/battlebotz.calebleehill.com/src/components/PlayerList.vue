<template>
<div class="wrapper">
  <div class="players">
    <div class="player" v-for="player in players" :key="player.id">
      <router-link to="/playerbio">
        <div @click="playerPicked(player)">
        <div class="image">
          <img :src="player.avatar" v-bind:style="{backgroundColor: player.background}">
        </div>
        <div class="info">
          <h1>{{player.username}}</h1>
        </div>
        </div>
      </router-link>
    </div>
  </div>
</div>
</template>

<script>
export default {
  name: 'ProductList',
  props: {
    players: Array
  },
  computed: {
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
  margin-top: 30px;
  width: 150px;
}

.player img {
  border: 2px solid #444444;
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
  background: #444444;
  color: white;
  padding: 1px 0px;
  height: 40px;
  text-align: center;
}

.info h1 {
  font-size: 16px;
}

.info h2 {
  font-size: 14px;
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
