// Updates user privacy if they want to change it
let save = document.getElementById("saveButton");
let on = document.getElementById("onButton");
let off = document.getElementById("offButton");

save.addEventListener("click", function(){
    let privacy = {};
    if(on.checked){
        privacy.privacy = true
    }else{
        privacy.privacy = false;
    }

    //Makes PUT request
    let request = new XMLHttpRequest();
    request.onreadystatechange= function(){
        if(this.readyState==4 && this.status==200){
            alert("Your changes have been saved");
        }
    }
    request.open("PUT", window.location.href);
    request.setRequestHeader("Content-Type", "application/json");
    request.send(JSON.stringify(privacy));
});