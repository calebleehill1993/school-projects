<template>
<div>
<div>
  <PlayerBio :player="player" />
</div>
<div class="github">
  <a href="https://github.com/calebleehill1993/portfolio/tree/master/playerstats.modernfloppydisk.com">Github Classroom</a>
</div>
</div>
</template>

<script>
import PlayerBio from "../components/PlayerBio.vue"
export default {
  name: 'Cart',
  components: {
    PlayerBio
  },
  data() {
    return {
    }
  },
  computed: {
    player() {
      return this.$root.$data.currentPlayer;
    },
    notEmpty() {
      return this.$root.$data.notEmpty;
    }
  },
  methods: {
  }
}
</script>
