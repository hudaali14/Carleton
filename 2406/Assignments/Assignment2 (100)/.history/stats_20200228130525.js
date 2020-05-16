// Array to hold items ordered
let order = [];

let restaurantName = [];

let restaurantData = [];

function init(){
	requestRestaurantNames();
	console.log(restaurantData);

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

