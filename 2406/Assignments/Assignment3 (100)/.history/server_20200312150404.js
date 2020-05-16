const express = require('express');
const fs = require("fs");
let app = express();

app.set("view engine", "pug");

let restaurants = [];
let restaurantNames = {names: []};
let restaurantIDs = {restaurants: []};

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
            restaurantNames.names.push({name: restaurants[filename].name, id: restaurants[filename].id});
            restaurantIDs.restaurants.push(restaurants[filename].id);
		});
    });
});

app.get("/", setPage);
app.get("/restaurants", getRestaurants);
app.get("/addrestaurant", addRestaurant);
app.get("client.js", getClient);
app.post("/restaurant", createRestaurant);


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
            res.status(200).render("pages/restaurants", {restaurantNames: restaurantNames.names});
        },
        "application/json": function(){
            res.status(200).json(restaurantIDs);
        }
    });
}

function addRestaurant(req, res, next){
    res.format({
        "text/html": function(){
            res.status(200).render("pages/addrestaurant");
        }
    });
}

function getClient(req, res, next){
    fs.readFile("client.js", function(err, data){
        if(err){
            res.statusCode = 500;
            res.end("Error reading file.");
            return;
        }
        res.status(200).send(data);
        return;
    });
}

function createRestaurant(){
    res.status(200);
}

app.listen(3000);
console.log("Server listening at http://localhost:3000");