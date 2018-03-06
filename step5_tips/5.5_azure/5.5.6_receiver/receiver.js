'use strict';

const EventHubClient = require('azure-event-hubs').Client;
const connectionString = '';
let client = EventHubClient.fromConnectionString(connectionString);

const printError = (err) => {console.log(err.message)};
const printMessage = (message) => {console.log(`Message received: ${JSON.stringify(message.body)}`)};

//レシーバの登録
const main = async () => {
    let partitionIds = await client.open().then(client.getPartitionIds.bind(client));
    for(let partitionId of partitionIds){
        const receiver = await client.createReceiver('$Default', partitionId, { 'startAfterTime' : Date.now()})
        console.log(`Created partition receiver: ${partitionId}`);
        receiver.on('errorReceived', printError);
        receiver.on('message', printMessage);
    }
}

main().catch(err=> {
    console.error(err);
    console.error("エラーでたっぽい");
});