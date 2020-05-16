// Sends server login information such as username and password

let loginButton = document.getElementById("loginbutton");
loginButton.addEventListener("click", login);

function login(){
    let username = document.getElementById("username").value;
    let password = document.getElementById("password").value;
    let user = {username: username, password: password};

    //Makes POST request
    let request = new XMLHttpRequest();
    request.onreadystatechange= function(){
        if(this.readyState==4 && this.status==200){
            // Once server has finished processing request open page with ID
            // let user = JSON.parse(request.responseText);
            window.location.href = "http://localhost:3000/";
        }
    }
    request.open("POST", "http://localhost:3000/login");
    request.setRequestHeader("Content-Type", "application/json");
    request.send(JSON.stringify(user));
}