/**
*** Copyright (c) 2016-2019, Jaguar0625, gimre, BloodyRookie, Tech Bureau, Corp.
*** Copyright (c) 2020-present, Jaguar0625, gimre, BloodyRookie.
*** All rights reserved.
***
*** This file is part of Catapult.
***
*** Catapult is free software: you can redistribute it and/or modify
*** it under the terms of the GNU Lesser General Public License as published by
*** the Free Software Foundation, either version 3 of the License, or
*** (at your option) any later version.
***
*** Catapult is distributed in the hope that it will be useful,
*** but WITHOUT ANY WARRANTY; without even the implied warranty of
*** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*** GNU Lesser General Public License for more details.
***
*** You should have received a copy of the GNU Lesser General Public License
*** along with Catapult. If not, see <http://www.gnu.org/licenses/>.
**/

#pragma once
#include "MosaicEntityType.h"
#include "catapult/model/Mosaic.h"
#include "catapult/model/Transaction.h"

namespace catapult { namespace model {

#pragma pack(push, 1)

	/// Binary layout for a mosaic supply revocation transaction body.
	template<typename THeader>
	struct MosaicSupplyRevocationTransactionBody : public THeader {
	private:
		using TransactionType = MosaicSupplyRevocationTransactionBody<THeader>;

	public:
		DEFINE_TRANSACTION_CONSTANTS(Entity_Type_Mosaic_Supply_Revocation, 1)

	public:
		/// Address from which tokens should be revoked.
		UnresolvedAddress SourceAddress;

		/// Revoked mosaic.
		UnresolvedMosaic Mosaic;

	public:
		/// Calculates the real size of a mosaic supply revocation \a transaction.
		static constexpr uint64_t CalculateRealSize(const TransactionType&) noexcept {
			return sizeof(TransactionType);
		}
	};

	DEFINE_EMBEDDABLE_TRANSACTION(MosaicSupplyRevocation)

#pragma pack(pop)
}}
