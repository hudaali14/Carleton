COMP 2406 - Assignment 4

Huda Ali 101120387

Source Files:
	• server.js
	• login.js
	• register.js
	• user.js
	• client.js
	• package.json
	• package-lock.json
	• views
		• pages
			• home.pug
			• users.pug
			• register.pug
			• profile.pug
			• order.pug
			• orderpage.pug
		• partials
			• header.pug
			• input.pug

Specs:
	• MUST DO FIRST
		• First make sure you are in the correct directory
		• Into the terminal type -> npm install
		• This will install all the external modules needed
	• RUN DATABASE AND MONGO DAEMON
		• First make sure you are in the correct directory
		• Into the terminal type -> node ./database-initializer.js
		• This will initializer all the initial users
		• Add a folder to save all database information on
		• Next into the terminal type -> sudo mongod --dbpath=database
		• "database" is the name of the folder you want to save all the information on
	• To run server
		• First make sure you are in the correct directory
		• Into the terminal type -> node ./server.js
		• The text "Server listening on port 3000" running will appear to let you know the server is running
	• Once server is running into any browser type the URL -> http://localhost:3000/
	• If you wish the close the server hit CTRL-C in the terminal and this will terminate the server
	• Once the client browser is loaded there will be a header that allows you to navigate through each page
