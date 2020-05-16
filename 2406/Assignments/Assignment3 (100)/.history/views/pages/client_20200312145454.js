let submit = document.getElementById("submitbutton");

submit.addEventListener("click", restaurantInfo);

function restaturantInfo(){
    let name = document.getElementById("restaurantname").value;
    let delivery = document.getElementById("deliveryfee").value;
    let minimum = document.getElementById("minimumorder").value;

    let restaurant = {name: name, deliver: delivery, minimum: minimum};

    let request = new XMLHttpRequest();
    request.onreadystatechange= function(){
        if(this.readyState==4 && this.status==200){

        }
    }

    request.open("POST", "http://")



}