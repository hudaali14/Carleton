const express = require('express');
const fs = require("fs");
let app = express();

app.set("view engine", "pug");

let restaurants = [];
let restaurantNames = {names: []};
let restaurantIDs = {"restaurants": []};

//Reads all files in restaurant directory
fs.readdir("./restaurants/", function(err, filenames) {
    if (err) {
        response.statusCode = 500;
        response.end("Error reading file.");
        return;
    }
    filenames.forEach(function(filename) {
        fs.readFile("./restaurants/" + filename, 'utf-8', function(err, content) {
            if (err) {
                response.statusCode = 500;
                response.end("Error reading file.");
                return;
			}
			//Saves files to restaurant array
			restaurants[filename] = JSON.parse(content);
			//Saves names in restuarantNames array
			restaurantNames.names.push(restaurants[filename].name);
			//Saves info on restaurant for stats page so no matter how many restaurants are added we will have a stats page for each one
			statsinfo.push({name:restaurants[filename].name, order: 0, average: 0, popular : {name: "N/A", amount:0}, averagediv: 0});
		});
    });
});

app.get("/", setPage);
app.get(" /restaurants", getRestaurants);




function setPage(req, res, next){
    res.format({
        "text/html": function(){
            res.status(200).render("pages/home");
        }
    });
}

function getRestaurants(req, res, next){
    res.format({
        "text/html": function(){
            res.status(200).render("pages/home");
        }
        "application/json": function(){
            res.statsu(200).json()
        }
    });
}

app.listen(3000);
console.log("Server listening at http://localhost:3000");