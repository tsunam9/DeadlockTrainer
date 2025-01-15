#pragma once

#include <cstdint>
#include <Windows.h>
#include <iostream>
#include "memory"
#include <thread>
#include <chrono>
#include "mem.h"
#include "json.hpp"

class Security {

public:

	static std::string getHardwareId();

	void StartupServerMessage(HMODULE hmod);

};