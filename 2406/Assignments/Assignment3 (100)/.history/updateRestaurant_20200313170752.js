// let categoryButton = document.getElementById("categorybutton");
// let itemName = document.getElementById("itemname");
// let itemDescription = document.getElementById("itemdescription");
// let itemPrice = document.getElementById("itemprice");
// let itemButton = document.getElementById("additembutton");
let name = document.getElementById("name");
let save = document.getElementById("save");
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
    let categoryName = document.getElementById("category");
    let d = document.getElementById("dropdown");

    id.innerHTML += restaurant.id;
    name.value = restaurant.name;
    deliveryFee.value = restaurant.delivery_fee;
    minOrder.value = restaurant.min_order;


    // Gets all menu category
    let menu = restaurant.menu;
    //console.log(menu);

	// For each category name
	Object.keys(menu).forEach(element => {

		// Create category name and link then append to category
		let resoptions = document.createElement("option");
		resoptions.id = element;
		resoptions.value = element;
		resoptions.text = element;
		d.appendChild(resoptions);
    });

    Object.keys(menu).forEach(key =>{
        let result = "";
		result += "<b>${key}</b><br>";
		//For each menu item in the category
		Object.keys(menu[key]).forEach(id => {
			item = menu[key][id];
			result += "Item Name: ${item.name} <br> Item Price: (\$${item.price})<br>";
			result += item.description + "<br>";
		});
	});
    
}

//{restaurant: restaurants[resid[2]]}

