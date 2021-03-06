// Required modules
const express = require('express');
const fs = require("fs");
let app = express();


app.set("view engine", "pug");
app.use(express.json())


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

app.get("/", setPage);
app.get("/restaurants", getRestaurants);
app.get("/addrestaurant", addRestaurant);
app.get("/createRestaurant.js", getCreate);
app.get("/updateRestaurant.js", getUpdate);
app.get("/restaurants/:restID", getRestaurantId);
app.post("/restaurants", createRestaurant);
app.put("/restaurants/:restID", updateRestaurant);


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
            res.status(200).render("pages/restaurants", {restaurants: restaurants});
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

function createRestaurant(req, res, next){
    res.format({
        "application/json": function(){
            let restaurant = {};
            restaurant.id = id;
            id++;
            restaurant.name = req.body.name;
            restaurant.delivery_fee = parseInt(req.body.delivery_fee);
            restaurant.min_order= parseInt(req.body.min_order);
            restaurant.menu = {};
            restaurants[restaurant.id] = restaurant;
            restaurantIDs.restaurants.push(restaurants[restaurant.id].id);
            res.status(200).json(restaurant);
        }
    });
}

function getRestaurantId(req, res, next){
    let resid = req.url.split("/");
    res.format({
        "application/json": function(){
            if(restaurantIDs.restaurants.includes(Number(resid[2]))){
                res.status(200).json(restaurants[resid[2]]);
            }else{
                res.status(404).send("Could not find restaurant.");
            }
        },
        "text/html": function(){
            res.status(200).render("pages/restaurantpage");
        }
    });
}

function updateRestaurant(req, res, next){
    let resid = req.url.split("/");
    if(restaurantIDs.restaurants.includes(Number(resid[2]))){
        res.format({
            "application/json": function(){
                restaurants[resid[2]] = req.body;
                res.status(200).send("Restaurant changed saved");
            }
        }); 
    }else{
        res.status(404).send("Could not find restaurant.");
    }
    
}

app.listen(3000);
console.log("Server listening at http://localhost:3000");