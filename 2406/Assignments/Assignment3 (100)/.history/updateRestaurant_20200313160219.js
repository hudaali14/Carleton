// let name = document.getElementById("name");
// let minOrder = document.getElementById("min");
// let deliveryFee = document.getElementById("delivery");
// let categoryName = document.getElementById("category");
// let categoryButton = document.getElementById("categorybutton");
// let itemName = document.getElementById("itemname");
// let itemDescription = document.getElementById("itemdescription");
// let itemPrice = document.getElementById("itemprice");
// let itemButton = document.getElementById("additembutton");
// let save = document.getElementById("save");
//let restaurant = {};

//save.addEventListener("click", saveRestaurant);

console.log(window.location.href);

let request = new XMLHttpRequest();
request.onreadystatechange= function(){
    if(this.readyState==4 && this.status==200){
        let newRestaurant = JSON.parse(request.responseText);
        updateRes(newRestaurant);
    }
}
request.open("GET", window.location.href);
request.setRequestHeader("Content-Type", "application/json");
request.send();

function updateRes(restaurant){
    let name = document.getElementById("name");
    let pname = document.getElementById("pname");
    let minOrder = document.getElementById("min");
    let deliveryFee = document.getElementById("delivery");
    let categoryName = document.getElementById("category");
    let categoryButton = document.getElementById("categorybutton");
    let d = document.getElementById("dropdown");
    let itemName = document.getElementById("itemname");
    let itemDescription = document.getElementById("itemdescription");
    let itemPrice = document.getElementById("itemprice");
    let itemButton = document.getElementById("additembutton");
    let save = document.getElementById("save");
    
    pname.innerHTML = "Restaurant Name: " + name.value;

    // Gets all menu category
	let menu = Object.keys(restaurant.menu);

	// For each category name
	menu.forEach(element => {

		// Create category name and link then append to category
		let resoptions = document.createElement("option");
		resoptions.id = restaurant.name;
		resoptions.value = restaurant.name;
		resoptions.text = restaurant.name;
		d.appendChild(resoptions);
    });
    
}

//{restaurant: restaurants[resid[2]]}

