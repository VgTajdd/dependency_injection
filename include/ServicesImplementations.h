// ========================================================================= //
// Copyright (c) 2022 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// ServicesImplementations.h                                                 //
// ========================================================================= //

#pragma once

#include <cmath>

class PowerOfTwoGenerator : public IPowerOfTwoGenerator
{
public:
	int value() override
	{
		return 2;
	}
};

class PowerOfThreeGenerator : public IPowerOfThreeGenerator
{
public:
	PowerOfThreeGenerator( int power )
	{
		this->power = power;
	}
	int value() override
	{
		return std::pow( 3, this->power );
	}
	int power;
};