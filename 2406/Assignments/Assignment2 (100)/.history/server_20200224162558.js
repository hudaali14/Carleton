const http = require('http');
const fs = require("fs");

let data = {};

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
            data[filename] = content;
        });
    });
});


const server = http.createServer(function (request, response){
	if(request.method === "GET"){
        console.log("get");
		if(request.url === "/"){
            response.statusCode = 200;
			response.setHeader("Content-Type", "text/html");
			response.end(data); 
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