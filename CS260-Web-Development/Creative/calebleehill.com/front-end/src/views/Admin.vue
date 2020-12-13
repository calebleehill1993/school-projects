<template>
<div class="admin">
  <h1>The Admin Page!</h1>
  <div class="heading">
    <div class="circle">1</div>
    <h2>Add an Item</h2>
  </div>
  <div class="add">
    <div class="form">
      <input v-model="title" placeholder="Title"><br>
      <input v-model="type" placeholder="Type"><br>
      <textarea v-model="description" placeholder="Description" cols="40" rows="5"></textarea><br>
      <input type="date" v-model="dateCompleted"><br>
      <input v-model="githubLink" placeholder="GitHub Link"><br>
      <input v-model="Class" placeholder="Class"><br>
      <p></p>
      <input v-model="link" placeholder="YouTube Video ID">
      <button @click="upload">Upload</button>
    </div>
    <div class="upload" v-if="addItem">
      <h2>{{addItem.title}}</h2>
      <h3>{{addItem.type}}</h3>
      <p>{{addItem.description}}</p>
      <img :src="addItem.path" />
    </div>
  </div>
  <div class="heading">
    <div class="circle">2</div>
    <h2>Edit/Delete an Item</h2>
  </div>
  <div class="edit">
    <div class="form">
      <input v-model="findTitle" placeholder="Search">
      <div class="suggestions" v-if="suggestions.length > 0">
        <div class="suggestion" v-for="s in suggestions" :key="s.id" @click="selectItem(s)">{{s.title}}
        </div>
      </div>
    </div>
    <div class="upload" v-if="findItem">
      <input v-model="findItem.title">
      <br>
      <input v-model="findItem.type">
      <br>
      <textarea v-model="findItem.description" cols="40" rows="5"></textarea><br>
      <input v-model="findItem.dateCompleted">
      <br>
      <input v-model="findItem.githubLink">
      <br>
      <input v-model="findItem.class">
      <br>
      <div class="actions" v-if="findItem">
        <button @click="deleteItem(findItem)">Delete</button>
        <button @click="editItem(findItem)">Edit</button>
      </div>
      <p></p>
    </div>
  </div>
</div>
</template>

<script>
import axios from 'axios';
export default {
  name: 'Admin',
  data() {
    return {
      title: "",
      description: "",
      type: "",
      link: "",
      dateCompleted: "",
      githubLink: "",
      Class: "",
      file: null,
      addItem: null,
      items: [],
      findTitle: "",
      findItem: null,
    }
  },
  computed: {
    suggestions() {
      let items = this.items.filter(item => item.title.toLowerCase().startsWith(this.findTitle.toLowerCase()));
      return items.sort((a, b) => a.title > b.title);
    }
  },
  created() {
    this.getItems();
  },
  methods: {
    fileChanged(event) {
      this.file = event.target.files[0]
    },
    async upload() {
      try {
        let link = "https://www.youtube.com/embed/" + this.link;
        let r2 = await axios.post('/api/items', {
          title: this.title,
          description: this.description,
          path: link,
          type: this.type,
          class: this.Class,
          githubLink: this.githubLink,
          dateCompleted: this.dateCompleted,
        });
        this.addItem = r2.data;
      } catch (error) {
        console.log(error);
      }
    },
    async getItems() {
      try {
        let response = await axios.get("/api/items");
        this.items = response.data;
        return true;
      } catch (error) {
        console.log(error);
      }
    },
    selectItem(item) {
      this.findTitle = "";
      this.findItem = item;
    },
    async deleteItem(item) {
      try {
        await axios.delete("/api/items/" + item._id);
        this.findItem = null;
        this.getItems();
        return true;
      } catch (error) {
        console.log(error);
      }
    },
    async editItem(item) {
      try {
        await axios.put("/api/items/" + item._id, {
          title: this.findItem.title,
          description: this.findItem.description,
          type: this.findItem.type,
          class: this.findItem.Class,
          githubLink: this.findItem.githubLink,
          dateCompleted: this.findItem.dateCompleted,
        });
        this.findItem = null;
        this.getItems();
        return true;
      } catch (error) {
        console.log(error);
      }
    },
  },
}
</script>

<style scoped>
.image h2 {
  font-style: italic;
  font-size: 1em;
}

.heading {
  display: flex;
  margin-bottom: 20px;
  margin-top: 20px;
}

.heading h2 {
  margin-top: 8px;
  margin-left: 10px;
}

.add,
.edit {
  display: flex;
}

.circle {
  border-radius: 50%;
  width: 18px;
  height: 18px;
  padding: 8px;
  background: #333;
  color: #fff;
  text-align: center
}

/* Form */
input,
textarea,
select,
button {
  font-family: 'Montserrat', sans-serif;
  font-size: 1em;
}

.form {
  margin-right: 50px;
}

/* Uploaded images */
.upload h2 {
  margin: 0px;
}

.upload img {
  max-width: 300px;
}

/* Suggestions */
.suggestions {
  width: 200px;
  border: 1px solid #ccc;
}

.suggestion {
  min-height: 20px;
}

.suggestion:hover {
  background-color: #5BDEFF;
  color: #fff;
}

.admin {
  background-color: #ffffff;
}
</style>
