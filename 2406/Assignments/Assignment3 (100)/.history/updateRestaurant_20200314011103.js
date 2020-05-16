// Gets elements that are going to be reused throughout code
let categoryButton = document.getElementById("categorybutton");
let itemButton = document.getElementById("additembutton");
let name = document.getElementById("name");
let id = document.getElementById("idres");
let minOrder = document.getElementById("min");
let deliveryFee = document.getElementById("delivery");
let save = document.getElementById("save");
let d = document.getElementById("dropdown");
let restaurant = {};

// Sends request to get restaurant data
let request = new XMLHttpRequest();
request.onreadystatechange= function(){
    if(this.readyState==4 && this.status==200){
        // Once request has been made update page
        restaurant = JSON.parse(request.responseText);
        updateRes();
    }
}
request.open("GET", window.location.href);
request.setRequestHeader("Content-Type", "application/json");
request.send();

// Updates restaurant page
function updateRes(){
    
    // Updates id, name, delivery, and min order text boxes with restaurant data
    id.innerHTML = "Restaurant ID: " + restaurant.id;
    name.value = restaurant.name;
    deliveryFee.value = restaurant.delivery_fee;
    minOrder.value = restaurant.min_order;

    // Gets all menu category
    let menu = restaurant.menu;
    // Erases old content
    d.innerHTML = "";

	// For each category name
	Object.keys(menu).forEach(element => {

		// Create category name and add to dropdown
		let resoptions = document.createElement("option");
		resoptions.id = element;
		resoptions.value = element;
		resoptions.text = element;
		d.appendChild(resoptions);
    });

    // Displays menu with category, id, name, price, and description
    let result = "";
    Object.keys(menu).forEach(key =>{
		result += key.bold() + "<br><br>";
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

// Once category button is clicked, add item to restauarant menu category then update page
categoryButton.addEventListener("click", function(){
    let categoryName = document.getElementById("category");
    if(restaurant.menu.hasOwnProperty(categoryName.value)){
        alert("Category already exists. Please enter another");
    }else{
        restaurant.menu[categoryName.value] = {}; 
    }
    categoryName.value = "";
    updateRes();
});

// Once item button is clicked, add item to restaurant menu items then update page
itemButton.addEventListener("click", function(){
    let itemName = document.getElementById("itemname");
    let itemDescription = document.getElementById("itemdescription");
    let itemPrice = document.getElementById("itemprice");
    nextId = 0;
    
    // Find available closes ID
    Object.keys(restaurant.menu[d.value]).forEach(id => {
        nextId= id;
    });
    let menu = restaurant.menu;
    let newMenu = {}; // New menu

    // If new category that is empty is being added to
    if(nextId == 0){
        let saveId = 0;
        Object.keys(menu).forEach(key =>{
            Object.keys(menu[key]).forEach(id => {
                saveId = id
            });
        }); 
        nextId = saveId;
    }else{
    // For each item in menu
    Object.keys(menu).forEach(key =>{
        newMenu[key] = {}; // Adds category to new menu
		Object.keys(menu[key]).forEach(id => {
            // If ID was before our spot and we just save it to our new menu
            if(Number(id) <= nextId){
                console.log("not updating: " + id);
                console.log(menu[key][id]);
                newMenu[key][id] = menu[key][id]; 
            // Else ID is larger then our spot then we must shift the ID numbers and add to new menu
            }else{
                console.log("not updating: " + id);
                console.log(menu[key][id]);
                let newId = Number(id)+1;
                newMenu[key][newId] = menu[key][id];
            }
		});
    });        
    }

    // Saves new item with id to new menu and saves that menu as the restaurant menu
    nextId++;
    newMenu[d.value][nextId] = {name: itemName.value, description: itemDescription.value, price: itemPrice.value};
    restaurant.menu = newMenu;
    itemName.value = "";
    itemDescription.value = "";
    itemPrice.value = "";
    updateRes();
});

// Once save button is clicked, save all information then send new restaurant info to server
save.addEventListener("click", function(){
    restaurant.name = name.value;
    restaurant.delivery_fee = deliveryFee.value;
    restaurant.min_order = minOrder.value;
    let request = new XMLHttpRequest();
    request.onreadystatechange= function(){
        if(this.readyState==4 && this.status==200){
            alert("Your changes have been saved");
        }
    }
    request.open("PUT", window.location.href);
    request.setRequestHeader("Content-Type", "application/json");
    request.send(JSON.stringify(restaurant));
});