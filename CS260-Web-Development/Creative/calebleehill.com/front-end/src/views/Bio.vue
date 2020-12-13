<template>
<div class="home">
  <p></p>
  <div class="topbar"></div>
  <div class="container-fluid">
    <div class="main">
      <div class="row">
        <div class="row main-width">
          <div class="col-sm flex-center">
            <div class="main-description">
              <h1>Caleb Lee Hill</h1>
              <p>Albert Einstein once said “Any fool can know. The point is to understand.”
                It has never been enough for me to simply know anything, I want to understand
                it on its deepest and most fundamental level. I spent some time during my
                education studying Mechanical Engineering, but felt unsatisfied by all the
                “how’s” and “why’s” that never got answered. So, I moved on to physics, but
                though the physics explained the Mechanical Engineering, I was faced with
                even more questions of “why” and “how.” So finally, I came to study mathematics,
                the language used to define the universe and explain how our world works,
                and statistics, the study of taking what we know and finding answers for
                the future. I love to learn, explore, extrapolate, and to teach what I
                have come to understand. </p>
              <p>Outside of my education, I love people. Starting with my wife and
                expanding to my family, friends, and the world as a whole. There is
                nothing more satisfying than working in true collaboration with others,
                to create something that no one of us could have achieved on our own.</p>
              <p>calebleehill1993@gmail.com</p>
              <a href="#">LinkedIn Profile</a>
              <br>
              <a href="/documents/Caleb Hill's Resume (STATS).pdf">Full Resume</a>
            </div>
          </div>
          <div class="col-sm">
            <img src="/images/Caleb-Bio.jpg" class="portrait">
          </div>
        </div>
      </div>
    </div>
  </div>

  <div class="topbar"></div>
  <br>
</div>
</template>

<style scoped>

.flex-center {
  display: flex;
  align-items: center;
  justify-content: center;
  height: 100%;
}

.container-fluid {
  padding: 0px;
  margin: auto;
}

.portrait {
  border: 5px solid #555555;
  border-radius: 5px;
  width: 100%;
  min-width: 136px;
  min-height: 156px;
}

.main-description {
  display: inline-block;
  text-align: left;
  max-width: 500px;
  font-family: 'EB Garamond', serif;
  align-items: center;
  justify-content: center;
}

.main-description a {
  font-size: 20px;
}

.col-sm {
  text-align: center;
}

.main {
  padding: 20px;
  background-image: url("/images/paper-background.jpg");
}

.main-width {
  width: 100%;
  max-width: 1200px;
  margin: auto;
  justify-content: center;
  align-items: center;
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

.image {
  margin: auto;
  width: 100%;
  text-align: center;
}

.text-center {
  margin: auto;
}

.image img {
  width: 100%;
  border-radius: 10px;
  box-shadow: 2px 2px 4px #000000;
}

.image-link-grid {
  display: grid;
  grid-template: auto auto auto / 1fr 1fr 1fr;
  grid-column-gap: 30px;
  grid-row-gap: 30px;
  max-width: 1300px;
  margin: 0px;
  padding: 20px;
  padding-top: 50px;
}

/* Tablet Styles */
@media only screen and (max-width: 960px) {
  .image-link-grid {
    grid-template: auto auto auto auto / 1fr 1fr;
  }
}

.projects-alignment {
  display: flex;
  justify-content: space-between;
}

@media only screen and (max-width: 960px) {
  .col-sm-2 {
    display: none;
  }
}
</style>
