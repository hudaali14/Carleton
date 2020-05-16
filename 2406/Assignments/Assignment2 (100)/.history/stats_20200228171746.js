// Array to hold items ordered
let orders = [];

let restaurantName = [];

let restaurantData = [];

function init(){
	requestRestaurantNames();
	requestOrder();

}

function requestRestaurantNames(){
	let xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function(){
		if(this.readyState == 4 && this.status == 200){
			let names = JSON.parse(xhttp.responseText);
			restaurantName = names;
			restaurantName.forEach(elem =>{
				restaurantData.push({name:elem, order: 0, average: 0, popular : {amount:0}})
			});
			//console.log(restaurantData);
			
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
			calculate();
		}
	}
	xhttp.open("GET", "http://localhost:3000/stats?orders");
	xhttp.send();
}

function calculate(){
	orders.forEach(elem =>{
		let res = {};
		restaurantData.forEach(element =>{
			if(elem.name === element.name){
				res = element;
			}
		});
		if(res != {}){
			res.order++;
			res.average += Math.round((elem.total) * 100) / 100;
			elem.order.forEach(element =>{
				if(element.amount > res.popular.amount){
					res.popular = element;
				}
			});
		}
	});

	let xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function(){
		if(this.readyState == 4 && this.status == 200){
		}
	}
	xhttp.open("POST", "http://localhost:3000/stats?load");
	xhttp.send(JSON.stringify(restaurantData));

}

