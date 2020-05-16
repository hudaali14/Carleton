const http = require('http');
const pug = require("pug");
const fs = require("fs");

let restaurants = [];
let restaurantNames = {names: []};
let orders = [];

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
			restaurants[filename] = JSON.parse(content);
			restaurantNames.names.push(restaurants[filename].name);
		});
    });
});

const renderHome = pug.compileFile('views/pages/home.pug');
const renderOrder = pug.compileFile("views/pages/order.pug");
const renderStats = pug.compileFile("views/pages/stats.pug");


const server = http.createServer(function (request, response){
	if(request.method === "GET"){
        if(request.url === "/order.html" || request.url === "/"){
			let data = renderHome({});
			response.statusCode = 200;
			response.end(data);
			return;
		}else if(request.url === "/orderpage"){
			let content = renderOrder({});
			response.statusCode = 200;
			response.end(content);
			return;
		}else if(request.url === "/stats"){
			let content = renderStats({orders});
			response.statusCode = 200;
			response.end(content);
			return;
		}else if(request.url === "/client.js"){
			fs.readFile("client.js", function(err, data){
				if(err){
					response.statusCode = 500;
					response.end("Error reading file.");
					return;
				}
				response.statusCode = 200;
				response.end(data);
				return;
			});
		}else if(request.url === "/stats.js"){
			fs.readFile("stats.js", function(err, data){
				if(err){
					response.statusCode = 500;
					response.end("Error reading file.");
					return;
				}
				response.statusCode = 200;
				response.end(data);
				return;
			});
		}else if(request.url === "/style.css"){
			fs.readFile('style.css',function(err,data){
				if(err){
					response.statusCode = 500;
					response.end("Error reading file.");
					return;
				}
                response.writeHead(200,{"Content-Type": "text/css"});
                response.end(data);
            });
		}else if(request.url === "/dropdown"){
			response.writeHead(200, { 'content-type': "application/json" });
			response.end(JSON.stringify(restaurantNames.names));
		}else if(request.url == "/restaurant?aragorn"){
			response.writeHead(200, { 'content-type': "application/json" });
			response.end(JSON.stringify(restaurants["aragorn.json"]));
		}else if(request.url === "/restaurant?legolas"){
			response.writeHead(200, { 'content-type': "application/json" });
			response.end(JSON.stringify(restaurants["legolas.json"]));
		}else if(request.url === "/restaurant?frodo"){
			response.writeHead(200, { 'content-type': "application/json" });
			response.end(JSON.stringify(restaurants["frodo.json"]));
		}else if(request.url === "/stats?orders"){
			response.writeHead(200, { 'content-type': "application/json" });
			response.end(JSON.stringify(orders));
		}else{
			response.statusCode = 404;
			response.end("Unknown resource.");
		}
    }else if(request.method === "POST"){
		if(request.url === "/order"){
			let body = ""
			request.on('data', (chunk) => {
				body += chunk;
			})
			request.on('end', () =>{
				let order = JSON.parse(body);
				orders.push(order);
				response.statusCode = 200;
				response.end();
				return;
			})
		}else{
			response.statusCode = 404;
			response.end("Unknown resource.");
		}
	}else{
		response.statusCode = 404;
		response.end("Unknown resource.");
	}
});

server.listen(3000);
console.log('Server running at http://127.0.0.1:3000/');


// Display the front page
// function displayMainPage(){
// 	let main = document.getElementById("main");
// 	main.innerHTML = "";
// 	clearPage();
// 	let welcome = document.createElement("h2");
// 	welcome.innerHTML += "WELCOME TO YOU WANT FOOD NOW?" + "<br/>";
// 	welcome.id = "welcome";
// 	main.appendChild(welcome);
// 	let intro = document.createElement("h4");
// 	intro.id = "intro";
// 	intro.innerHTML += "The EXTREMELY FAST Fast Food Service. We delivery at the SPEED OF LIGHT! ";
// 	intro.innerHTML += "We delivery BEFORE you even click submit! ";
// 	intro.innerHTML += "We delivery before you even CONSIDER ordering! ";
// 	intro.innerHTML += "WE'RE JUST THAT FAST! ";
// 	intro.innerHTML += "You're delivery is probably ON IT'S WAY NOW! ";
// 	intro.innerHTML += "So PLEASE place your order! We promise you WON'T regret it! :D"+ "<br/>" + "<br/>" + "<br/>";
// 	intro.innerHTML += "These are REAL PICTURES of food made at OUR RESTAURANT CHAINS. Don't they look DELICOUS?? ORDER NOW AND YOU CAN HAVE THESE!";
// 	main.appendChild(intro);
// 	let image1 = document.createElement("img");
// 	image1.src = "https://s3.amazonaws.com/pas-wordpress-media/content/uploads/2019/10/24135155/Fast-Food-Restaurant-Sample-Business-Plan-1-min.jpg";
// 	let image2 = document.createElement("img");
// 	image2.src = "https://qaynarinfo.az/file/pic/xeber/2017-10-19/194692.jpg";
// 	let image3 = document.createElement("img");
// 	image3.src = "https://coachellavalley.com/wp-content/uploads/2019/11/48507368-fast-food-and-unhealthy-eating-concept-close-up-of-hamburger-or-cheeseburger-deep-fried-squid-rings--890x395_c.jpg";
// 	main.appendChild(image1);
// 	main.appendChild(image2);
// 	main.appendChild(image3);

// }

// #header{
//     margin: auto;
//     padding: 20px;
//     width: 985px;
//     text-align: center;
//     border: 13px solid lightsteelblue;
//     border-radius: 5px;
//     background-color: skyblue;
//     color: black;
//     text-shadow: 1px 1px 2px grey;
//     font-family: fantasy;
// }