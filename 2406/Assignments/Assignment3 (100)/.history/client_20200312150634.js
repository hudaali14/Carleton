let submit = document.getElementById("submitbutton");

submit.addEventListener("click", restaurantInfo);

function restaturantInfo(){
    let name = document.getElementById("restaurantname").value;
    let delivery = document.getElementById("deliveryfee").value;
    let minimum = document.getElementById("minimumorder").value;

    let restaurant = {name: name, delivery_fee: delivery, min_order: minimum};
    console.log(restaurant);

    let request = new XMLHttpRequest();
    request.onreadystatechange= function(){
        if(this.readyState==4 && this.status==200){
            request.send(request.responseText);
        }
    }

    request.open("POST", "http://localhost:3000/restaurants")
    request.send(JSON.stringify(restaurant));

}