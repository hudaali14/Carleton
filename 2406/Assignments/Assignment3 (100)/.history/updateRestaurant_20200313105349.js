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

//save.addEventListener("click", restaurant);

console.log(window.location.href);

let request = new XMLHttpRequest();
request.onreadystatechange= function(){
    if(this.readyState==4 && this.status==200){
        //let newRestaurant = JSON.parse(request.responseText);
        //console.log(newRestaurant);
        console.log(request.responseText);
    }
}
request.open("GET", window.location.href);
request.setRequestHeader("Content-Type", "application/json");
request.send();


// h1 Restaurant Info
// p#idres Restaurant ID: 
// | Restaurant Name: 
// input(type= "text", id="name", value = restaurant.name) 
// br
// br
// | Restaurant Min Order: 
// input(type= "text", id="min", value = restaurant.min_order) 
// br
// br
// | Delivery Fee: 
// input(type= "text", id="delivery", value = restaurant.delivery_fee) 
// br
// br

// h1 Add Category: 
// br
// | Category Name: 
// input(type= "text", id="category") 
// br

// button(type="button", id="categorybutton") Add Category


// h1 Add Item: 
// br
// | Select Category: 
// - let menu = Object.keys(restaurant.menu);
// select
//     each category in menu
//         option=category
// br
// | Item Name: 
// input(type= "text", id="itemname") 
// br
// | Item Description: 
// input(type= "text", id="itemdescription") 
// br
// | Item Price: 
// input(type= "text", id="itemprice") 
// br
// button(type="button", id="additembutton") Add Item
// br
// br

// h1 Menu

// each category in menu
//     h4 #{category}
//     - let items = Object.keys(restaurant.menu[category])
//     each id in items
//         - let item = restaurant.menu[category][id];
//         | Name: 
//         p #{item.name}
//         | Description: 
//         p #{item.description}
//         | Price: 
//         p #{item.price}

// button(type="button", id="save") Save