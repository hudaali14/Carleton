// Array to hold items ordered
let orders = [];

let restaurantName = [];

let restaurantData = [];

function init(){
	requestRestaurantNames();
	requestOrder();
	console.log("Stats: " + restaurantData);

}

function requestRestaurantNames(){
	let xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function(){
		if(this.readyState == 4 && this.status == 200){
			let names = JSON.parse(xhttp.responseText);
			restaurantName = names;
			restaurantName.forEach(elem =>{
				restaurantData.push({name:elem, order: "N/A", average: "N/A", popular : "N/A"})
			});
			
		}
	}
	xhttp.open("GET", "http://localhost:3000/dropdown");
	xhttp.send();
}

function requestOrder(){
	let xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function(){
		if(this.readyState == 4 && this.status == 200){
			orders = JSON.parse(xhttp.responseText);
			console.log(orders);
			calculate();
		}
	}
	xhttp.open("GET", "http://localhost:3000/stats?orders");
	xhttp.send();
}

function calculate(){
	orders.forEach(elem =>{
		
	});
}

