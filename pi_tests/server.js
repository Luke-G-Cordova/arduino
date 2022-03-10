const express = require('express');
const cors = require('cors');
const path = require('path');
var time = 0;
// var Gpio = require('onoff').Gpio;
// var relay = new Gpio(4, 'out');

const corsInit = {
    origin: 'http://localhost:5252',
    optionsSuccessStatus: 200,
    credentials: true,
    methods: ['GET', 'POST', 'PUT', 'DELETE'],
};
const app = express();
app.use(cors(corsInit));
app.use(express.json());
app.use('/', express.static(__dirname + '/public'))

app.get('/', (req, res) => {
    res.sendFile('./public/index.html');
});
app.post('/', timeout, (req, res) => {
    
    // rotate motor to open door here
    time = 5;
    res.json({
        time_left: time
    });
    setTimeout(() => {
        time = 0;
        // rotate motor to close door here
    }, 5000);
});

const PORT = 5252;
app.listen(PORT, () => {
    console.log(`Server started on port: ${PORT}`);
});

function timeout(req, res, next) {
    if(time===0){
        next();
    }
}