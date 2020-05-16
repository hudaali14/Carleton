const express = require('express');
let app = express();

app.set("view engine", "pug");

app.get("/", setPage);


function setPage(req, res, next){
    res.format({
        'text/html': function(){
            res.status(200).render("pages/home");
        }
    });
}

app.listen(3000);
console.log("Server listening at http://localhost:3000");