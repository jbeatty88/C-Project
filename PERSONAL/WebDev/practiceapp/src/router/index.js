import Vue from 'vue'
import Router from 'vue-router'
import HelloWorld from '@/components/HelloWorld'
import Home from '@/components/Home'
import SouthernThailand from '@/components/SouthernThailand'
import NorthernThailand from '@/components/NorthernThailand'
import Bangkok from '@/components/Bangkok'



Vue.use(Router)

export default new Router({
  routes: [
    {
      path: '/',
      name: 'HelloWorld',
      component: HelloWorld
    },
    {
      pash: '/home',
      name: 'Home',
      component: Home
    },
    {
      path: '/southern_thailand',
      name: 'SouthernThailand',
      component: SouthernThailand
    },
    {
      path: '/northern_thailand',
      name: 'NorthernThailand',
      component: NorthernThailand
    },
    {
      path: '/bangkok',
      name: 'Bangkok',
      component: Bangkok
    }
  ]
})
