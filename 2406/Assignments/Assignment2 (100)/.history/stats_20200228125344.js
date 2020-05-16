// Array to hold items ordered
let order = [];

let restaurantName = [];

let restaurantData = {aragorn :[], legolas: [], frodo: []};

function init(){
	requestRestaurantNames();
}

function requestRestaurantNames(){
	let xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function(){
		if(this.readyState == 4 && this.status == 200){
			let names = JSON.parse(xhttp.responseText);
			restaurantName = names;
			
		}
	}
	xhttp.open("GET", "http://localhost:3000/dropdown");
	xhttp.send();
}

