import Vue from 'vue'
import App from './App.vue'
import router from './router'
import test_data from './test.js'

Vue.config.productionTip = false

let data = {
  type: "All",
  menudown: false,
  currentProject: {},
}

let test = test_data;
//
import axios from 'axios';

for (const project of test){
  try {
    axios.post('/api/items', {
      title: project.title,
      description: project.description,
      path: project.path,
      type: project.type,
      dateCompleted: project.dateCompleted,
      githubLink: project.githubLink,
      class: project.class
    });
  } catch (error) {
    console.log(error);
  }
}

new Vue({
  router,
  data,
  render: h => h(App)
}).$mount('#app')
