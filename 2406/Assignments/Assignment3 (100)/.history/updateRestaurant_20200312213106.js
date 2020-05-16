let name = document.getElementById("name");
let minOrder = document.getElementById("min");
let deliveryFee = document.getElementById("delivery");
let categoryName = document.getElementById("category");
let categoryButton = document.getElementById("categorybutton");
let itemName = document.getElementById("itemname");
let itemDescription = document.getElementById("itemdescription");
let itemPrice = document.getElementById("itemprice");
let itemButton = document.getElementById("additembutton");
let save = document.getElementById("save");
let restaurant = {};

save.addEventListener("click", restaurant);

let request = new XMLHttpRequest();
request.onreadystatechange= function(){
    if(this.readyState==4 && this.status==200){
        restaurant = JSON.parse(request.responseText);

    }
}
request.open("GET", "http://localhost:3000/restaurants/:restID");
request.setRequestHeader("Content-Type", "application/json");
request.send();