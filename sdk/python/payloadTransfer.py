import argparse
import importlib
from abc import abstractmethod
from binascii import hexlify, unhexlify
import datetime
import requests
import json
import time


from symbolchain.CryptoTypes import PrivateKey
from symbolchain.facade.NemFacade import NemFacade
from symbolchain.facade.SymbolFacade import SymbolFacade
from symbolchain.NetworkTimestamp import NetworkTimestamp, NetworkTimestampDatetimeConverter
proxies = {
    'http' : 'http://proxy.cc.yamaguchi-u.ac.jp:8080/',
    'https' : 'http://proxy.cc.yamaguchi-u.ac.jp:8080/',
}

node = "http://20.222.234.16:3000/transactions"
nd = "http://20.222.234.16:3000"
facade = SymbolFacade('bootstrap')
keypair = facade.KeyPair(PrivateKey(unhexlify('F8CF068C8E7475BA8CF6505350FAEF671524C919289AAEF8DACCE5E0396F1E34')))
# keypair = facade.KeyPair(PrivateKey(unhexlify('F1CF068C8E7475BA8CF6505350FAEF671524C919289AAEF8DACCE5E0396F1E34')))
keypair = facade.KeyPair(PrivateKey(unhexlify('F2CF068C8E7475BA8CF6505350FAEF671524C919289AAEF8DACCE5E0396F1E34')))

# print(facade.network.datetimeConverter(datetime.datetime.now()))
deadline = int(facade.network.from_datetime(datetime.datetime.now(datetime.timezone.utc)).timestamp)+60*60*5
print(deadline)
# key TCVFT32ZPW3A33C34NIQDWTREC5U65CS7BIRJMQ
print(facade.network.from_datetime(datetime.datetime.now(datetime.timezone.utc)))
rest = {
    'type': 'transfer_transaction_v1',
    'recipient_address': 'TCVFT32ZPW3A33C34NIQDWTREC5U65CS7BIRJMQ',
    'message': 'Wayne Gretzky',
    'signer_public_key': keypair.public_key,
    'fee': 0,
    'deadline': deadline,
    }
rest = {
    'type': 'account_deactivate_transaction_v1',
    'restriction_flags': 'account_deactivate',
    'signer_public_key': keypair.public_key,
    'fee': 0,
    'deadline': deadline,
    'restriction_additions':['transfer']
    }
tx = facade.transaction_factory.create(rest)
signature = facade.sign_transaction(keypair, tx)
stx = facade.transaction_factory.attach_signature(tx,signature)
print(f'Hash: {facade.hash_transaction(tx)}\n')
# print(facade.hash_transaction(tx).bytes)
txhash = hexlify(facade.hash_transaction(tx).bytes).decode("utf8").upper()
print(nd+"/transactionStatus/"+txhash)
print(stx)

headers={
    "Content-type": "application/json",
}
r = requests.put(node, params=json.loads(stx), headers=headers, proxies=proxies)
# r = requests.put(node, params=json.loads(stx), headers=headers)
print(r.status_code)
print(r.text)
time.sleep(1)
status = requests.get(nd+"/transactionStatus/"+txhash)
print(status.status_code)
print(status.text)

