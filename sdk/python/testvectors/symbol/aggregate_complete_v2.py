from binascii import unhexlify

aggregate_recipes = {
	# comment: two transfers
	'schema_name': 'AggregateCompleteTransactionV2',
	'descriptors': [
		{
			'aggregate': {'type': 'aggregate_complete_transaction_v2'},
			'embedded': [
				{
					'type': 'transfer_transaction_v1',
					'recipient_address': 'TBA6LOHEA6A465G2X5MSQF66JBYR254GJDPK7MQ',
					'mosaics': [],
					'message': 'Hello 👋'
				},
				{
					'type': 'transfer_transaction_v1',
					'recipient_address': 'TCIFSMQZAX3IDPHUP2RTXP26N6BJRNKEBBKP33I',
					'mosaics': [
						{'mosaic_id': 0x000056CE00002B67, 'amount': 0x0000000000000064},
						{'mosaic_id': 0xD525AD41D95FCF29, 'amount': 0x0000000000000001}
					],
					'message': unhexlify('D600000300504C5445000000FBAF93F7')
				}
			],
			'num_cosignatures': 3
		}
	]
}
