<template>
<div>
  <div id="app">
    <nav class="navbar navbar-expand-lg navbar-bg navbar-light navbar-texts">
      <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNavDropdown" aria-controls="navbarNavDropdown" aria-expanded="false" aria-label="Toggle navigation">
        <span class="navbar-toggler-icon"></span>
      </button>
      <div class="collapse navbar-collapse justify-content-between" id="navbarNavDropdown">
        <ul class="navbar-nav d-inline-flex">
          <li class="nav-item active">
            <router-link to="/">
              <a class="nav-link" @click="leavePage" href="index.html">Home <span class="sr-only">(current)</span></a>
            </router-link>
          </li>
          <li class="nav-item dropdown">
            <a class="nav-link" @click="toggleProjects" href="#" id="navbarDropdownMenuLink" role="button" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
              Projects
            </a>
            <div v-if="this.$root.$data.menudown" class="dropdown-menu dropbackground show">
              <router-link to="/projects">
                <a @click="select('Python')" class="dropdown-item" href="index.html">Python <span class="sr-only">(current)</span></a>
              </router-link>
              <router-link to="/projects">
                <a @click="select('R')" class="dropdown-item" href="index.html">R <span class="sr-only">(current)</span></a>
              </router-link>
              <router-link to="/projects">
                <a @click="select('C++')" class="dropdown-item" href="index.html">C++ <span class="sr-only">(current)</span></a>
              </router-link>
              <router-link to="/projects">
                <a @click="select('Java')" class="dropdown-item" href="index.html">Java <span class="sr-only">(current)</span></a>
              </router-link>
              <router-link to="/projects">
                <a @click="select('Applied Math')" class="dropdown-item" href="index.html">Applied Math <span class="sr-only">(current)</span></a>
              </router-link>
              <router-link to="/projects">
                <a @click="select('Web Development')" class="dropdown-item" href="index.html">Web Development <span class="sr-only">(current)</span></a>
              </router-link>
            </div>
          </li>
          <li class="nav-item">
            <router-link to="/bio">
              <a class="nav-link" @click="leavePage" href="index.html">Bio <span class="sr-only">(current)</span></a>
            </router-link>
          </li>
        </ul>
        <div class="email">
          <h3>calebleehill1993@gmail.com</h3>
        </div>
      </div>
    </nav>
    <div class="topbar"></div>
    <nav v-if="this.$root.$data.menudown" class="navbar navbar-expand-lg navbar-light navbar-texts subbar">
      <div class="collapse navbar-collapse justify-content-start">
        <ul class="navbar-nav d-inline-flex">
          <li class="nav-item active">
            <router-link to="/projects">
              <a @click="select('Python')" class="subbar-link" href="index.html">Python <span class="sr-only">(current)</span></a>
            </router-link>
          </li>
          <li class="nav-item active">
            <router-link to="/projects">
              <a @click="select('R')" class="subbar-link" href="index.html">R <span class="sr-only">(current)</span></a>
            </router-link>
          </li>
          <li class="nav-item active">
            <router-link to="/projects">
              <a @click="select('C++')" class="subbar-link" href="index.html">C++ <span class="sr-only">(current)</span></a>
            </router-link>
          </li>
          <li class="nav-item active">
            <router-link to="/projects">
              <a @click="select('Java')" class="subbar-link" href="index.html">Java <span class="sr-only">(current)</span></a>
            </router-link>
          </li>
          <li class="nav-item active">
            <router-link to="/projects">
              <a @click="select('Applied Math')" class="subbar-link" href="index.html">Applied Math <span class="sr-only">(current)</span></a>
            </router-link>
          </li>
          <li class="nav-item active">
            <router-link to="/projects">
              <a @click="select('Web Development')" class="subbar-link" href="index.html">Web Development <span class="sr-only">(current)</span></a>
            </router-link>
          </li>
        </ul>
      </div>
    </nav>
    <div class="content">
      <router-view />
    </div>
    <div class="footer">
      <router-link to="/admin" style="margin: auto 30px auto auto;">Admin</router-link><a href="https://github.com/calebleehill1993/portfolio/tree/master/calebleehill.modernfloppydisk.com">Github for Code</a>
    </div>
  </div>
</div>
</template>

<script>
// @ is an alias to /src
export default {
  name: 'App',
  data() {
    return {}
  },
  methods: {
    toggleProjects() {
      this.$root.$data.menudown = !this.$root.$data.menudown;
    },
    select(type) {
      this.$root.$data.type = type;
      this.toggleProjects();
    },
    leavePage() {
      if (this.$root.$data.menudown == true) {
        this.$root.$data.menudown = false;
      }
    }
  }
}
</script>

<style>
@media (min-width: 992px) {
  .dropdown-menu.show {
    display: none;
  }
}

.dropdown-menu.show {
  box-shadow: 2px 2px 4px #000000;
}

@media (max-width: 991px) {
  .email {
    display: none;
  }
}

.navbar-toggler {
  margin: 10px 0px;
  background-color: #493830;
}

.topbar {
  height: 5px;
  background-color: #493830;
  box-shadow: 2px 2px 4px #000000;
}

@media (max-width: 991px) {
  .subbar {
    display: none;
  }
}

.subbar-link {
  color: #493830;
  font-size: 20px;
  padding: 10px;
  padding-left: 20px;
  padding-right: 20px;
}

.subbar {
  background-color: #f6f9f4;
  box-shadow: 2px 2px 4px #000000;
}

.navbar h3 {
  margin: auto 0px;
  font-size: 20px
}

.navbar {
  padding-top: 0rem;
  padding-bottom: 0rem;
}

.navbar-bg {
  background-color: #0a5546;
  color: #f6f9f4;
}

.navbar-texts {
  font-family: 'EB Garamond', serif;
  font-size: 25px;
  color: #f6f9f4;
}

.navbar-light .navbar-nav .nav-link {
  color: #f6f9f4;
}

html {
  box-sizing: border-box;
}

body {
  font-family: 'Montserrat', sans-serif;
  font-size: 16px;
  background: #fff;
  padding: 0px;
  margin: 0px;
  background: url("/images/background.jpg") repeat fixed;
}

/* Header */
.header {
  display: flex;
  padding: 10px 100px 0px 100px;
  background-color: #5BDEFF;
  color: #1C454F;
}

.title {
  margin-top: 5px;
}

.title h1 {
  font-size: 30px;
}

.content {
  padding: 20px 0px;
  min-height: 500px;
}

/* Footer */
.footer {
  height: 50px;
  padding: 20px 100px 0px 100px;
  background: #e3e3e3;
  font-size: 12px;
}

.footer a {
  color: #000;
}

h1,
h2,
h3 {
  font-family: 'EB Garamond', serif;
}

h1 {
  font-size: 42px;
}

h2 {
  font-size: 24px;
}

.github {
  margin: 50px;
  text-align: center;
}
</style>
