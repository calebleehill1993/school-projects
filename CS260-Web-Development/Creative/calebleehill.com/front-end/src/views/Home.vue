<template>
<div class="home">
  <p></p>
  <div class="topbar"></div>
  <div class="container-fluid">
    <div class="main">
      <div class="row">
        <div class="row main-width">
          <div class="col-sm-4">
            <div class="frame">
              <img src="/images/Caleb.jpg" class="portrait">
            </div>
          </div>
          <div class="col-sm-7 flex-center">
            <div class="main-description">
              <h1>Caleb Lee Hill</h1>
              <h2>Data Scientist, Programmer, Applied Mathematician</h2>
              <p>calebleehill1993@gmail.com</p>
              <a href="https://www.linkedin.com/in/calebleehill/">LinkedIn Profile</a>
              <br>
              <a href="/documents/Caleb Hill's Resume (STATS).pdf">Full Resume</a>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>

  <div class="topbar"></div>
  <br><br>
  <div class="topbar"></div>
  <div class="container-fluid">
    <p class="projects-space"><br></p>
    <div class="projects-banner-top">
      <div class="row">
        <h2>P R O J E C T S</h2>
      </div>
    </div>
    <div class="main-projects">
      <div class="row">
        <div class="projects-alignment main-width">
          <div class="col-sm-4">
            <section class="image-link-grid">
              <div class="image">
                <div class="max-width-300 text-center">
                  <router-link @click="toggleProjects" to="/projects">
                    <img @click="select('Python')" href="index.html" src="/images/python.png">
                  </router-link>
                </div>
              </div>
              <div class="image">
                <div class="max-width-300 text-center">
                  <router-link @click="toggleProjects" to="/projects">
                    <img @click="select('R')" href="index.html" src="/images/r.jpg">
                  </router-link>
                </div>
              </div>
              <div class="image">
                <div class="max-width-300 text-center">
                  <router-link @click="toggleProjects" to="/projects">
                    <img @click="select('C++')" href="index.html" src="/images/c++.jpg">
                  </router-link>
                </div>
              </div>
              <div class="image">
                <div class="max-width-300 text-center">
                  <router-link @click="toggleProjects" to="/projects">
                    <img @click="select('Java')" href="index.html" src="/images/java.jpg">
                  </router-link>
                </div>
              </div>
              <div class="image">
                <div class="max-width-300 text-center">
                  <router-link @click="toggleProjects" to="/projects">
                    <img @click="select('Applied Math')" href="index.html" src="/images/math.jpg">
                  </router-link>
                </div>
              </div>
              <div class="image">
                <div class="max-width-300 text-center">
                  <router-link @click="toggleProjects" to="/projects">
                    <img @click="select('Web Development')" href="index.html" src="/images/web.jpg">
                  </router-link>
                </div>
              </div>
            </section>
          </div>
          <div class="col-sm-2 flex-center">
            <div class="projects-banner">
              <h2>P<br>R<br>O<br>J<br>E<br>C<br>T<br>S</h2>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
  <div class="topbar"></div>
  <br>
</div>
</template>

<script>
// @ is an alias to /src
import axios from 'axios';
export default {
  name: 'Home',
  data() {
    return {
      items: [],
    }
  },
  created() {
    this.getItems();
  },
  methods: {
    async getItems() {
      try {
        let response = await axios.get("/api/items");
        this.items = response.data;
        return true;
      } catch (error) {
        console.log(error);
      }
    },
    select(type) {
      if (this.$root.$data.menudown == true){
        this.$root.$data.menudown = false;
      }
      this.$root.$data.type = type;
    }
  }
}
</script>

<style scoped>
.projects-space {
  background: #0a5546;
  margin: 0px;
}

.projects-alignment .col-sm-2 {
  flex: 0 0 20%;
  max-width: 20%;
}

.projects-alignment .col-sm-4 {
  flex: 0 0 80%;
  max-width: 80%;
}

.max-width-300 {
  max-width: 150px;
}

.projects-banner-top {
  background-image: url("/images/paper-background.jpg");
  padding-top: 8px;
}

@media only screen and (min-width: 961px) {
  .projects-banner-top {
    display: none;
  }
  .projects-space {
    display: none;
  }
}

.projects-banner-top h2 {
  font-family: 'Bebas Neue', cursive;
  height: 100%;
  font-size: 40px;
  font-weight: 800;
  margin: auto;
}

.projects-banner h2 {
  font-family: 'Bebas Neue', cursive;
  height: 100%;
  font-size: 40px;
  font-weight: 800;
}


.projects-banner {
  padding: 28px 45px 15px 45px;
  background-image: url("/images/paper-background.jpg");
  text-align: center;
  margin: 0px;
  max-width: 100px;
  height: 100%;
}

.col-sm-4 {
  min-width: 250px;
  text-align: center;
  margin: auto;
  display: inline-block;
}

.col-sm-2 {
  text-align: center;
  display: inline-block;
  margin: 0px auto;
  height: 100%;
}

.flex-center {
  display: flex;
  align-items: center;
  justify-content: center;
  height: 100%;
}

.container-fluid {
  padding: 0px;
  margin: auto;
}

.portrait {
  border: 5px solid #555555;
  border-radius: 5px;
  width: 100%;
  min-width: 136px;
  min-height: 156px;
}

.main-description {
  display: inline-block;
  text-align: center;
  max-width: 500px;
  font-family: 'EB Garamond', serif;
  align-items: center;
  justify-content: center;
}

.main-description a {
  font-size: 20px;
}

.col-sm {
  text-align: center;
}

.frame {
  padding: 30px;
  background-color: #888888;
  display: inline-block;
  border: 2px solid #666666;
}

.main-projects {
  padding: 0px 20px;
  background-color: #0a5546;
}

.main {
  padding: 20px;
  background-image: url("/images/paper-background.jpg");
}

.main-width {
  width: 100%;
  max-width: 1120px;
  margin: auto;
  justify-content: center;
  align-items: center;
}

.image h2 {
  font-style: italic;
}

/* Masonry */
*,
*:before,
*:after {
  box-sizing: inherit;
}

.image {
  margin: auto;
  width: 100%;
  text-align: center;
}

.text-center {
  margin: auto;
}

.image img {
  width: 100%;
  border-radius: 10px;
  box-shadow: 2px 2px 4px #000000;
}

.image-link-grid {
  display: grid;
  grid-template: auto auto auto / 1fr 1fr 1fr;
  grid-column-gap: 30px;
  grid-row-gap: 30px;
  max-width: 1300px;
  margin: 0px;
  padding: 20px;
  padding-top: 50px;
}

/* Tablet Styles */
@media only screen and (max-width: 960px) {
  .image-link-grid {
    grid-template: auto auto auto auto / 1fr 1fr;
  }
}

.projects-alignment {
  display: flex;
  justify-content: space-between;
}

@media only screen and (max-width: 960px) {
  .col-sm-2 {
    display: none;
  }
}
</style>
