let aragorn = {
	name: "Aragorn's Orc BBQ", //The name of the restaurant
	min_order: 20, //The minimum order amount required to place an order
	delivery_charge: 5, //The delivery charge for this restaurant
	//The menu
	menu: {
		//First category
		"Appetizers": {
			//First item of this category
			0: {
				name: "Orc feet",
				description: "Seasoned and grilled over an open flame.", //
				price: 5.50
			},
			1: {
				name: "Pickled Orc fingers",
				description: "Served with warm bread, 5 per order.",
				price: 4.00
			},
			2: { //Thank you Kiratchii
				name: "Sauron's Lava Soup",
				description: "It's just really spicy water.",
				price: 7.50
			},
			3: {
				name: "Eowyn's (In)Famous Stew",
				description: "Bet you can't eat it all.",
				price: 0.50
			},
			4: {
				name: "The 9 rings of men.",
				description: "The finest of onion rings served with 9 different dipping sauces.",
				price: 14.50
			}
		},
		"Combos": {
			5: {
				name: "Buying the Farm",
				description: "An arm and a leg, a side of cheek meat, and a buttered biscuit.",
				price: 15.99
			},
			6: {
				name: "The Black Gate Box",
				description: "Lots of unidentified pieces. Serves 50.",
				price: 65.00
			},
			7: {//Thanks to M_Sabeyon
				name: "Mount Doom Roast Special with Side of Precious Onion Rings.",
				description: "Smeagol's favorite.",
				price: 15.75
			},
			8: { //Thanks Shar[TA]
				name: "Morgoth's Scorched Burgers with Chips",
				description: "Blackened beyond recognition.",
				price: 13.33
				
			},
			9: {
				name: "Slab of Lurtz Meat with Greens.",
				description: "Get it while supplies last.",
				price: 17.50
			},
			10: {
				name: "Rangers Field Feast.",
				description: "Is it chicken? Is it rabbit? Or...",
				price: 5.99
			}
		},
		"Drinks": {
			11: {
				name: "Orc's Blood Mead",
				description: "It's actually raspberries - Orc's blood would be gross.",
				price: 5.99
			},
			12: {
				name: "Gondorian Grenache",
				description: "A fine rose wine.",
				price: 7.99
			},
			13: {
				name: "Mordor Mourvedre",
				description: "A less-fine rose wine.",
				price: 5.99
			}
		}	
	}
};

let legolas = {
	name: "Lembas by Legolas",
	min_order: 15,
	delivery_charge: 3.99,
	menu: {
		"Lembas": {
			0: {
				name: "Single",
				description: "One piece of lembas.",
				price: 3
			},
			1: {
				name: "Double",
				description: "Two pieces of lembas.",
				price: 5.50
			},
			2: { 
				name: "Triple",
				description: "Three pieces, which should be more than enough.",
				price: 8.00
			}
		},
		"Combos": {
			3: {
				name: "Second Breakfast",
				description: "Two pieces of lembas with honey.",
				price: 7.50
			},
			4: {
				name: "There and Back Again",
				description: "All you need for a long journey - 6 pieces of lembas, salted pork, and a flagon of wine.",
				price: 25.99
			},
			5: {
				name: "Best Friends Forever",
				description: "Lembas and a heavy stout.",
				price: 6.60
			}
		}
	}
};

let frodo = {
	name: "Frodo's Flapjacks",
	min_order: 35,
	delivery_charge: 6,
	menu: {
		"Breakfast": {
			0: {
				name: "Hobbit Hash",
				description: "Five flapjacks, potatoes, leeks, garlic, cheese.",
				price: 9.00
			},
			1: {
				name: "The Full Flapjack Breakfast",
				description: "Eight flapjacks, two sausages, 3 eggs, 4 slices of bacon, beans, and a coffee.",
				price: 14.00
			},
			2: { 
				name: "Southfarthing Slammer",
				description: "15 flapjacks and 2 pints of syrup.",
				price: 12.00
			}
			
		},
		"Second Breakfast": {
			3: {
				name: "Beorning Breakfast",
				description: "6 flapjacks smothers in honey.",
				price: 7.50
			},
			4: {
				name: "Shire Strawberry Special",
				description: "6 flapjacks and a hearty serving of strawberry jam.",
				price: 8
			},
			5: {
				name: "Buckland Blackberry Breakfast",
				description: "6 flapjacks covered in fresh blackberries. Served with a large side of sausage.",
				price: 14.99
			}
		},
		"Elevenses": {
			6: {
				name: "Lembas",
				description: "Three pieces of traditional Elvish Waybread",
				price: 7.70
			},
			7: {
				name: "Muffins of the Marish",
				description: "A variety of 8 different types of muffins, served with tea.",
				price: 9.00
			},
			8: {
				name: "Hasty Hobbit Hash",
				description: "Potatoes with onions and cheese. Served with coffee.",
				price: 5.00
			}
		},
		"Luncheon": {
			9: {
				name: "Shepherd's Pie",
				description: "A classic. Includes 3 pies.",
				price: 15.99
			},
			10: {
				name: "Roast Pork",
				description: "An entire pig slow-roasted over a fire.",
				price: 27.99
			},
			11: {
				name: "Fish and Chips",
				description: "Fish - fried. Chips - nice and crispy.",
				price: 5.99
			}
		},
		"Afternoon Tea": {
			12: {
				name: "Tea",
				description: "Served with sugar and cream.",
				price: 3
			},
			13: {
				name: "Coffee",
				description: "Served with sugar and cream.",
				price: 3.50
			},
			14: {
				name: "Cookies and Cream",
				description: "A dozen cookies served with a vat of cream.",
				price: 15.99
			},
			15: {
				name: "Mixed Berry Pie",
				description: "Fresh baked daily.",
				price: 7.00
			}
		},
		"Dinner": {
			16: {
				name: "Po-ta-to Platter",
				description: "Boiled. Mashed. Stuck in a stew.",
				price: 6
			},
			17: {
				name: "Bree and Apple",
				description: "One wheel of brie with slices of apple.",
				price: 7.99
			},
			18: {
				name: "Maggot's Mushroom Mashup",
				description: "It sounds disgusting, but its pretty good",
				price: 6.50
			},
			19: {
				name: "Fresh Baked Bread",
				description: "A whole loaf of the finest bread the Shire has to offer.",
				price: 6
			},
			20: {
				name: "Pint of Ale",
				description: "Yes, it comes in pints.",
				price: 5
			}
		},
		"Supper": {
			21: {
				name: "Sausage Sandwich",
				description: "Six whole sausages served on a loaf of bread. Covered in onions, mushrooms and gravy.",
				price: 15.99
			},
			22: {
				name: "Shire Supper",
				description: "End the day as you started it, with a dozen flapjacks, 5 eggs, 3 sausages, 7 pieces of bacon, and a pint of ale.",
				price: 37.99
			}
		}
	}
};

let restaurants = [aragorn, legolas, frodo];
let order = [];

function init(){
	let r = document.getElementById("dropdown");
	for(i = 0; i<restaurants.length; i++){
		let resoptions = document.createElement("option");
		str = JSON.stringify(restaurants[i].name);
		resoptions.value = str;
		resoptions.text = str;
		r.appendChild(resoptions);
	}
	let category = document.getElementById("categories");
	//r.addEventListener("click", checkItemsMenu);
	r.onchange= displayCategories;
}


function checkItemsMenu(){
	if(order.length > 0){
		if(confirm("There is a current order with items in it. Do you want to clear the order?")){
			order = [];
			return;
		}
	}
}

function displayRestaurant(index){
	let requirements = document.getElementById("requirements");
	requirements.innerHTML="";
	let para = document.createElement("p");
	para.innerHTML += restaurants[index].name + "<br/>";
	para.innerHTML += "Minimum order price: $" + restaurants[index].min_order + "<br/>";
	para.innerHTML += "Delivery Charge: $" + restaurants[index].delivery_charge;
	requirements.appendChild(para);
}


function displayCategories(){
	checkItemsMenu();
	let dropdownMenu=document.getElementById("dropdown");
	let category=document.getElementById("categories");
	category.innerHTML="";
	if(dropdownMenu.selectedIndex==1){
		displayRestaurant(dropdownMenu.selectedIndex-1);
		let aragornMenu= ["Appetizers", "Combos","Drinks"];
		aragornMenu.forEach(element => {
			let txt= "#"+element;
			let para =document.createElement("a");
			para.innerHTML=element+"<br/>";
			para.href=txt;
			category.appendChild(para);
		});
		displayItems(aragorn, aragornMenu);
	}else if(dropdownMenu.selectedIndex==2){
		displayRestaurant(dropdownMenu.selectedIndex-1);
		let legolasMenu=["Lembas", "Combos"];
		legolasMenu.forEach(element => {
			let txt= "#"+element;
			let para =document.createElement("a");
			para.innerHTML=element+"<br/>";
			para.href=txt;
			category.appendChild(para);
		});
		displayItems(legolas, legolasMenu);

	}else if(dropdownMenu.selectedIndex==3){
		displayRestaurant(dropdownMenu.selectedIndex-1);
		let frodoMenu=["Breakfast","Second Breakfast","Elevenses","Luncheon","Afternoon Tea","Dinner","Supper"];
		frodoMenu.forEach(element => {
			let txt= "#"+element;
			let para =document.createElement("a");
			para.innerHTML=element+"<br/>";
			para.href=txt;
			category.appendChild(para);
		});
		displayItems(frodo, frodoMenu);
	}else{
		let x=5;
	}
	displayOrder();
}

function displayItems(restaurant, restaurantMenu){
	let itemMenu = document.getElementById("items");
	itemMenu.innerHTML = "";
	let categoryItems = restaurant.menu;
	let counter = 0;
  	for(let i = 0; i < restaurantMenu.length; i++){
		  let category = document.createElement("h3");
		  category.innerHTML = restaurantMenu[i]+"<br/>";
		  category.id= restaurantMenu[i];
		  category.className="links";
		  itemMenu.appendChild(category);
    	while(typeof restaurant.menu[restaurantMenu[i]][counter] !== "undefined"){
			let item = restaurant.menu[restaurantMenu[i]][counter];
			let para = document.createElement("p");
			let image = document.createElement("img");
			image.id = "image";
			image.src = "https://p7.hiclipart.com/preview/27/906/465/symbol-cross-line-font-add.jpg";
			image.addEventListener("click", function(){addItem(item.name, item.price);});
			para.innerHTML += "Name: " + item.name + "<br/>";
			para.innerHTML += "Description: " + item.description + "<br/>";
			para.innerHTML += "Price: $" + item.price + "<br/>";
			itemMenu.appendChild(para);
			itemMenu.appendChild(image);
      		counter++;
    	}
  	}
}

function addItem(name, price){
	let itemAdded = {};
	if(checkItemsAdded(name)==false){
		itemAdded.name = name;
		itemAdded.price = price;
		itemAdded.amount = 1;
		order.push(itemAdded);
	}else{
		if(typeof order.findIndex(element => element.name === name) !== "undefined"){
			let index = order.findIndex(element => element.name === name);
			order[index].amount += 1;
		}
	}
	displayOrder(); 
	for(let i=0; i>order.length; i++){
		console.log("Name: ", order[i].name);
		console.log("Price: ", order[i].price);
		console.log("Amount: ", order[i].amount);
	}
}

function removeItem(name){
	let index = order.findIndex(element => element.name === name);
	if(typeof index !== "undefined"){
		order[index].amount += 1;
		order[index].amount -= 1;
		if(order[index].amount == 0){
			order.splice(index);
		}
	}
	displayOrder();
	for(let i=0; i>order.length; i++){
		console.log("Name: ", order[i].name);
		console.log("Price: ", order[i].price);
		console.log("Amount: ", order[i].amount);
	}
}

function displayOrder(){
	let itemsOrdered = document.getElementById("itemsOrdered");
	let dropdownMenu=document.getElementById("dropdown");
	let index = dropdownMenu.selectedIndex;
	let submit = document.createElement("button");
	submit.type= "submit";
	submit.disabled = "disabled";
	submit.addEventListener("click", submitOrder);
	itemsOrdered.innerHTML = "";
	let subtotal = 0;
	order.forEach(element =>{
		let para = document.createElement("p");
		let image = document.createElement("img");
		image.id = "image";
		image.src = "https://p7.hiclipart.com/preview/240/807/703/symbol-plus-and-minus-signs-meno-symbol.jpg";
		image.addEventListener("click", function(){removeItem(element.name);});
		para.innerHTML += element.name + "<br/>";
		para.innerHTML += "Amount: " + element.amount + "<br/>";
		let totalUnitPrice = element.amount* element.price;
		let totalUnitPriceRounded = Math.round(totalUnitPrice * 100) / 100;
		para.innerHTML += "Total price :$" + totalUnitPriceRounded;
		subtotal += totalUnitPriceRounded;
		itemsOrdered.appendChild(para);
		itemsOrdered.appendChild(image);
	});
	let minimumOrder = restaurants[index-1].min_order;
	let minimumOrderRounded = Math.round(minimumOrder * 100) / 100;
	let subtotalRounded = Math.round(subtotal * 100) / 100;
	let totalLeft = minimumOrderRounded - subtotalRounded;
	if(totalLeft <= 0){
		submit.disabled = false;
	}
	let tax = subtotalRounded * 0.1;
	let taxRounded = Math.round(tax * 100) / 100;
	let deliveryPrice = restaurants[index-1].delivery_charge;
	let total = subtotal + taxRounded + deliveryPrice;
	let totalRounded = Math.round(total * 100) / 100;
	let totalPrice = document.createElement("p");
	totalPrice.innerHTML += "CURRENT SUBTOTAL: $" + subtotalRounded + "<br/>";
	totalPrice.innerHTML += "Delivery Fee: $" + deliveryPrice + "<br/>";
	totalPrice.innerHTML += "Tax: $" + taxRounded + "<br/>";
	totalPrice.innerHTML += "TOTAL: $" + totalRounded + "<br/>";
	totalPrice.innerHTML += "You must add $" + minimumOrderRounded + "more to your order before submitting";
	itemsOrdered.appendChild(totalPrice);
	itemsOrdered.appendChild(submit);
}

function checkItemsAdded(name){
	flag = false;
	if(order.length == 0){
		return false;
	}else{
		let itemNames = order.map(element => element.name);
		itemNames.forEach(element => {
			if(name == element){
				flag = true;
			}
		});
		if(flag == true){
			return true;
		}else{
			return false;
		}
	}
}

function submitOrder(){
	alert("Order has been submitted");
	let dropdownMenu=document.getElementById("dropdown");
	dropdownMenu.selectedIndex = 1;
	items = [];
	return;
}