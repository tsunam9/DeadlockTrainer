#pragma once
#include "Windows.h"
#include <string>
#include <unordered_set>
#include "helper.h"
#include "offsets.h"
#include "client_dll.hpp"
#include <iostream>


using namespace cs2_dumper::schemas::client_dll;


class EntityList {
	
public:
	std::vector<uint64_t*> entityList;

	EntityList(bool Initialize = true) {
		if (Initialize) {
			Helper PlayerClassHelperObj;
			int max_ents = PlayerClassHelperObj.get_max_entities();

			for (size_t i = 1; i <= PlayerClassHelperObj.get_max_entities(); ++i)
			{
				uint64_t* entityptr = PlayerClassHelperObj.get_base_entityptr_from_index(i);
				if (!*entityptr)
					continue;

				entityList.push_back(entityptr);
			}
		}
		else
		{
			for(int i = 0; i < 12; i++)
			{
				entityList[i] = nullptr;
			}
		}
	}
};
