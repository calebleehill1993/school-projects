import Vue from 'vue'
import VueRouter from 'vue-router'
import Home from '../views/Home.vue'
import Admin from '../views/Admin.vue'
import Projects from '../views/Projects.vue'
import Bio from '../views/Bio.vue'
import Project from '../views/Project.vue'

Vue.use(VueRouter)

const routes = [{
    path: '/',
    name: 'home',
    component: Home
  },
  {
    path: '/admin',
    name: 'admin',
    component: Admin
  },
  {
    path: '/projects',
    name: 'projects',
    component: Projects
  },
  {
    path: '/bio',
    name: 'bio',
    component: Bio
  },
  {
    path: '/project',
    name: 'project',
    component: Project
  }
]

const router = new VueRouter({
  mode: 'history',
  base: process.env.BASE_URL,
  routes
})

export default router
