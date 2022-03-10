const express = require('express');
const cors = require('cors');
const path = require('path');
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
app.post('/', (req, res) => {
    res.json({
        time_left: 5
    });
});

const PORT = 5252;
app.listen(PORT, () => {
    console.log(`Server started on port: ${PORT}`);
})