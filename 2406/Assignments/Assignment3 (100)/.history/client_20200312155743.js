let submit = document.getElementById("submitbutton");

submit.addEventListener("click", restaurantInfo);

function restaurantInfo(){
    let name = document.getElementById("restaurantname").value;
    let delivery = document.getElementById("deliveryfee").value;
    let minimum = document.getElementById("minimumorder").value;

    let restaurant = {name: name, delivery_fee: delivery, min_order: minimum};
    console.log(restaurant);

    let request = new XMLHttpRequest();
    request.onreadystatechange= function(){
        if(this.readyState==4 && this.status==200){
            let newRestaurant = JSON.parse(request.responseText);
            window.location.href = "http://localhost:3000/restaurants"+
        }
    }
    request.open("POST", "http://localhost:3000/restaurants");
    request.setRequestHeader("Content-Type", "application/json");
    request.send(JSON.stringify(restaurant));

}