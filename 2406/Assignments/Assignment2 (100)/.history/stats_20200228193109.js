// Array to hold items ordered
let orders = [];

// Holds Restaurant Names
let restaurantName = [];

// Holds Stats Data
let restaurantData = [];


// On intitalization
function init(){
	requestStatsInfo();
}

//
function requestStatsInfo(){
	let xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function(){
		if(this.readyState == 4 && this.status == 200){
			let stats = JSON.parse(xhttp.responseText);
			
		}
	}
	xhttp.open("GET", "http://localhost:3000/stats?info");
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
		res.averagediv = Math.round((res.average/res.order) * 100) / 100;
	});

	let xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function(){
		if(this.readyState == 4 && this.status == 200){
		}
	}
	xhttp.open("POST", "http://localhost:3000/stats");
	xhttp.send(JSON.stringify(restaurantData));

}

