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

	// namespace {
	// 	// constexpr auto Relevant_Entity_Type = model::AccountDeactivateRestrictionTransaction::Deactivate;
	// 	// constexpr auto Deactivate_Flag = model::AccountRestrictionFlags::EntityType;
	// 	constexpr auto Restriction_Flags = model::AccountRestrictionFlags::Deactivate

	// 	bool Validate(const Notification& notification, const ValidatorContext& context) {
	// 		AccountRestrictionView view(context.Cache);
	// 		if (!view.initialize(notification.Sender))
	// 			return ValidationResult::Success;
	// 		return view.isAllowed(Restriction_Flags, notification.Entity_Type);
	// 	}
	// }
	// AccountDeactivateRestriction?
	DEFINE_STATEFUL_VALIDATOR(DeactivateRestriction, [](const Notification& notification,const ValidatorContext& context) {
		constexpr auto Restriction_Flags = model::AccountRestrictionFlags::Deactivate;
		AccountRestrictionView view(context.Cache);
		if (!view.initialize(notification.Sender))
			return ValidationResult::Success;
		
		// auto isDeactivated = view.get(Restriction_Flags);
		auto isDeactivated = HasFlag(Restriction_Flags, view.get(Restriction_Flags).descriptor().raw());
		// get sender flags
		return isDeactivated ? Failure_RestrictionAccount_Account_Deactivated : ValidationResult::Success;
		// return Validate(notification, context) ? 
	})

}}

	// DEFINE_STATEFUL_VALIDATOR(OperationRestriction, [](const Notification& notification, const ValidatorContext& context) {
	// 	constexpr auto Restriction_Flags = model::AccountRestrictionFlags::TransactionType | model::AccountRestrictionFlags::Outgoing;
	// 	AccountRestrictionView view(context.Cache);
	// 	if (!view.initialize(notification.Sender))
	// 		return ValidationResult::Success;

	// 	auto isTransferAllowed = view.isAllowed(Restriction_Flags, notification.TransactionType);
	// 	return isTransferAllowed ? ValidationResult::Success : Failure_RestrictionAccount_Operation_Type_Prohibited;
	// })
