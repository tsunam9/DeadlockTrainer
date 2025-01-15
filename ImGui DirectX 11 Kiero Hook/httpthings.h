#pragma once
#define CPPHTTPLIB_OPENSSL_SUPPORT // Enable SSL support
#include "httplib.h"
#include <iostream>
#include "json.hpp"
#include "Security.h"
#include <Windows.h>

using nlohmann::json;

class http {

public:
	static void send();
};

extern bool unloadRequested;

void sendrequest(json j) {

	httplib::SSLClient client("192.168.254.92", 443);

    client.enable_server_certificate_verification(false);

    std::string json_str = j.dump();

    std::cout << "Sending Request\n";

    auto res = client.Get("/confirm");

    if (res) {
        // Process the response
        std::cout << "Response: " << res->body << std::endl;
    }
    else {
        std::cout << "Request failed with error code: " << static_cast<int>(res.error()) << std::endl;
    }
}

std::string readFromClipboard() {
    std::string data;

    // Open the clipboard
    if (!OpenClipboard(nullptr)) {
        std::cerr << "Failed to open clipboard." << std::endl;
        return data;
    }

    // Check if the clipboard contains text data
    if (IsClipboardFormatAvailable(CF_TEXT)) {
        // Get the handle to the clipboard data
        HGLOBAL hGlobal = GetClipboardData(CF_TEXT);
        if (hGlobal == nullptr) {
            std::cerr << "Failed to retrieve clipboard data." << std::endl;
            CloseClipboard();
            return data;
        }

        // Lock the handle to get a pointer to the data
        char* pClipboardData = static_cast<char*>(GlobalLock(hGlobal));
        if (pClipboardData != nullptr) {
            data = pClipboardData; // Copy data into the string
            GlobalUnlock(hGlobal);
        }
        else {
            std::cerr << "Failed to lock clipboard data." << std::endl;
        }
    }
    else {
        std::cerr << "Clipboard does not contain text data." << std::endl;
    }

    // Close the clipboard

    EmptyClipboard();

    CloseClipboard();

    return data;
}

extern std::string global_token;


#define NO_SECURITY

void http::send() {

    httplib::SSLClient client("192.168.254.92", 443);

    client.enable_server_certificate_verification(false);

    std::cout << "Sending Request\n";

    auto res = client.Get("/confirm");

    if (res) {
        // Process the response
        std::cout << "Response: " << res->body << std::endl;
    }
    else {
        std::cout << "Request failed with error code: " << static_cast<int>(res.error()) << std::endl;
    }


    return;






#ifdef NO_SECURITY
    std::cout << "WARNING NO SECURITY ENABLED\n";
    return;
#endif

    std::string key = readFromClipboard();

    std::cout << "SENDING KEY " << key << "\n";

    Sleep(500);

    nlohmann::json j;

    j["key"] = key;
    j["hwid"] = Security::getHardwareId();

    global_token = key;

    sendrequest(j);

}
