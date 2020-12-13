<template>
<div class="page">
<div class="wrapper">
  <div class="image">
    <img :src="player.avatar" v-bind:style="{backgroundColor: player.background}">
  </div>
  <div class="players">
    <div class="player">
      <div class="info">
        <h1>{{player.username}}</h1>
        <p>{{player.timezone}}</p>
        <p>{{player.email}}</p>
        <h2>{{player.firstname}} {{player.lastname}}</h2>
      </div>
      <div class="stats">
        <div>
        <h2>WINS: {{player.wins}}</h2>
        <h2>LOSES: {{player.loses}}</h2>
        </div>
        <h2>W/L: {{player.wl}}</h2>
        <div>
        <h2>KILLS: {{player.kills}}</h2>
        <h2>DEATHS: {{player.deaths}}</h2>
        </div>
        <h2>K/D: {{player.kd}}</h2>
        <div>
        <h2>ASSISTS: {{player.assists}}</h2>
        </div>
      </div>
    </div>
  </div>
</div>
<div class="description">
<h1>Description</h1>
<p>{{ player.description }}</p>
</div>
<h3>Post to {{player.username}}'s Board</h3>
<div class="comment-section">
<form v-on:submit.prevent="addComment">
  <input v-model="addedName" placeholder="Name">
  <textarea v-model="addedComment"></textarea>
  <br />
  <button class="post" type="submit">Post</button>
</form>
<h3>{{player.username}}'s Board</h3>
<div v-for="comment in player.comments" :key="comment.number">
  <hr>
  <p>{{comment.text}}</p>
  <p><i>-- {{comment.author}} --</i></p>
</div>
</div>
</div>
</template>

<script>
export default {
  name: 'PlayerBio',
  data() {
    return {
      addedName: '',
      addedComment: '',
    }
  },
  props: {
    players: Array,
  },
  computed: {
    player() {
      return this.$root.$data.currentPlayer;
    },
    comments() {
      return this.player.comments;
    }
  },
  methods: {
    addComment() {
      if (typeof(this.player.comments) == "undefined") {
        console.log("YOUR ARE HERE");
        this.$root.$data.players.filter(e => e.id === this.player.id)[0].comments = [];
      }
      this.$root.$data.players.filter(e => e.id === this.player.id)[0].comments.push({
        author: this.addedName,
        text: this.addedComment,
      });
      this.addedName = '';
      this.addedComment = '';
    },
  },
}
</script>

<style scoped>

.page {
  background: #444444;
  text-align: center;
  padding: 10px;
}

.comment-section {
  text-align: left;
  margin: 0px 100px;
}

textarea {
    width: 100%;
    max-width: 500px;
    height: 100px;
    display: block;
}

input {
  width: 33%;
  min-width: 75px;
}

.description {
  padding: 30px;
  color: #222222;
}

.wrapper {
  display: flex;
  align-items: center;
  justify-content: space-around;
  background: #444444;
  flex-wrap: wrap;
}

.stats {
  display: flex;
  align-items: center;
  justify-content: space-between;
  background: #444444;
  flex-wrap: wrap;
  padding: 10px;
  text-align: left;
  color: #222222;
}

.players {
  display: flex;
  flex-wrap: wrap;
  justify-content: space-around;
  background: #222222;
}

.post {
  width: 80px;
  height: 30px;
}

.player {
  margin: 10px;
  margin-top: 0px;
  width: 210px;
}

.player img {
  border: 2px solid #333;
  height: 250px;
  width: 200px;
  object-fit: cover;
}

.image {
  display: flex;
  justify-content: center;
  margin: 20px;
  object-fit: cover;
}

img {
  width: 100%;
}

.info {
  color: white;
}

.info h1 {
  font-size: 24px;
  color: #AC0703;
  margin: 10px;
}

.info h2 {
  font-size: 16px;
}

.info p {
  margin: 5px;
  font-size: 12px;
}

h2 {
  font-size: 12px;
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
