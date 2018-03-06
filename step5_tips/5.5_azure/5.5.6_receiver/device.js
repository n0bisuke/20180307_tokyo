'use strict';

const clientFromConnectionString = require('azure-iot-device-mqtt').clientFromConnectionString;
const Message = require('azure-iot-device').Message;
const connectionString = '';

const client = clientFromConnectionString(connectionString);

const printResultFor = (op) => {
    return (err, res) => {
        if (err) console.log(`${op} error: ${err.toString()}`);
        if (res) console.log(`${op} status: ${res.constructor.name}`);
    };
}

const connectCallback = (err) => {
    if (err) {
        console.log('Could not connect: ' + err);
        return;
    }
    console.log('Client connected');    
    // Create a message and send it to the IoT Hub every second
    setInterval(() => {
        const temperature = 20 + (Math.random() * 15);
        const humidity = 60 + (Math.random() * 20);            
        const data = JSON.stringify({
            deviceId: 'myFirstNodeDevice',
            temperature: temperature,
            humidity: humidity
        });
        const message = new Message(data);
        message.properties.add('temperatureAlert', (temperature > 30) ? 'true' : 'false');
        console.log(`Sending message: ${message.getData()}`);
        client.sendEvent(message, printResultFor('send'));
    }, 1000);
};

client.open(connectCallback);