// Array to hold items ordered
let order = [];

let restaurantName = [];

function init(){
	requestRestaurantNames();
}

function requestRestaurantNames(){
	let xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function(){
		if(this.readyState == 4 && this.status == 200){
			let names = JSON.parse(xhttp.responseText);
			restaurantName = names;;
			console.log(restaurantName);
			
		}
	}
	xhttp.open("GET", "http://localhost:3000/dropdown");
	xhttp.send();
}

