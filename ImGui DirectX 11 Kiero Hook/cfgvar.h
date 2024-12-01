#pragma once
#include <string>
#include <typeinfo>

//basically lifted tf2 cheat seowned but its a good system so im gonna use it

class cfgvar {

	public:

	std::string m_name;
	void* m_data;
	size_t typehash;

	cfgvar(std::string_view name, void* const ptr, const size_t type_hash)
	{
		m_name = name;
		m_data = ptr;
		typehash = type_hash;
	}

};

#define MAKE_CFGVAR(name, val) \
namespace cfg { inline auto name{ val }; } \
namespace make_cfgvar { inline ConfigVar name{ #name, &cfg::name, typeid(cfg::name).hash_code() }; }

namespace cfg
{
	void save(std::string_view name);
	void load(std::string_view name);
}