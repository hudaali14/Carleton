const http = require('http');
const fs = require("fs");

let restaurants = [];
let restaurantNames = {names: []};

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
			restaurants[filename] = content;
			restaurantNames.names.push(restaurantNames[filename].name);
			console.log(restaurantNames.names);
		});
    });
});

//let restaurantNames ={names: [data[0].name, data[1].name, data[2].name]};

const server = http.createServer(function (request, response){
	if(request.method === "GET"){
        if(request.url === "/order.html" || request.url === "/"){
			fs.readFile("order.html", function(err, data){
				if(err){
					response.statusCode = 500;
					response.end("Error reading file.");
					return;
				}
				response.statusCode = 200;
				response.setHeader("Content-Type", "text/html");
				response.end(data);
			});
		}else if(request.url === "/client.js"){
			fs.readFile("client.js", function(err, data){
				if(err){
					response.statusCode = 500;
					response.end("Error reading file.");
					return;
				}
				response.statusCode = 200;
				response.setHeader("Content-Type", "application/javascript");
				response.end(data);
			});
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