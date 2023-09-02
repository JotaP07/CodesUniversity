var greetingBottom = document.getElementById("GreetingBottom");
var fieldName = document.getElementById("name");
var greeting = document.getElementById("greeting");

function isEnterKey(event) {
    return event.key === "Enter";
}

greetingBottom.addEventListener("click", function () {
    greet();
});

fieldName.addEventListener("keypress", function(event) {
    if (isEnterKey(event)){
        greet();
    }
});

function greet() {
    var name = fieldName.value;

    if (name.trim() === "") {
        alert("Please, enter your name before greeting")
    } else {
        greeting.textContent = "Hello, " + name + "!";
    }
}