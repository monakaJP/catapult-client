// const newXym = require("_build/bundle.mjs");
import {CryptoTypes} from './_build/bundle'
const { sha3_256 } = require('js-sha3');
const request = require('request');
const node = "http://20.222.234.16:3000"
// const node = "http://sym-test-01.opening-line.jp:3000"

const symfacade = new newXym.facade.SymbolFacade("testnet");
const key = new newXym.CryptoTypes.PrivateKey("F8CF068C8E7475BA8CF6505350FAEF671524C919289AAEF8DACCE5E0396F1E34")

const now = Date.now();
const eadj = 1573430400;
const deadline = BigInt(now - eadj*1000 + 60*60*5*1000);//deadlineを導出

const transaction = symfacade.transactionFactory.create({
    type: 'account_deactivate_transaction_v1',
    signerPublicKey: 'CBCBFCD07813A55368AE02E36A8C8D016D50D8DEE5C34BC4D805E8873EC93073',//signerの公開鍵
    fee: 0n,
    deadline: deadline,
});
const signature = symfacade.signTransaction(new facade.SymbolFacade.KeyPair(key), transaction);
const jsonPayload = symfacade.transactionFactory.constructor.attachSignature(transaction, signature);
console.log(jsonPayload);
anounceTX(JSON.parse(jsonPayload).payload);

const payload = stringToUint8Array(JSON.parse(jsonPayload).payload);
const sig = payload.slice(8,8+64);
const pub = payload.slice(8+64,8+64+32)
const gene = stringToUint8Array("E12826238668439FD5689985EAAD4F6246A5F4B9984E224FC6EE99C5C7AFEB09");
const tx = payload.slice(8 + 64 + 32 + 4);
const hasher = sha3_256.create();
hasher.update(sig);
hasher.update(pub);
hasher.update(gene);
hasher.update(tx);
const hash = new Uint8Array(hasher.arrayBuffer())
console.log(node +"/transactionStatus/"+uint8ToString(hash))

function stringToUint8Array(str){
  const buf = Buffer.from(str,"hex");
  return bufferToUint8Array(buf);
}
function bufferToUint8Array(buf) {
  const view = new Uint8Array(buf.length);
  for (let i = 0; i < buf.length; ++i) {
      view[i] = buf[i];
  }
  return view;
}

function uint8ToString(uint8arr){
  return Buffer.from(uint8arr).toString("hex").toUpperCase();
}

function anounceTX(signed){
  console.log(node+"/transactions")
  var options = {
    uri: node+"/transactions",

  json: {
    "payload": signed
  }
  };
  request.put(options, function(error, response, body){
    console.log(body);
  });

}