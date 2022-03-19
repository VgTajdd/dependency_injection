// ========================================================================= //
// Copyright (c) 2022 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// ClientClass.h                                                             //
// ========================================================================= //

#pragma once

#include "ServicesInterfaces.h"
#include "pkg/DIContainer.h"

class ClientClass
{
public:
	int evaluate( const DIContainer& container )
	{
		const auto& powerOfTwoGenerator{ container.getService<IPowerOfTwoGenerator>() };
		const auto& powerOfThreeGenerator{ container.getService<IPowerOfThreeGenerator>() };
		return powerOfTwoGenerator->value() + powerOfThreeGenerator->value();
	}
};