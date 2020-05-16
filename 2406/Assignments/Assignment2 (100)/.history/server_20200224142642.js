const http = require('http');
const fs = require("fs");

let data = {};

function readFiles(restaurants, onError) {
    fs.readdir(restaurants, function(err, filenames) {
        if (err) {
            onError(err);
            return;
        }
        filenames.forEach(function(filename) {
            fs.readFile(restaurants + filename, 'utf-8', function(err, content) {
                if (err) {
                    onError(err);
                    return;
                }
                console.log(content);
                data[filename] = content;
            });
        });
    });
}


const server = http.createServer(function (request, response){
	if(request.method === "GET"){
		if(request.url === "/"){
            readFiles("/restaurants", function(err) {
                response.statusCode = 500;
                response.end("abc");
                //console.log("asd" + JSON.stringify(data));
                //response.end(data);
                return;
            });
	
            //console.log(data);
            // console.log(data[1]);
            // console.log(data[2]);
            // response.statusCode = 200;
            // response.setHeader("Content-Type", "application/json");
            // response.end(data);
            
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