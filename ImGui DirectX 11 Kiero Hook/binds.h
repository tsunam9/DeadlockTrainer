#pragma once
#include <string>
#include "cfgvar.h"
#include "helper.h"

// also lifted from seowned cause its one of the best bind systems i've ever seen istg im not a paster

enum BindType
{
	TOGGLE, HOLD
};

struct Bind final
{
public:
	std::string name{};
	int32_t key{};
	int type{};
	bool val_on{};
	bool val_off{};
	cfgvar* configvar;

	bool operator==(const Bind& other) const {
		return this->name == other.name;
	}

};

class Binds {

private:

	std::vector<Bind> bindstodelete;

	std::vector<Bind> bindlist;

public:

	void addbind(const Bind bind);
	void removebind(Bind* const bind_ptr);

	void think();
	void paint();


};