// Required modules
const express = require('express');
const fs = require("fs");
let app = express();


app.set("view engine", "pug");
app.use(express.json())

// Restaurant
let restaurants = [];
let restaurantIDs = {restaurants: []};
let id = 0;

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
            let res = JSON.parse(content);
			restaurants[res.id] = res;
			//Saves id to array
            restaurantIDs.restaurants.push(restaurants[res.id].id);
            id++;
		});
    });
});

// Server requests
app.get("/", setPage);                             // Home page
app.get("/restaurants", getRestaurants);           // List of restaurants
app.get("/addrestaurant", addRestaurant);          // Adding restaurant page
app.get("/restaurants/:restID", getRestaurantId);  // Opening specific restaurant page
app.get("/createRestaurant.js", getCreate);        // Loading Javscript file
app.get("/updateRestaurant.js", getUpdate);        // Loading Javscript file
app.post("/restaurants", createRestaurant);        // Adding new restaurant data
app.put("/restaurants/:restID", updateRestaurant); // Updating exisiting restaurant data


// Renders home page
function setPage(req, res, next){
    res.format({
        "text/html": function(){
            res.status(200).render("pages/home");
        }
    });
}


// Sends either HTML or JSON, depending on Accepts header
// If HTML sends page with list of restaurants
// If Javascript sends array with all restaurant IDs
function getRestaurants(req, res, next){
    res.format({
        "text/html": function(){
            res.status(200).render("pages/restaurants", {restaurants: restaurants});
        },
        "application/json": function(){
            res.status(200).json(restaurantIDs);
        }
    });
}

// Renders add restaurant page
// Uses createRestaurant.js for page functionality
function addRestaurant(req, res, next){
    res.format({
        "text/html": function(){
            res.status(200).render("pages/addrestaurant");
        }
    });
}

// Once restaurant has been created, adds new restaurant to array
function createRestaurant(req, res, next){
    res.format({
        "application/json": function(){
            // Created restaurant with new ID
            let restaurant = {};
            restaurant.id = id;
            id++;
            // Saves and verifies restaurant data
            if(req.body.hasOwnProperty("name") && req.body.hasOwnProperty("delivery_fee") && req.body.hasOwnProperty("min_order")){
                restaurant.name = req.body.name;
                restaurant.delivery_fee = parseInt(req.body.delivery_fee);
                restaurant.min_order= parseInt(req.body.min_order);
                restaurant.menu = {};
            // One or more propeties were not entered so send 400 response
            }else{
                res.status(400).send("One or more properties were not entered");
                return;
            }
            
            // Saves restaurant data and sends restaurant with new ID back
            restaurants[restaurant.id] = restaurant;
            restaurantIDs.restaurants.push(restaurants[restaurant.id].id);
            res.status(200).json(restaurant);
        }
    });
}

// Reads Javascript file
function getCreate(req, res, next){
    fs.readFile("createRestaurant.js", function(err, data){
        if(err){
            res.statusCode = 500;
            res.end("Error reading file.");
            return;
        }
        res.status(200).send(data);
        return;
    });
}

// Reads Javascript file
function getUpdate(req, res, next){
    fs.readFile("updateRestaurant.js", function(err, data){
        if(err){
            res.statusCode = 500;
            res.end("Error reading file.");
            return;
        }
        res.status(200).send(data);
        return;
    });
}

//Sends either HTML or JSON, depending on Accepts header
// If JSON sends restaurant data with that ID
// If HTMl renders restaurant page with that ID
function getRestaurantId(req, res, next){
    // Parses URL to get restaurant ID
    let resid = req.url.split("/");
    res.format({
        "application/json": function(){
            // Makes sure restaurant with that ID exists
            if(restaurantIDs.restaurants.includes(Number(resid[2]))){
                res.status(200).json(restaurants[resid[2]]);
            // If not send 404
            }else{
                res.status(404).send("Could not find restaurant.");
            }
        },
        "text/html": function(){
            res.status(200).render("pages/restaurantpage");
        }
    });
}

// Updates restaurant info
function updateRestaurant(req, res, next){
    // Parses URL to get restaurant ID
    let resid = req.url.split("/");
    // Makes sure restaurant with that ID exists if does saves data and then response
    if(restaurantIDs.restaurants.includes(Number(resid[2]))){
        res.format({
            "application/json": function(){
                restaurants[resid[2]] = req.body;
                res.status(200).send("Restaurant changed saved");
            }
        }); 
    // Else sends 404
    }else{
        res.status(404).send("Could not find restaurant.");
    }
    
}

app.listen(3000);
console.log("Server listening at http://localhost:3000");