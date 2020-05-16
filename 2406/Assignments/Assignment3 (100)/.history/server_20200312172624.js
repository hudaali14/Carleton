const express = require('express');
const fs = require("fs");
let app = express();


app.set("view engine", "pug");
app.use(express.json())

// app.use(bodyParser.json());
// app.use(bodyParser.urlencoded({ extended: true }));

let restaurants = [];
let restaurantNames = {names: []};
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
			//Saves names in restuarantNames array
            restaurantNames.names.push({name: restaurants[res.id].name, id: restaurants[res.id].id});
            restaurantIDs.restaurants.push(restaurants[res.id].id);
            id++;
		});
    });
});

app.get("/", setPage);
app.get("/restaurants", getRestaurants);
app.get("/addrestaurant", addRestaurant);
app.get("/client.js", getClient);
app.get("/restaurants/:restID", getRestaurantId);
app.post("/restaurants", createRestaurant);


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
            res.status(200).json(restaurant);

        }
    });
}

function getRestaurantId(req, res, next){
    let resid = req.url.split("/");
    console.log(resid);
    console.log(restaurants[resid[2]]);
    res.format({
        "text/html": function(){
            console.log(restaurant[resid[2]]);
            res.status(200).render("pages/restaurantpage", {restaurant: restaurants[resid[2]]});
        },
        "application/json": function(){
            res.status(200).json(restaurants[resid[2]]);
        }
    });
}

app.listen(3000);
console.log("Server listening at http://localhost:3000");