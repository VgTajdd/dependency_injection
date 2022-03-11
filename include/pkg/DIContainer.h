#pragma	once

#include <map>
#include <iostream>

#include "ServiceDefinition.h"

/**
 * @brief The DIContainer class is a dependency injection container.
 * It is used to store service definitions and to create service instances.
 */
class DIContainer
{
public:
	explicit DIContainer() = default;
	~DIContainer() = default;

	/**
	 * @brief registerService registers a service definition.
	 * @param type_info the type info of the service.
	 * @param factory the factory function that creates the service.
	 */
	template<class TInterface, class TImplementation, typename... TArgs>
	void registerService( TArgs... args )
	{
		static_assert( std::is_base_of<TInterface, TImplementation>::value, "TImplementation must be derived from T" );
		const auto& typeInterface{ typeid( TInterface ) };
		auto factory{ [=]() -> TInterface* { return new TImplementation( args... ); } };
		services.emplace( std::type_index( typeInterface ), ServiceDefinition{ typeInterface, typeInterface, factory } );
	}

	/**
	 * @brief getService gets a service instance.
	 * @param type_info the type info of the service.
	 * @return a pointer to the service instance.
	 */
	template<class TInterface>
	TInterface* getService() const
	{
		const auto& typeInterface{ typeid( TInterface ) };
		auto serviceDefinition{ services.find( std::type_index( typeInterface ) ) };
		if ( serviceDefinition == services.end() )
		{
			return nullptr;
		}
		else
		{
			return static_cast<TInterface*>( serviceDefinition->second.factory() );
		}
	}

private:
	/**
	 * @brief services stores the service definitions.
	 */
	std::map<std::type_index, ServiceDefinition> services;
};
