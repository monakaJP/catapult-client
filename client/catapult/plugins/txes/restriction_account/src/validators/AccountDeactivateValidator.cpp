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

#include "Validators.h"
#include "AccountRestrictionView.h"
#include "src/cache/AccountRestrictionCache.h"
#include "catapult/model/Address.h"
#include "catapult/validators/ValidatorContext.h"

namespace catapult { namespace validators {

	using Notification = model::TransactionNotification;

	// auto strippedRestrictionFlags = state::AccountRestrictionDescriptor(restrictionFlags).restrictionFlags();
	DEFINE_STATEFUL_VALIDATOR(AccountDeactivate, [](const Notification& notification,const ValidatorContext& context) {
		constexpr auto Restriction_Flags = model::AccountRestrictionFlags::Deactivate;
		// auto strippedRestrictionFlags = state::AccountRestrictionDescriptor(Restriction_Flags).restrictionFlags();
		AccountRestrictionView view(context.Cache);
		CATAPULT_LOG(info) << "Deactivate validation....";
		// const auto& address = notification.Sender;
		// const auto& cache = context.Cache.sub<cache::AccountRestrictionCache>();
		// if (!cache.contains(address))
		// 	return ValidationResult::Success;

		// auto restrictionsIter = cache.find(address);
		// const auto& restrictions = restrictionsIter.get();
		// auto restrictionFlags = notification.AccountRestrictionDescriptor.directionalRestrictionFlags();
		// const auto& restriction = restrictions.restriction(Restriction_Flags);
		// auto strippedRestrictionFlags = state::AccountRestrictionDescriptor(restrictionFlags).restrictionFlags();
		if (!view.initialize(notification.Sender))
			return ValidationResult::Success;
		// auto isTransferAllowed = view.isAllowed(Restriction_Flags, notification.TransactionType);
		auto isDeactivated = HasFlag(model::AccountRestrictionFlags::Deactivate, view.get(Restriction_Flags).descriptor().raw());
		// auto isDeactivated = restriction.contains(Restriction_Flags);
		// auto isDeactivated = strippedRestrictionFlags == state::AccountRestrictions:Deactivate
		// get sender flags
		if (!isDeactivated)
			CATAPULT_LOG(info) << "validation success";
		if (isDeactivated)
			CATAPULT_LOG(info) << "DeactivatedAddress....";
		return isDeactivated ? Failure_RestrictionAccount_Account_Deactivated : ValidationResult::Success;
	})

}}

