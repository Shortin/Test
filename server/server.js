var express = require('express');

var app = express();

app.use(express.static(".",{"index":"/pages/Page1.html"}));

const ffi = require("ffi-napi");
const UsersData = new ffi.Library("./UsersData", {
    "datausers": [
        "int", ["string"]
    ]
});

const urlencodedParser = express.urlencoded({extended: false});
app.post("/", urlencodedParser, function (request, response) {
    
    if(!request.body) return response.sendStatus(400);
    
    var i = UsersData.datausers(request.body.firstInput);

    if(i==1){
        response.sendFile(__dirname + "/pages/PageYes.html");
    }
    else{
        response.sendFile(__dirname + "/pages/PageNo.html");
    }
});

// запускаем сервер на порту 8080
app.listen(8080);
// отправляем сообщение
console.log('Сервер стартовал на порту 8080!');

