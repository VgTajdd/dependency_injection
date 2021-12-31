#pragma	once

#include <typeinfo>
#include <typeindex>
#include <functional>

/**
 * @brief	The ServiceDefinition struct.
 */
struct ServiceDefinition
{
	std::type_info const& type_info;
	std::type_index type_index;
	std::function<void* ( )> factory;
};
