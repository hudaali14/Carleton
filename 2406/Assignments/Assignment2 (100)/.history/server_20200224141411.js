const http = require('http');
const fs = require("fs");

// function onFileContent(filename, content){
//     let data=fs.readFileSync(filename, 'utf8');
//     let words=JSON.parse(data);
// }

function readFiles(restaurants, onFileContent, onError) {
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
                //onFileContent(filename, content);
            });
        });
    });
}


const server = http.createServer(function (request, response){
	if(request.method === "GET"){
		if(request.url === "/"){
            let data = {};
            readFiles('/restaurants', function(filename, content) {
                data[filename] = content;
            }, function(err) {
                response.statusCode = 500;
                response.end("Error reading file.");
                return;
            });
	
            console.log(data);
            // console.log(data[1]);
            // console.log(data[2]);
            response.statusCode = 200;
            response.setHeader("Content-Type", "application/json");
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