// Globals.h 

#pragma once
#include "CGlobalVarsBase.h"
#include "client_dll.hpp"
#include "helper.h"
#include "mem.h"
#include <condition_variable>
#include "IEngineClient.h"
#include "gameinterface.h"
#include "IEngineCvar.h"

using namespace cs2_dumper::schemas::client_dll;

namespace constGlobalVars {
    static const float tickinterval = 0.015625;
}

struct EntityBuffer {
    std::vector<uint64_t>* active = nullptr;
    std::vector<uint64_t>* updating = nullptr;
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
    EntityBuffer espEntList;
    CGlobalVarsBase* Globals;
    uint64_t clientbase;
    float BulletVelocity = 30000.f;

    static globals& instance() {
        static globals single_instance;
        return single_instance;
    }

    void SortEnts();
    void SortEntsEsp();

private:
    std::mutex sortMutex;
    std::condition_variable sortCV;
    bool isSorting = false;

    globals() {
        clientbase = MEM::GetClientBase();
        uint64_t globalsoffset = MEM::PatternScanOffset((void*)clientbase, "48 8B 05 ? ? ? ? 44 3B 40", 3, 7); 
        Globals = *(CGlobalVarsBase**)(clientbase + globalsoffset);
    }

    // Prevent copying and assignment
    globals(const globals&) = delete;
    globals& operator=(const globals&) = delete;

};

extern IEngineClient* iEngine;
extern IEngineCVar* VEngineCvar;

extern bool unloadRequested;