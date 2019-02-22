<template>
  <div class="users">
    <h1>Users</h1>
    <form v-on:submit="addUser">
      <input type="text" v-model="newUser.name" placeholder="Enter Name">
      <br />
      <input type="text" v-model="newUser.email" placeholder="Enter Email">
      <br />
      <input type="submit" value="Submit">
    </form>
    <ul>
      <li v-for="user in users">
        <input type="checkbox" class="toggle" v-model="user.contacted">
        <span :class="{contacted: user.contacted}">
          {{ user.name }}: {{ user.email }} <button v-on:click="deleteUser">X</button>
        </span>
      </li>
    </ul>
  </div>
</template>

<script>
  export default {
    name: 'users',
    data() {
      return {
        newUser: {},
        users: [
          {
            name: 'Josh Beatty',
            contacted: false,
            email: 'jbeatty8@byu.edu'
          },
          {
            name: 'Natthaya Beatty',
            contacted: false,
            email: 'nbeatty8@byu.edu'
          },
          {
            name: 'ChaiChana Win Beatty',
            contacted: false,
            email: 'ccwbeatty8@byu.edu'
          }
        ]
      }
    },
    methods: {
      addUser: function(e) {
        this.users.push({
          name: this.newUser.name,
          contacted: false,
          email: this.newUser.email
        });
        e.preventDefault();
      },
      deleteUser: function() {
        this.users.splice(this.users.indexOf(user), 1);
      }
    }
  }
</script>

<style scoped>
.contacted {
  text-decoration: line-through;
}


</style>
