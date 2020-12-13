<template>
<div>
<div v-if="notEmpty">
<h1> Your Cart </h1>
  <CartList :products="cart" />
</div>
<div v-else>
  <h1>Your Cart is Empty</h1>
</div>
<div class="github">
  <a href="https://github.com/BYU-CS-260-Winter-2020/lab-3b-grocery-store-calebleehill1993">Github Classroom</a>
</div>
</div>
</template>

<script>
import CartList from "../components/CartList.vue"
export default {
  name: 'Cart',
  components: {
    CartList
  },
  data() {
    return {
    }
  },
  computed: {
    cart() {
      return this.$root.$data.cart;
    },
    notEmpty() {
      return this.$root.$data.notEmpty;
    }
  },
  methods: {
  }
}
</script>
