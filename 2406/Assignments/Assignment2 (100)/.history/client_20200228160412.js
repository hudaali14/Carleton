let restaurantName = [];
restaurant = {};

// Array to hold items ordered
let order = [];

function init(){

	let r = document.getElementById("dropdown");

	requestRestaurantNames();

	requestRestaurant();

	// Holds option in drop down menu
	let index = 0;

	// Once the user opens on the drop down menu, the index is saved in case there is an order and they want to switch back
	r.addEventListener("focus", function(){
		index = r.selectedIndex;
	});

	// Calls checkItemsMenu function once drop down menu selection has changed
	r.addEventListener("change", function(){checkItemsMenu(index);});
}

function requestRestaurantNames(){
	let xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function(){
		if(this.readyState == 4 && this.status == 200){
			let names = JSON.parse(xhttp.responseText);
			restaurantName = names;;
			// Adds restaurant names to drop down menu
			let r = document.getElementById("dropdown");
			for(i = 0; i<restaurantName.length; i++){
				let resoptions = document.createElement("option");
				resoptions.id = restaurantName[i];
				str = restaurantName[i];
				resoptions.value = str;
				resoptions.text = str;
				r.appendChild(resoptions);
			}
		}
	}
	xhttp.open("GET", "http://localhost:3000/dropdown");
	xhttp.send();
}

function requestRestaurant(){
	let xhttp = new XMLHttpRequest();
	let dropdownMenu = document.getElementById("dropdown");
	xhttp.onreadystatechange = function(){
		if(this.readyState == 4 && this.status == 200){
			restaurant = JSON.parse(xhttp.responseText);
			displayCategories(restaurant);
		}
	}
	if(dropdownMenu.value == "Aragorn's Orc BBQ"){
		xhttp.open("GET", "http://localhost:3000/restaurant?aragorn");
	}else if(dropdownMenu.value == "Lembas by Legolas"){
		xhttp.open("GET", "http://localhost:3000/restaurant?legolas");
	}else{
		xhttp.open("GET", "http://localhost:3000/restaurant?frodo");
	}
	xhttp.send();
}

function requestRestaurantInfo(){
	let xhttp = new XMLHttpRequest();
	let dropdownMenu = document.getElementById("dropdown");
	xhttp.onreadystatechange = function(){
		if(this.readyState == 4 && this.status == 200){
			restaurant = JSON.parse(xhttp.responseText);
			displayOrder(restaurant);
		}
	}
	if(dropdownMenu.value == "Aragorn's Orc BBQ"){
		xhttp.open("GET", "http://localhost:3000/restaurant?aragorn");
	}else if(dropdownMenu.value == "Lembas by Legolas"){
		xhttp.open("GET", "http://localhost:3000/restaurant?legolas");
	}else{
		xhttp.open("GET", "http://localhost:3000/restaurant?frodo");
	}
	xhttp.send();
}

function requestSubmitOrder(){
	let xhttp = new XMLHttpRequest();
	let dropdownMenu = document.getElementById("dropdown");
	xhttp.onreadystatechange = function(){
		if(this.readyState == 4 && this.status == 200){
			submitOrder();
		}
	}
	xhttp.open("POST", "http://localhost:3000/order");
	xhttp.send(JSON.stringify({name: dropdownMenu.value, order: order}));
}


// Handles when the user selects a different restuarant and there are items in cart
function checkItemsMenu(index){

	// If there's nothing that added to the cart then just display the categories
	if(order.length == 0){
		requestRestaurant();
	}else{

		//Checks whether they want to clear order
		if(confirm("There is a current order with items in it. Do you want to clear the order?")){
			
			// If they do, clears order and displays categories for new option chosen
			order = [];
			requestRestaurant();
		}else{

			// Else uses the saved index from before to stay on the current option with items in cart
			let dropdownMenu = document.getElementById("dropdown");
			dropdownMenu.selectedIndex = index;
		}
	}
}

// Displays the restaurant name, min order, and delivery charge
function displayRestaurant(restaurant){
	let requirements = document.getElementById("requirements");
	requirements.innerHTML="";
	let para = document.createElement("p");
	para.innerHTML += restaurant.name + "<br/>";
	para.innerHTML += "MMINIMUM ORDER PRICE: $" + restaurant.min_order + "<br/>";
	para.innerHTML += "DELIVERY CHARGE: $" + restaurant.delivery_fee;
	requirements.appendChild(para);
}

//Displays restaurant categories
function displayCategories(restaurant){

	// Clears main page
	let main = document.getElementById("main");
	main.innerHTML = "";

	//Clears old things category
	let category = document.getElementById("categories");
	category.innerHTML = "";
	let categoryBox = document.createElement("div");
	categoryBox.innerHTML = "";
	categoryBox.className = "categoryBox";

	displayRestaurant(restaurant);

	// Gets all menu category
	let menu = Object.keys(restaurant.menu);

	// For each category name
	menu.forEach(element => {

		// Create category name and link then append to category 
		let para = document.createElement("a");
		para.innerHTML = element + "<br/>";
		let txt = "#" + element;
		para.href = txt;
		para.className = "links";
		categoryBox.appendChild(para);
	});
	category.appendChild(categoryBox);
	// Display items and order
	displayItems(restaurant, menu);
	requestRestaurantInfo();
}

// Display items 
function displayItems(restaurant, restaurantMenu){

	// Clears item menu page
	let itemMenu = document.getElementById("items");
	itemMenu.innerHTML = "";
	let counter = 0;

	//For each category
  	for(let i = 0; i < restaurantMenu.length; i++){
		// Creates category title and appends to itemMenu
		let category = document.createElement("h3");
		category.innerHTML = restaurantMenu[i] + "<br/>";
		category.id = restaurantMenu[i];
		category.className = "categoryName";
		itemMenu.appendChild(category);

		// Gets each item in a category until it reaches an undefined, which means we've reached the end
    	while(typeof restaurant.menu[restaurantMenu[i]][counter] !== "undefined"){
			// For each item in the category creates elements and appends them
			let item = restaurant.menu[restaurantMenu[i]][counter];
			let para = document.createElement("p");
			let image = document.createElement("img");
			let categoryItem = document.createElement("div");
			categoryItem.className = "categoryItems";
			image.className = "image";
			image.src = "https://www.pinclipart.com/picdir/big/356-3569045_download-png-plus-sign-clipart-png-transparent-png.png";
			// Adds an event listener so when image is clicked calls Add function
			image.addEventListener("click", function(){addItem(item.name, item.price);});
			para.innerHTML += "Name: " + item.name + "<br/>";
			para.innerHTML += "Description: " + item.description + "<br/>";
			para.innerHTML += "Price: $" + item.price + "<br/>";
			categoryItem.appendChild(para);
			categoryItem.appendChild(image);
			itemMenu.appendChild(categoryItem);
      		counter++;
		}
  	}
}

// Adds item to cart
function addItem(name, price){
	let itemAdded = {};
	// If item is not already in the order add it
	if(checkItemsAdded(name)==false){
		itemAdded.name = name;
		itemAdded.price = price;
		itemAdded.amount = 1;
		order.push(itemAdded);

	// If item is in order then increase amount
	}else{
		let index = order.findIndex(element => element.name === name);
		if(typeof index !== "undefined"){
			order[index].amount += 1;
		}
	}
	// Display new order with item added
	requestRestaurantInfo();
}

// Remove item from order
function removeItem(name){
	let index = order.findIndex(element => element.name === name);
	if(typeof index !== "undefined"){
		order[index].amount -= 1;
		if(order[index].amount == 0){
			order.splice(index, 1);
		}
	}
	// Display new order with item removed
	requestRestaurantInfo();
}


// Displays item in order
function displayOrder(restaurant){

	// Gets drop down Menu and div where order is going to display
	let itemsOrdered = document.getElementById("itemsOrdered");

	// Creates submit button and disables it for now
	let submit = document.createElement("button");
	submit.type = "submit";
	submit.id = "submit";
	submit.disabled = "disabled";
	submit.innerHTML = "Submit Order";

	// Event listener for when button is clicked
	submit.addEventListener("click", requestSubmitOrder());

	// Holds the subtotal, delivery fee, tax, and total
	let totalPrice = document.createElement("p");
	itemsOrdered.innerHTML = "";
	totalPrice.id = "totalPrice";
	let subtotal = 0;

	// For each item in order
	order.forEach(element =>{

		// Creates paragraph for text and remove image 
		let para = document.createElement("p");
		let image = document.createElement("img");
		let categoryItem = document.createElement("div");
		categoryItem.className = "categoryItems";
		image.className = "image";
		image.src = "https://image.flaticon.com/icons/svg/25/25232.svg";

		// Adds event listener to remove img so if it's clicked removeItem function is called
		image.addEventListener("click", function(){removeItem(element.name);});

		// Writes item, amount, and total price
		para.innerHTML += element.name + "<br/>";
		para.innerHTML += "Amount: " + element.amount + "<br/>";
		let totalUnitPriceRounded = Math.round((element.amount* element.price) * 100) / 100;
		para.innerHTML += "Total price :$" + totalUnitPriceRounded;
		subtotal += totalUnitPriceRounded;

		// Appends text and remove image to a div then appends that div to the itemsOrdered div
		categoryItem.appendChild(para);
		categoryItem.appendChild(image);
		itemsOrdered.appendChild(categoryItem);
	});
	
	let minimumOrderRounded = Math.round((restaurant.min_order) * 100) / 100;
	let subtotalRounded = Math.round(subtotal * 100) / 100;
	let amountLeftRounded = Math.round((minimumOrderRounded - subtotalRounded) * 100) / 100;

	// If they've passed the minimum order then allow the submit button to be pressed
	if(amountLeftRounded <= 0){
		submit.disabled = false;

	// Else print how much should be added to pass minimum order amount
	}else{
		totalPrice.innerHTML += "You must add $" + amountLeftRounded + " more to your order before submitting" + "<br/>";
	}

	// Calculate tax and total, then prints and appends all the necessary information, such as subtotal, delivery, tax, and total
	let taxRounded = Math.round(subtotalRounded * 0.1 * 100) / 100;
	let deliveryPrice = restaurant.delivery_fee;
	let totalRounded = Math.round(subtotal + taxRounded + deliveryPrice * 100) / 100;
	totalPrice.innerHTML += "CURRENT SUBTOTAL: $" + subtotalRounded + "<br/>";
	totalPrice.innerHTML += "Delivery Fee: $" + deliveryPrice + "<br/>";
	totalPrice.innerHTML += "Tax: $" + taxRounded + "<br/>";
	totalPrice.innerHTML += "TOTAL: $" + totalRounded + "<br/>";
	itemsOrdered.appendChild(totalPrice);
	itemsOrdered.appendChild(submit);
}

// Check if item is already in order 
function checkItemsAdded(name){
	// Flag to check if item has been found
	flag = false;

	// If there's nothing in order then an item can't be in it
	if(order.length == 0){
		return false;
	}else{
		// Gets all the names for comparison
		let itemNames = order.map(element => element.name);

		// For each item name
		itemNames.forEach(element => {
			//If element is already in order then raise flag
			if(name == element){
				flag = true;
			}
		});

		// If flag been raised then it's been found so return true
		if(flag == true){
			return true;
		}else{
			return false;
		}
	}
}


// Clears everything on the page excpet the header
function clearPage(){
	let itemsOrdered = document.getElementById("itemsOrdered");
	itemsOrdered.innerHTML = "";
	let itemMenu = document.getElementById("items");
	itemMenu.innerHTML = "";
	let category=document.getElementById("categories");
	category.innerHTML="";
	let requirements = document.getElementById("requirements");
	requirements.innerHTML="";
}

// Submits order
function submitOrder(){

	// Returns to main page
	let dropdownMenu=document.getElementById("dropdown");
	dropdownMenu.selectedIndex = 0;

	clearPage();
	requestRestaurant();


	// Clears order and alerts the customer that there order is on its way.
	order = [];
	alert("Order has been submitted");
	return;
}