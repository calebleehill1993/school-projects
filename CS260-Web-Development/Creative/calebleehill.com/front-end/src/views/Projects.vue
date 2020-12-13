<template>
<div>
  <br>
  <div class="topbar"></div>
  <div class="projects">
    <h1>{{this.$root.$data.type}} Projects</h1>
    <section class="project-gallery">
      <router-link to="/project">
        <div @click="select(item)" class="project" v-for="item in projects" :key="item.id">
          <h2>{{item.title}}</h2>
          <p class="text">{{item.description}}</p>
        </div>
      </router-link>
    </section>
  </div>
  <div class="topbar"></div>
  <br>
</div>
</template>

<script>
// @ is an alias to /src
import axios from 'axios';
export default {
  name: 'Projects',
  data() {
    return {
      items: [],
    }
  },
  created() {
    this.getItems();
  },
  computed: {
    projects() {
      if (this.$root.$data.type == "All") {
        return this.items;
      }
      return this.items.filter(project => project.type == this.$root.$data.type);
    }
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
    select(project) {
      this.$root.$data.currentProject = project;
    }
  }
}
</script>

<style scoped>
h1 {
  text-align: center;
  padding: 20px;
}

.text {
  overflow: hidden;
  text-overflow: ellipsis;
  display: -webkit-box;
  -webkit-line-clamp: 3;
  /* number of lines to show */
  -webkit-box-orient: vertical;
}

.projects {
  background-image: url("/images/paper-background.jpg");
  padding: 10px;
}


/* Masonry */
*,
*:before,
*:after {
  box-sizing: inherit;
}

.project-gallery {
  column-gap: 4em;
}

.project {
  margin: 0 0 3em;
  display: inline-block;
  width: 100%;
  height: 120px;
  color: #212529;
}

/* Masonry on large screens */
@media only screen and (min-width: 1024px) {
  .project-gallery {
    column-count: 4;
  }
}

/* Masonry on medium-sized screens */
@media only screen and (max-width: 1023px) and (min-width: 768px) {
  .project-gallery {
    column-count: 3;
  }
}

/* Masonry on small screens */
@media only screen and (max-width: 767px) and (min-width: 540px) {
  .project-gallery {
    column-count: 2;
  }
}
</style>
