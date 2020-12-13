<template>
<div>
<div>
  <div class="wrapper">
    <div class="search">
      <form class="pure-form">
        <i class="fas fa-search"></i><input v-model="searchText" />
      </form>
    </div>
  </div>
  <PlayerList :players="players" />
</div>
<div class="github">
  <a href="https://github.com/calebleehill1993/portfolio/tree/master/playerstats.modernfloppydisk.com">Github Classroom</a>
</div>
</div>
</template>

<script>
import PlayerList from "../components/PlayerList.vue"
export default {
  name: 'Home',
  components: {
    PlayerList
  },
  data() {
    return {
      searchText: '',
    }
  },
  computed: {
    players() {
      let sorted = this.$root.$data.players;
      sorted.sort((a, b) => (a.id > b.id ? 1 : -1));
      return sorted.filter(player => player.username.toLowerCase().search(this.searchText) >= 0);
    }
  },
}
</script>

<style scoped>
.wrapper {
  display: flex;
  align-items: center;
  justify-content: center;
}

.search {
  border: 1px solid #ccc;
  border-radius: 4px;
  width: 50%;
  background: white;
}

form {
  display: table;
  width: 100%;
}

i {
  display: table-cell;
  padding-left: 10px;
  width: 1px;
}

input {
  display: table-cell;
  font-size: 20px;
  border: none !important;
  box-shadow: none !important;
  width: 100%;
  height: 40px;
}
</style>
