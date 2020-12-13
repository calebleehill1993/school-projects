document.getElementById("weatherSubmit").addEventListener("click", function(event) {
  event.preventDefault();
  const value = document.getElementById("weatherInput").value;
  if (value === "")
    return;
  console.log(value);
  const appid = "e2cc399b39dde7ce73c633e4f2a94286";
  const url = "https://api.openweathermap.org/data/2.5/weather?q=" + value + ",US&units=imperial" + "&APPID=" + appid;
  fetch(url)
    .then(function(response) {
      return response.json();
    }).then(function(json) {
      let date = new Date();
      let time = date.getTime();
      let diff = date.getTimezoneOffset();
      let utc = time + (diff * 60000);
      let localTime = utc + json.timezone * 1000
      let localTimeString = moment(localTime).format("MMMM Do YYYY h:mm a");
      let currentHour = moment(localTime).format("H");
      let day = "n";
      if (5 < currentHour && currentHour < 20) day = "d";
      let results = "";
      results += '<h2>Weather in ' + json.name + "</h2>";
      results += '<h2>' + localTimeString + "</h2>";
      results += `<div class='main' style='background-image: url("images/` + json.weather[0].icon.slice(0, 2) + day + `.jpg");'>`;
      results += "<div class='hourlyWeather'>";
      results += "<div class='hourlyWeatherInfo'>";
      for (let i=0; i < json.weather.length; i++) {
      results += "<p style='margin: 15px'>" + json.weather[i].description + "</p>";
      if (i !== json.weather.length - 1) results += ", ";
      }
      for (let i=0; i < json.weather.length; i++) {
      results += '<img src="http://openweathermap.org/img/w/' + json.weather[i].icon + '.png"/>';
      }
      results += '<h2>' + Math.round(json.main.temp) + " &deg;F</h2>";
      let deg = json.wind.deg % 360;
      let direction = "N";
      if (deg >= 348.75 || deg < 11.25) direction = "N";
      else if (11.25 <= deg && deg < 33.75) direction = "NNE";
      else if (33.75 <= deg && deg < 56.25) direction = "NE";
      else if (56.25 <= deg && deg < 78.75) direction = "ENE";
      else if (78.75 <= deg && deg < 101.25) direction = "E";
      else if (101.25 <= deg && deg < 123.75) direction = "ESE";
      else if (123.75 <= deg && deg < 146.25) direction = "SE";
      else if (146.25 <= deg && deg < 168.75) direction = "SSE";
      else if (168.75 <= deg && deg < 191.25) direction = "S";
      else if (191.25 <= deg && deg < 213.75) direction = "SSW";
      else if (213.75 <= deg && deg < 236.25) direction = "SW";
      else if (236.25 <= deg && deg < 258.75) direction = "WSW";
      else if (258.75 <= deg && deg < 281.25) direction = "W";
      else if (281.25 <= deg && deg < 303.75) direction = "WNW";
      else if (303.75 <= deg && deg < 326.25) direction = "NW";
      else if (326.25 <= deg && deg < 348.75) direction = "NNW";
      results += "</div>";
      results += "</div>";
      results += "</div>";
      results += "<div class='todayGrid'>";
      results += "<div>";
      results += "<p>Feels Like: " + Math.round(json.main.feels_like) + " &deg;F<br>";
      results += "Today's Low: " + Math.round(json.main.temp_min) + " &deg;F<br>";
      results += "Today's High: " + Math.round(json.main.temp_max) + " &deg;F</p>";
      results += "</div>";
      results += "<div>";
      results += "<p>Humidity: " + Math.round(json.main.humidity) + "%</p>";
      results += "<p>Wind Speed: " + Math.round(json.wind.speed) + "mph " + direction + "</p>";
      results += "</div>";
      results += "</div>";
      document.getElementById("weatherResults").innerHTML = results;
    });

  const url2 = "https://api.openweathermap.org/data/2.5/forecast?q=" + value + ", US&units=imperial" + "&APPID=" + appid;
  fetch(url2)
    .then(function(response) {
      return response.json();
    }).then(function(json) {
      let forecast = "";
      for (let i=0; i < 40; i++) {
        let currentDay = moment(json.list[i].dt_txt).format('MMMM Do YYYY');
        forecast += "<h2 class='date'>" + moment(json.list[i].dt_txt).format('MMMM Do YYYY') + "</h2>";
        forecast += '<div class="dailyWeather">';
        while (moment(json.list[i].dt_txt).format('MMMM Do YYYY') == currentDay) {
          let direction = "N";
          let deg = json.list[i].wind.deg % 360;
          let day = "n";
          let time = moment(json.list[i].dt_txt).format('H');
          if (3 < time && time < 21) day = "d";
          forecast += `<div class='hourlyWeather' style='background-image: url("images/` + json.list[i].weather[0].icon.slice(0, 2) + day + `.jpg");'>`;
          forecast += "<div class='hourlyWeatherInfo'>";
          forecast += "<h3>" + moment(json.list[i].dt_txt).format('h:mm:ss a') + "</h3>";
          forecast += '<img src="http://openweathermap.org/img/w/' + json.list[i].weather[0].icon.slice(0, 2) + day + '.png"/>'
          forecast += "<p>" + json.list[i].weather[0].description + "</p>";
          forecast += "<p>" + Math.round(json.list[i].main.temp) + "&deg;F</p>";
          forecast += "<p> Precipitation: " + Math.round(json.list[i].pop * 100) + "%";
          if (deg >= 348.75 || deg < 11.25) direction = "N";
          else if (11.25 <= deg && deg < 33.75) direction = "NNE";
          else if (33.75 <= deg && deg < 56.25) direction = "NE";
          else if (56.25 <= deg && deg < 78.75) direction = "ENE";
          else if (78.75 <= deg && deg < 101.25) direction = "E";
          else if (101.25 <= deg && deg < 123.75) direction = "ESE";
          else if (123.75 <= deg && deg < 146.25) direction = "SE";
          else if (146.25 <= deg && deg < 168.75) direction = "SSE";
          else if (168.75 <= deg && deg < 191.25) direction = "S";
          else if (191.25 <= deg && deg < 213.75) direction = "SSW";
          else if (213.75 <= deg && deg < 236.25) direction = "SW";
          else if (236.25 <= deg && deg < 258.75) direction = "WSW";
          else if (258.75 <= deg && deg < 281.25) direction = "W";
          else if (281.25 <= deg && deg < 303.75) direction = "WNW";
          else if (303.75 <= deg && deg < 326.25) direction = "NW";
          else if (326.25 <= deg && deg < 348.75) direction = "NNW";
          forecast += "<p>" + Math.round(json.list[i].wind.speed) + "mph " + direction + "</p>";
          forecast += "</div>";
          forecast += "</div>";
          i++;
          if (i == 40) break;
        }
        if (i == 40) break;
        i--;
        forecast += "</div>";
      }
      document.getElementById("forecastResults").innerHTML = forecast;
    });
});
