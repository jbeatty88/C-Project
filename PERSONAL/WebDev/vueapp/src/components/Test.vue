<template>
  <div class="test">
    <input type="text" name="" value="" v-model="title"><br />
    <h1>{{ title }} {{ user.firstName }}</h1>
    <p v-if="showName">{{ user.firstName }} {{ user.lastName }}</p>
    <p v-else="showName">Nobody</p>

    <ul>
      <li v-for="item in items">{{ item.title }}</li>
    </ul>
    <button type="button" name="button" v-on:click="greet('Hello')">Say Greeting</button>
    <br />
    <br />
    <input type="text" v-on:keyup="pressKey" v-on:keyup.enter="enterHit">

    <hr />
    <label> First Name: </label><input type="text" v-model="user.firstName">
    <br />
    <label> First Name: </label><input type="text" v-model="user.lastName">
    <h3>{{ fullName }}</h3>
  </div>
</template>

<script>
  export default {
    name: 'test',
    data() {
      return {
        title: 'Hello',
        user: {
          firstName: 'Josh',
          lastName: 'Beatty'
        },
        showName: true,
        items: [
          { title: 'Natthaya Beatty'},
          { title: 'Zac Beatty'},
          { title: 'Eli Beatty'}
        ]
      }
    },
    methods: {
      greet: function(greeting) {
        alert(greeting);
      },
      pressKey: function(e) {
        console.log(e.target.value);
      },
      enterHit: function() {
        console.log('You hit enter');
      }
    },
    computed: {
      fullName: function() {
        return this.user.firstName + '  ' + this.user.lastName;
      }
    }
  }
</script>

<style scoped>


</style>
