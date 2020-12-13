<template>
<div class="wrapper">
  <div class="products">
    <div class="product" v-for="product in products" :key="product.id">
      <div class="info">
        <h1>{{product.name}} ({{product.quantity}})</h1>
        <p>{{product.country}}</p>
      </div>
      <div class="image">
        <img :src="'/images/products/'+product.image">
      </div>
      <div class="price">
        <h2>{{product.price}}</h2>
        <button @click="remove(product)" class="auto">Remove</button>
      </div>
    </div>
  </div>
</div>
</template>

<script>
export default {
  name: 'CartList',
  props: {
    products: Array,
  },

  methods: {
    remove(product) {
      let index = this.$root.$data.cart.map(e => e.id).indexOf(product.id);
      if (this.$root.$data.cart[index].quantity === 1) {
        this.$root.$data.cartCount -= 1;
        this.$root.$data.cart = this.$root.$data.cart.filter(cartItem => cartItem.id !== product.id);
        if (this.$root.$data.cartCount < 1) {
          this.$root.$data.notEmpty = false;
        }
        return;
      }
      this.$root.$data.cartCount -= 1;
      this.$root.$data.cart[index].quantity -= 1;
      this.$root.$data.cart.push({test: 2});
      this.$root.$data.cart.pop();
    }
  }
}
</script>

<style scoped>
.wrapper {
  display: flex;
  align-items: center;
  justify-content: center;
}

.products {
  margin-top: 20px;
  display: flex;
  flex-wrap: wrap;
  justify-content: space-around;
}

.product {
  margin: 10px;
  margin-top: 50px;
  width: 200px;
}

.product img {
  border: 2px solid #333;
  height: 250px;
  width: 200px;
  object-fit: cover;
}

.product .image {
  display: flex;
  justify-content: center;
  margin-bottom: 5px;
}

.info {
  background: #F2921D;
  color: #000;
  padding: 10px 30px;
  height: 80px;
}

.info h1 {
  font-size: 16px;
}

.info h2 {
  font-size: 14px;
}

.info p {
  margin: 0px;
  font-size: 10px;
}


.price {
  display: flex;
}

button {
  height: 50px;
  background: #000;
  color: white;
  border: none;
}

.auto {
  margin-left: auto;
}
</style>
