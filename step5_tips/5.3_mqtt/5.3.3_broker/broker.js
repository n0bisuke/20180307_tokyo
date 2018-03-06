'use strict';

const http = require('http');
const httpServer = http.createServer();

const HTTP_PORT = 3000;
const MQTT_PORT = 1883;

const mosca = require('mosca');
const server = new mosca.Server({port: MQTT_PORT});

server.on('ready', () => console.log('Server is ready.'));
server.on('clientConnected', client => console.log('broker.on.connected.', 'client:', client.id));
server.on('clientDisconnected', client => console.log('broker.on.disconnected.', 'client:', client.id));
server.on('subscribed', (topic, client) => console.log('broker.on.subscribed.', 'client:', client.id, 'topic:', topic));
server.on('unsubscribed', (topic, client) => console.log('broker.on.unsubscribed.', 'client:', client.id));

server.on('published', (packet, client) => {
    if (/\/new\//.test(packet.topic)){
        return;
    }
    if (/\/disconnect\//.test(packet.topic)){
        return;
    }
    console.log('broker.on.published.', 'client:', client.id);
});

server.attachHttpServer(httpServer);
httpServer.listen(HTTP_PORT);

// const ngrok = require('ngrok');
// ngrok.connect(HTTP_PORT, (err, url) => console.log(err, `${HTTP_PORT} -> ${url}`)); //ngrokでトンネリング
// ngrok.connect({proto: 'tcp', addr: MQTT_PORT}, (err, url) => console.log(err, `${MQTT_PORT} -> ${url}`)); //ngrokでトンネリング