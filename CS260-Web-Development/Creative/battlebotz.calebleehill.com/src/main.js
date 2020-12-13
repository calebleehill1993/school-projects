import Vue from 'vue'
import App from './App.vue'
import router from './router'
import mock from './mock-data.js'

for (let i = 0; i < mock.length; i++){
  mock[i].kd = (mock[i].kills / mock[i].deaths).toPrecision(4);
  mock[i].wl = (mock[i].wins / mock[i].loses).toPrecision(4);
}

let data = {
  players: mock,
  viewBy: "wins",
  currentPlayer: {},
}

new Vue({
  router,
  data,
  render: h => h(App)
}).$mount('#app')
