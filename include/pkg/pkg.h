#pragma once

void printHelloWorld();

void printNumber( int number );

int getFibonacci( int n );

// TODO:
// Register singleton service
// Register transient service
// Resolve services in runtime

#include <typeinfo>
#include <typeindex>
#include <map>
#include <iostream>
#include <functional>
#include <cmath>
struct ServiceDefinition
{
	std::type_info const& type_info;
	std::type_index type_index;
	std::function<void* ( )> factory;
};

static std::map<std::type_index, ServiceDefinition> services;

template<class TInterface, class TImplementation, typename... TArgs>
void RegisterService( TArgs... args )
{
	static_assert( std::is_base_of<TInterface, TImplementation>::value, "TImplementation must be derived from T" );
	const auto& typeInterface = typeid( TInterface );
	auto factory = [=]() -> TInterface* { return new TImplementation( args... ); };
	services.emplace( std::type_index( typeInterface ), ServiceDefinition{ typeInterface, typeInterface, factory } );
}

template<class TInterface>
TInterface* GetService()
{
	const auto& typeInterface = typeid( TInterface );
	auto serviceDefinition = services.find( std::type_index( typeInterface ) );
	if ( serviceDefinition == services.end() )
	{
		return nullptr;
	}
	else
	{
		return static_cast<TInterface*>( serviceDefinition->second.factory() );
	}
}

class IPowerOfTwoGenerator
{
public:
	virtual int value() = 0;
};

class PowerOfTwoGenerator : public IPowerOfTwoGenerator
{
public:
	int value() override
	{
		return 2;
	}
};

class IPowerOfThreeGenerator
{
public:
	virtual int value() = 0;
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
