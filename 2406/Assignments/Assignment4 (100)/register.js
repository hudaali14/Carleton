// Sends server register information such as username and password

let registerButton = document.getElementById("registerbutton");
registerButton.addEventListener("click", register);

function register(){
    let username = document.getElementById("username").value;
    let password = document.getElementById("password").value;
    let user = {username: username, password: password};

    // Makes POST request
    let request = new XMLHttpRequest();
    request.onreadystatechange= function(){
        if(this.readyState==4 && this.status==200){
            // Once server has finished processing request open page with ID
            let newID = JSON.parse(request.responseText);
            window.location.href = "http://localhost:3000/users/" + newID;
        // If username has been taken server sends a 409 status meaning username has been taken    
        }else if(this.readyState==4 && this.status==409){
            alert("Sorry that username has been taken");
        }
    }
    request.open("POST", "http://localhost:3000/register");
    request.setRequestHeader("Content-Type", "application/json");
    request.send(JSON.stringify(user));
}