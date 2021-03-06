let categoryButton = document.getElementById("categorybutton");
let itemButton = document.getElementById("additembutton");
let name = document.getElementById("name");
let id = document.getElementById("idres");
let minOrder = document.getElementById("min");
let deliveryFee = document.getElementById("delivery");
let save = document.getElementById("save");
let d = document.getElementById("dropdown");
let restaurant = {};

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

    id.innerHTML = "Restaurant ID: " + restaurant.id;
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
            result += "Id: " + id + "<br>";
            result += "Name: " +  item.name + "<br>";
            result += "Price: " + item.price + "<br>";
            result += "Description: " + item.description + "<br>";
            result += "<br>";
		});
    });

    let menuHTML = document.getElementById("menu");
    menuHTML.innerHTML = result;
}

categoryButton.addEventListener("click", function(){
    let categoryName = document.getElementById("category");
    restaurant.menu[categoryName.value] = {}; 
    categoryName.innerHTML = "";
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
    console.log(nextId);
    Object.keys(menu).forEach(key =>{
		Object.keys(menu[key]).forEach(id => {
            if(id >= nextId){
                console.log(id);
                menu[key][id++] = menu[key][id];
                delete menu[key][id];
            }
            
		});
    });
    nextId++;
    restaurant.menu[d.value][nextId]= {name: itemName.value, description: itemDescription.value, price: itemPrice.value};
    itemName.innerHTML = "";
    itemDescription.innerHTML = "";
    itemPrice.innerHTML = "";
    updateRes();
});

save.addEventListener("click", function(){
    restaurant.name = name.value;
    restaurant.delivery_fee = deliveryFee.value;
    restaurant.min_order = minOrder.value;
    let request = new XMLHttpRequest();
    request.onreadystatechange= function(){
        if(this.readyState==4 && this.status==200){
            alert("Your changed have been saved");
        }
    }
    request.open("POST", window.location.href);
    request.setRequestHeader("Content-Type", "application/json");
    console.log(restaurant);
    request.send(JSON.stringify(restaurant));
});