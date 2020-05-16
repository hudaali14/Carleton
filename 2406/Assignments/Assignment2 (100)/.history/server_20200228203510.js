const http = require('http');
const pug = require("pug");
const fs = require("fs");

let restaurants = [];
let restaurantNames = {names: []};
let orders = [];
let statsinfo = [];

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
			statsinfo.push({name:restaurants[filename].name, order: 0, average: 0, popular : {name: "N/A", amount:0}, averagediv: 0});
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
			let content = renderStats({statsinfo});
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
		}else if(request.url === "/stats?info"){
			response.writeHead(200, { 'content-type': "application/json" });
			response.end(JSON.stringify(statsinfo));
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
				console.log("Order");
				console.log(orders);
				calculate();
				response.statusCode = 200;
				response.end();
				return;
			})
		}else if(request.url === "/stats"){
			let body = ""
			request.on('data', (chunk) => {
				body += chunk;
			})
			request.on('end', () =>{
				statsinfo = JSON.parse(body);
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



function calculate(){
	// orders.forEach(elem =>{
	// 	// console.log("Each order:");
	// 	// console.log(elem);
	// 	let res = {};
	// 	statsinfo.forEach(element =>{
	// 		if(elem.name === element.name){
	// 			res = element;
	// 		}
	// 	});
	// 	if(res != {}){
	// 		res.order++;
	// 		res.average += Math.round((elem.total) * 100) / 100;
	// 		elem.order.forEach(element =>{
	// 			if(element.amount > res.popular.amount){
	// 				res.popular = element;
	// 			}
	// 		});
	// 	}
	// 	res.averagediv = Math.round((res.average/res.order) * 100) / 100;
	// 	console.log(res);
	// });

	
	let item = {};
	if(typeof orders.length === "undefined"){
		item = orders[0];
	}
	item = orders[orders.length];
	console.log(item);
	let res = {};
	statsinfo.forEach(element =>{
		if(item.name === element.name){
			res = element;
		}
	});
	if(res != {}){
		res.order++;
		res.average += Math.round((item.total) * 100) / 100;
		item.order.forEach(element =>{
			if(element.amount > res.popular.amount){
				res.popular = element;
			}
		});
	}
	res.averagediv = Math.round((res.average/res.order) * 100) / 100;
	console.log(res);

}


