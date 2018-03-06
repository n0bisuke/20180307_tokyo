'use strict';

const mqtt = require('mqtt');
const client = mqtt.connect('mqtt://localhost');

client.on('connect', () => console.log('publisher.connected.'));

setInterval(() => {
    const message = Date.now().toString();
    client.publish('n0bisuke', message);
    console.log('publisher.publish:', message);
}, 1000);