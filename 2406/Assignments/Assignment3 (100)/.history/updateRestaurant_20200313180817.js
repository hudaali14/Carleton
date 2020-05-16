let categoryButton = document.getElementById("categorybutton");
let itemButton = document.getElementById("additembutton");
let name = document.getElementById("name");
let save = document.getElementById("save");
let d = document.getElementById("dropdown");
let restaurant = {};

//save.addEventListener("click", saveRestaurant);

console.log(window.location.href);

let request = new XMLHttpRequest();
request.onreadystatechange= function(){
    if(this.readyState==4 && this.status==200){
        restaurant = JSON.parse(request.responseText);
        updateRes();
    }
}
request.open("GET", window.location.href);
request.setRequestHeader("Content-Type", "application/json");
request.send();

function updateRes(){
    let id = document.getElementById("idres");
    let minOrder = document.getElementById("min");
    let deliveryFee = document.getElementById("delivery");

    id.innerHTML = restaurant.id;
    name.value = restaurant.name;
    deliveryFee.value = restaurant.delivery_fee;
    minOrder.value = restaurant.min_order;


    // Gets all menu category
    let menu = restaurant.menu;

    d.innerHTML = "";

	// For each category name
	Object.keys(menu).forEach(element => {

		// Create category name and link then append to category
		let resoptions = document.createElement("option");
		resoptions.id = element;
		resoptions.value = element;
		resoptions.text = element;
		d.appendChild(resoptions);
    });

    let result = "";
    Object.keys(menu).forEach(key =>{
		result += key + "<br><br>";
		//For each menu item in the category
		Object.keys(menu[key]).forEach(id => {
			item = menu[key][id];
            result += "Item Name: "+  item.name + "<br>";
            result += "Item Price: " + item.price + "<br>";
            result += "Item Description: " + item.description + "<br>";
            result += "<br>";
		});
    });

    let menuHTML = document.getElementById("menu");
    menuHTML.innerHTML = result;
}
//{restaurant: restaurants[resid[2]]}

categoryButton.addEventListener("click", function(){
    let categoryName = document.getElementById("category");
    restaurant.menu[categoryName.value] = {}; 
    updateRes();
});

itemButton.addEventListener("click", function(){
    let itemName = document.getElementById("itemname");
    let itemDescription = document.getElementById("itemdescription");
    let itemPrice = document.getElementById("itemprice");
    nextId = 0;
    Object.keys(restaurant.menu[d.value]).forEach(id => {
        nextId= id;
    });
    menu[key][nextId]= {}

    //updateRes();
});