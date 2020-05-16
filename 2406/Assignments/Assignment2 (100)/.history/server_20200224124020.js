const http = require('http');
const fs = require("fs");

const server = http.createServer(function (request, response){
	if(request.method === "GET"){
		if(request.url === "/"){
            let aragorn = JSON.parse(fs.readFileSync('aragorn.json', 'utf8'));
            console.log(aragorn);
            let legolas = JSON.parse(fs.readFileSync('legolas.json', 'utf8'));
            console.log(legolas);
            let frodo = JSON.parse(fs.readFileSync('frodo.json', 'utf8'));
            console.log(frodo);
            
            // fs.readFile("/legolas.json", "utf8", function(err, data){
			// 	if(err){
			// 		response.statusCode = 500;
			// 		response.end("Error reading file.");
			// 		return;
            //     }
            //     console.log(JSON.parse(data));
				// response.statusCode = 200;
				// response.setHeader("Content-Type", "application/json");
				// response.end(data);
            //});
            
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