'use strict';

const mqtt = require('mqtt');
const client = mqtt.connect({
    host: 'mosquitto.org',
    port: 1883,
});

client.on('connect', () => console.log('subscriber.connected.'));

client.subscribe('n0bisuke', (err, granted) => console.log('subscriber.subscribed.'));

client.on('message', (topic, message) => console.log('subscriber.on.message', 'topic:', topic, 'message:', message.toString()));
