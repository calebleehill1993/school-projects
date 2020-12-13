<template>
<div>
  <br>
  <div class="topbar"></div>
  <div class="project">
    <br>
    <h1>{{project.title}}</h1>
    <h2>{{project.type}}</h2>
    <br>
    <div class="video">
      <div class=iframe-container>
        <iframe width="560" height="315" :src="project.path" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
      </div>
    </div>
    <div class="description">
      <br>
      <h2>Project Description</h2>
      <div v-for="paragraph in description" :key="paragraph">
        <p>{{paragraph}}</p>
      </div>
      <a :href="project.githubLink">GitHub Link to Project Code</a><br><br>
      <p>Date Completed: {{project.dateCompleted}}</p>
      <p>Class: {{project.class}}</p>
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
  name: 'Project',
  data() {
    return {
      items: [],
    }
  },
  created() {
    this.getItems();
  },
  computed: {
    project() {
      if (Object.keys(this.$root.$data.currentProject).length === 0) {
        return this.items[0];
      }
      return this.$root.$data.currentProject;
    },
    description() {
      return this.project.description.split("\n").filter(paragraph => paragraph !== "");
    },
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
  },
}
</script>


<style scoped>

.description {
  margin: auto;
  max-width: 1120px;
  padding-left: 90px;
  padding-right: 60px;
  padding-bottom: 20px;
}

h1, h2 {
  text-align: center;
}

.project {
  background-image: url("/images/paper-background.jpg");
}

.video {
  max-width: 1080px;
  padding-left: 100px;
  padding-right: 100px;
  padding-bottom: 20px;
  padding-top: 0px;
  margin: auto;
}

.iframe-container {
  position: relative;
  width: 100%;
  padding-bottom: 56.25%;
  height: 0;
  box-shadow: 2px 2px 4px #000000;
}

.iframe-container iframe {
  position: absolute;
  top: 0;
  left: 0;
  width: 100%;
  height: 100%;
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

.image-gallery {
  column-gap: 1.5em;
}

.image {
  margin: 0 0 1.5em;
  display: inline-block;
  width: 100%;
}

.image img {
  width: 100%;
}

/* Masonry on large screens */
@media only screen and (min-width: 1024px) {
  .image-gallery {
    column-count: 4;
  }
}

/* Masonry on medium-sized screens */
@media only screen and (max-width: 1023px) and (min-width: 768px) {
  .image-gallery {
    column-count: 3;
  }
}

/* Masonry on small screens */
@media only screen and (max-width: 767px) and (min-width: 540px) {
  .image-gallery {
    column-count: 2;
  }
}
</style>
