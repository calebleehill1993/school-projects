<template>
<div id="app">
  <div id="menu">
    <div id="brand">
      <router-link to="/">
        <img src="/images/logo.png">
        <h2><em>b</em>attle<em>b</em>otz</h2>
      </router-link>
    </div>
    <div id="side">
      <router-link to="/browse">
        <div class="menu-item stats">
          <img src="/images/stats.png">
          <p>Player Stats</p>
        </div>
      </router-link>
    </div>
  </div>
  <router-view />
</div>
</template>

<script>

export default {
  name: 'Cart',
  components: {
  },
  data() {
    return {
    }
  },
  computed: {
  },
  methods: {
  }
}
</script>

<style>
* {
  box-sizing: border-box;
}

body {
  margin: 50px 100px;
  background-image: url("../images/gears.jpg");
  background-size: 100%;
}

a em {
  color: white;
}

#menu {
  display: grid;
  grid-template-columns: 1fr 1fr 1fr;
  grid-column-gap: 5px;
  grid-template-areas: "none brand side";
  margin-bottom: 50px;
}

#menu a {
  color: #B84901;
}

#brand {
  grid-area: brand;
  display: flex;
  justify-content: center;
}

a h2 {
  color: #AC0703;
  text-decoration: none;
  text-align: center;
  font-size: 40px;
  margin: auto;
}

#brand img {
  height: 200px;
}

#side {
  grid-area: side;
  display: flex;
  justify-content: flex-end;
}

#side img {
  width: 50px;
}

a {
  text-decoration: none;
}

.menu-item {
  display: flex;
  flex-direction: column;
}

.stats img {
  margin: auto;
}

.menu-item p {
  margin: 10px 0px 0px 0px;
  color: #AC0703;
  font-weight: bold;
}

.stats {
  background: white;
  padding: 10px;
  border-radius: 10px;
}

.github {
margin: 50px;
text-align: center;
}

.github a {
  color: white;
}

.github a:visited {
  color: white;
}


</style>
