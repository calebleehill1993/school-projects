const url = "https://quote-garden.herokuapp.com/api/v2/quotes/random";
fetch(url)
  .then(function(response) {
    return response.json();
  }).then(function(json) {
    newQuote = '<p>"' + json.quote.quoteText + '"</p>';
    newQuote += "<p>- " + json.quote.quoteAuthor + " -</p>";
    document.getElementById("quote").innerHTML = newQuote;
  });
document.getElementById("getQuote").addEventListener("click", function(event) {
  event.preventDefault();
  const url = "https://quote-garden.herokuapp.com/api/v2/quotes/random";
  fetch(url)
    .then(function(response) {
      return response.json();
    }).then(function(json) {
      newQuote = '<p>"' + json.quote.quoteText + '"</p>';
      newQuote += "<p>- " + json.quote.quoteAuthor + " -</p>";
      document.getElementById("quote").innerHTML = newQuote;
    });
});
