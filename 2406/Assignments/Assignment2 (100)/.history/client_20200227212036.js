let restaurantName = [];
restaurant = {};

// Array to hold items ordered
let order = [];

function init(){

	let r = document.getElementById("dropdown");

	requestRestaurantNames();

	// Displays main page
	displayMainPage();

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

function requestCategories(){
	let xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function(){
		if(this.readyState == 4 && this.status == 200){
			console.log(JSON.parse(xhttp.responseText));
		}
	}
	xhttp.open("GET", "http://localhost:3000/categories");
	xhttp.send();
}


// Handles when the user selects a different restuarant and there are items in cart
function checkItemsMenu(index){

	// If there's nothing that added to the cart then just display the categories
	if(order.length == 0){
		displayCategories();
	}else{

		//Checks whether they want to clear order
		if(confirm("There is a current order with items in it. Do you want to clear the order?")){
			
			// If they do, clears order and displays categories for new option chosen
			order = [];
			displayCategories();
		}else{

			// Else uses the saved index from before to stay on the current option with items in cart
			let dropdownMenu = document.getElementById("dropdown");
			dropdownMenu.selectedIndex = index;
		}
	}
}


// Display the front page
function displayMainPage(){
	let main = document.getElementById("main");
	main.innerHTML = "";
	clearPage();
	let welcome = document.createElement("h2");
	welcome.innerHTML += "WELCOME TO YOU WANT FOOD NOW?" + "<br/>";
	welcome.id = "welcome";
	main.appendChild(welcome);
	let intro = document.createElement("h4");
	intro.id = "intro";
	intro.innerHTML += "The EXTREMELY FAST Fast Food Service. We delivery at the SPEED OF LIGHT! ";
	intro.innerHTML += "We delivery BEFORE you even click submit! ";
	intro.innerHTML += "We delivery before you even CONSIDER ordering! ";
	intro.innerHTML += "WE'RE JUST THAT FAST! ";
	intro.innerHTML += "You're delivery is probably ON IT'S WAY NOW! ";
	intro.innerHTML += "So PLEASE place your order! We promise you WON'T regret it! :D"+ "<br/>" + "<br/>" + "<br/>";
	intro.innerHTML += "These are REAL PICTURES of food made at OUR RESTAURANT CHAINS. Don't they look DELICOUS?? ORDER NOW AND YOU CAN HAVE THESE!";
	main.appendChild(intro);
	let image1 = document.createElement("img");
	image1.src = "https://s3.amazonaws.com/pas-wordpress-media/content/uploads/2019/10/24135155/Fast-Food-Restaurant-Sample-Business-Plan-1-min.jpg";
	let image2 = document.createElement("img");
	image2.src = "https://qaynarinfo.az/file/pic/xeber/2017-10-19/194692.jpg";
	let image3 = document.createElement("img");
	image3.src = "https://coachellavalley.com/wp-content/uploads/2019/11/48507368-fast-food-and-unhealthy-eating-concept-close-up-of-hamburger-or-cheeseburger-deep-fried-squid-rings--890x395_c.jpg";
	main.appendChild(image1);
	main.appendChild(image2);
	main.appendChild(image3);

}

// Displays the restaurant name, min order, and delivery charge
function displayRestaurant(index){
	let requirements = document.getElementById("requirements");
	requirements.innerHTML="";
	let para = document.createElement("p");
	para.innerHTML += restaurants[index].name + "<br/>";
	para.innerHTML += "MMINIMUM ORDER PRICE: $" + restaurants[index].min_order + "<br/>";
	para.innerHTML += "DELIVERY CHARGE: $" + restaurants[index].delivery_charge;
	requirements.appendChild(para);
}

//Displays restaurant categories
function displayCategories(){

	// Clears main page
	let main = document.getElementById("main");
	main.innerHTML = "";
	let dropdownMenu = document.getElementById("dropdown");

	//Clears old things category
	let category = document.getElementById("categories");
	category.innerHTML = "";
	let categoryBox = document.createElement("div");
	categoryBox.innerHTML = "";
	categoryBox.className = "categoryBox";

	// For each drop down menu option
	if(dropdownMenu.selectedIndex == 1){
		displayRestaurant(dropdownMenu.selectedIndex - 1);

		// Gets all menu category
		let aragornMenu = Object.keys(aragorn.menu);

		// For each category name
		aragornMenu.forEach(element => {

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
		displayItems(aragorn, aragornMenu);
		displayOrder();
	}else if(dropdownMenu.selectedIndex == 2){
		displayRestaurant(dropdownMenu.selectedIndex - 1);
		let legolasMenu = Object.keys(legolas.menu);
		legolasMenu.forEach(element => {
			let txt = "#"+element;
			let para = document.createElement("a");
			para.innerHTML = element + "<br/>";
			para.href = txt;
			para.className = "links";
			categoryBox.appendChild(para);
		});
		category.appendChild(categoryBox);
		displayItems(legolas, legolasMenu);
		displayOrder();
	}else if(dropdownMenu.selectedIndex == 3){
		displayRestaurant(dropdownMenu.selectedIndex - 1);
		let frodoMenu = Object.keys(frodo.menu);
		frodoMenu.forEach(element => {
			let txt = "#"+element;
			let para = document.createElement("a");
			para.innerHTML = element + "<br/>";
			para.href = txt;
			para.className = "links";
			categoryBox.appendChild(para);
		});
		category.appendChild(categoryBox);
		displayItems(frodo, frodoMenu);
		displayOrder();
	}else{

		// If main page is chosen go back to that
		displayMainPage();
	}
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
	displayOrder();
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
	displayOrder();
}

// Displays item in order
function displayOrder(){

	// Gets drop down Menu and div where order is going to display
	let itemsOrdered = document.getElementById("itemsOrdered");
	let dropdownMenu=document.getElementById("dropdown");
	let index = dropdownMenu.selectedIndex;

	// Creates submit button and disables it for now
	let submit = document.createElement("button");
	submit.type = "submit";
	submit.id = "submit";
	submit.disabled = "disabled";
	submit.innerHTML = "Submit Order";

	// Event listener for when button is clicked
	submit.addEventListener("click", submitOrder);

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
	
	let minimumOrderRounded = Math.round((restaurants[index-1].min_order) * 100) / 100;
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
	let deliveryPrice = restaurants[index-1].delivery_charge;
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

	// Clears rest of page and goes back to main page
	clearPage();
	displayMainPage();

	// Clears order and alerts the customer that there order is on its way.
	order = [];
	alert("Order has been submitted");
	return;
}