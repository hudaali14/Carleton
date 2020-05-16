// Create express app
const express = require('express');
const fs = require("fs");
const session = require('express-session');
const ObjectID = require('mongodb').ObjectID;
let mongo = require('mongodb');

// Database and express variables
let app = express();
let MongoClient = mongo.MongoClient;
let db;


// require module, pass it the session module
const MongoDBStore = require('connect-mongodb-session')(session);
// Create the new mongo store, using the database we have been
// using already, and the collection sessiondata
const store = new MongoDBStore({
    uri: 'mongodb://localhost:27017/tokens',
    collection: 'sessiondata'
});

//View engine
app.set("view engine", "pug");

// Use the session middleware
// Set the store property in the options
app.use(session({secret: 'some secret here', store: store}));

app.use(express.static("public"));
app.use(express.json());
app.use(express.urlencoded({extended: true}));

// Loading Javascript and CSS files
app.get("/login.js", getLoginJS);
app.get("/register.js", getRegisterJS);
app.get("/user.js", getUserJS);
app.get("/client.js", getOrderJS);
app.get("/style.css", getStyle);           

//Server requests
app.get("/", main);
app.get("/register", register);
app.get("/users", queryParser);
app.get("/users", loadUsers);
app.get("/users/:userID", profile);
app.get("/orders", order);
app.get("/orders/:orderID", orderpage);
app.get("/logout", logout);
app.post("/login", login);
app.post("/register", registerUser);
app.post("/orders", savingOrders);
app.put("/users/:userID", changePrivacy);

//Loads home page
function main(req, res, next){
    res.status(200).render("pages/home", {"session": req.session});
}

// Loads register page
function register(req, res, next){
    res.status(200).render("pages/register", {"session": req.session});
}


//Parse the query parameters
//limit: integer specifying maximum number of results to send back
//page: the page of results to send back (start is (page-1)*limit)
//name: string to find in user names to be considered a match
function queryParser(req, res, next){
	const MAX_USERS = 50;
	
	//build a query string to use for pagination later
	let params = [];
	for(prop in req.query){
		if(prop == "page"){
			continue;
		}
		params.push(prop + "=" + req.query[prop]);
	}
	req.qstring = params.join("&");
	
	try{
		req.query.limit = req.query.limit || 10;
		req.query.limit = Number(req.query.limit);
		if(req.query.limit > MAX_USERS){ 
			req.query.limit = MAX_USERS;
		}
	}catch{
		req.query.limit = 10;
	}
	
	try{
		req.query.page = req.query.page || 1;
		req.query.page = Number(req.query.page);
		if(req.query.page < 1){
			req.query.page = 1;
		}
	}catch{
		req.query.page = 1;
	}
	
	if(!req.query.name){
		req.query.name = "?";
	}
	
	next();
}

//Loads the correct set of users based on the query parameters
function loadUsers(req, res, next){
    // If parameter isn't specifies then loads all usernames
    if(req.query.name === "?"){
        users = db.collection("users").find({}).toArray(function(err, result) {
            if(err){
                res.status(500).send("Error reading users.");
                return;
            }
            res.status(200).render("pages/users", {"session": req.session, users: result});
        });
    // Else loads usernames that match query parameter    
    }else{
        db.collection("users").find({ 'username' : {'$regex' : req.query.name, '$options' : 'i' }}).toArray(function(err, result){
            if(err){
                res.status(500).send("Error reading users.");
                return;
            }
            res.status(200).render("pages/users", {"session": req.session, users: result});
        });
    }

}

// Loads user profile
function profile(req, res, next){
    let id = req.params.userID;	
	let oid;
	try{
		oid = new ObjectID(id);
	}catch{
		res.status(404).send("That ID does not exist.");
		return;
    }
    // Finds user with that id
    db.collection("users").findOne({"_id": oid}, function(err, result){
		if(err){
			res.status(500).send("Error reading database.");
			return;
        }
        // If it can't find user with id then that user doesn't exist
		if(!result){
			res.status(404).send("That ID does not exist in the database.");
			return;
        }
        // if user is logged in and then allows user to always view their own profile
		if (req.session.loggedin){
			if (req.session.username === result.username){
				res.render('pages/profile', {profile: result, ownprofile: true, "session": req.session});
				return;
			}
		};
		// if user is trying to access ID that is for a private user, throw 404 error
		if (result.privacy){
			res.status(404).send("Page requested does not exist");
			return;
		}
		// otherwise, display user information
		res.status(200).render("pages/profile", {profile: result, "session": req.session});
	});
}

// Loads orders page only if user is logged in
function order(req, res, next){
    if(req.session.loggedin){
        res.status(200).render("pages/order", {"session": req.session});
    }else{
        res.status(404).send("Unauthorized");
    }
}

// Loads individual order page
function orderpage(req, res, next){
    let orderid = req.params.orderID;	
	let oid;
	try{
		oid = new ObjectID(orderid);
	}catch{
		res.status(404).send("That ID does not exist.");
		return;
    }

    // Finds order matching id specified in URL then loads that page
    db.collection("users").findOne({orders: {$elemMatch: {"id": oid}}}, function(err, result){
        if(err) throw err;

        // If it can't find order with id then that order doesn't exist
		if(!result){
			res.status(404).send("That ID does not exist in the database.");
			return;
        }

        let order = result.orders.find( ({id}) => id == orderid);
    
        // if user is logged in and then allows user to always view their own order
		if (req.session.loggedin){
			if (req.session.username === result.username){
				res.status(200).render("pages/orderpage",  {"session": req.session, username: result.username, order: order});
				return;
			}
        };
        
        // if user is trying to access order that is for a private user, throw 404 error
		if (result.privacy){
			res.status(404).send("Page requested does not exist");
			return;
        }
        
		// otherwise, display order information
        res.status(200).render("pages/orderpage",  {"session": req.session, username: result.username, order: order});
    });
}

// Logs out user and returns to homepage
function logout(req, res, next){
    if(req.session.loggedin){
        req.session.loggedin = false;
        res.redirect("/");
    }else{
        res.status(200).send("You cannot log out because you aren't logged in.");
    }
}

// Registers and adds user to database
function registerUser(req, res, next){
    db.collection("users").findOne({username: req.body.username}, function(err, result){
        if(err) throw err;

        // If user with that username doesn't exists then adds to to database
        if(!result){
            db.collection("users").insertOne({username: req.body.username, password: req.body.password, privacy: false, orders: []}, function(err, result){
                if(err){
                    res.status(500).send("Error saving to database.");
                    return;
                }
                
                // Logs in new user
                let newID = result.insertedId;
                req.session.loggedin = true;
                req.session.username = req.body.username;
                req.session.user_id = newID;
                res.status(200).send(JSON.stringify(newID));
            });
        // User with that id has been taken so throws 409 meaning request could not be completed due to conflict  
        }else{
            res.status(409).send("Sorry that username has been taken");
        }
    });
    
}

// Logs in user
function login(req, res, next){
    if(req.session.loggedin){
        res.status(200).send("Already logged in.");
        return;
    }
    let username = req.body.username;
    let password = req.body.password;
    db.collection("users").findOne({username: username}, function(err, result){
        if(err)throw err;

        if(result){
            if(result.password === password){
                req.session.loggedin = true;
                req.session.username = username;
                req.session.user_id = result._id;
                res.status(200).send("Logged in");
            }else{
                res.status(401).send("Not authorized. Invalid password.");
            }
        }else{
            res.status(401).send("Not authorized. Invalid username.");
            return;
        }
      
    });
}

// Changes user privacy
function changePrivacy(req, res, next){
    let id = req.params.userID;	
	let oid;
	try{
		oid = new ObjectID(id);
	}catch{
		res.status(404).send("That ID does not exist.");
		return;
    }
    // Gets privacy from users
    privacy = JSON.parse(req.body.privacy);

    // Finds user with id specified in URL
    db.collection("users").findOne({"_id": oid}, function(err, result){
        if(err) throw err;
        // if user is logged in and their username equals username of url, allows user to update privacy
        if (req.session.loggedin){
            if (req.session.username === result.username){
                db.collection("users").updateOne({username: result.username}, {$set: {privacy: privacy}}, function(err, result){
                    if(err) throw err;
                });
            }
        };
    });
}

// Saves orders and adds to user orders
function savingOrders(req, res, next){
    //Finds user who's logged in and adds order info to users orders
    db.collection("users").findOne({username: req.session.username}, function(err, result){
        if(err) throw err;
        if(result){
            let order = {	
                placed: req.session.username,
                restuarantID: req.body.id,
                name: req.body.name, 
                fee: req.body.fee,
                order: req.body.order, 
                total: req.body.total,
                subtotal: req.body.subtotal,
                tax: req.body.tax
            };
            // Assigns ID to order
            let id = ObjectID();
            order.id = id
            db.collection("users").findOneAndUpdate({username: result.username},{$push: {orders: order}}, function(err, result){
                if(err) throw err;
            });
            res.status(200).send("Your changes have been saved.");
        }
    });
}


// Reads Javascript file
function getLoginJS(req, res, next){
    fs.readFile("login.js", function(err, data){
        if(err){
            res.statusCode = 500;
            res.end("Error reading file.");
            return;
        }
        res.status(200).send(data);
        return;
    });
}

// Reads Javascript file
function getRegisterJS(req, res, next){
    fs.readFile("register.js", function(err, data){
        if(err){
            res.statusCode = 500;
            res.end("Error reading file.");
            return;
        }
        res.status(200).send(data);
        return;
    });
}

// Reads Javascript file
function getUserJS(req, res, next){
    fs.readFile("user.js", function(err, data){
        if(err){
            res.statusCode = 500;
            res.end("Error reading file.");
            return;
        }
        res.status(200).send(data);
        return;
    });
}

// Reads Javascript file
function getOrderJS(req, res, next){
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

// Reads CSS file
function getStyle(req, res, next){
    fs.readFile('style.css',function(err,data){
        if(err){
            res.statusCode = 500;
            res.end("Error reading file.");
            return;
        }
        res.writeHead(200,{"Content-Type": "text/css"});
        res.end(data);
    });
}

// Initialize database connection
MongoClient.connect("mongodb://localhost:27017/", function(err, client) {
    if(err) throw err;

    db = client.db('a4');

    app.listen(3000);
    console.log("Server listening on port 3000");
});
