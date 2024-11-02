#pragma once
#include "offsets.h"
#include "helper.h"
#include "client_dll.hpp"

using namespace cs2_dumper::schemas::client_dll;

struct EntityBuffer {
    std::vector<uint64_t>* active = nullptr;  // currently being read
    std::vector<uint64_t>* updating = nullptr; // being written to
    std::atomic<bool> isSwapping{ false };

    EntityBuffer() {
        active = new std::vector<uint64_t>();
        updating = new std::vector<uint64_t>();
    }

    ~EntityBuffer() {
        delete active;
        delete updating;
    }

    void SwapBuffers() {
        bool expected = false;
        if (isSwapping.compare_exchange_strong(expected, true)) {
            std::swap(active, updating);
            isSwapping.store(false);
        }
    }
};


class globals {

public:

    EntityBuffer entlist;
    CGlobalVarsBase* Globals;
    void SortEnts();

    globals();
};

inline static globals GlobalVars;