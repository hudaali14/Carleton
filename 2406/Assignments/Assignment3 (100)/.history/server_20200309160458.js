const express = require('express');
let app = express();

app.set("view engine", "pug");

app.get("/", setPage);

function setPage(req, res, next){
    res.render(home);
}