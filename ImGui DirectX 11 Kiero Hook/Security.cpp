#include "Security.h"

enum ServerMessageTypes {
    Startup,
    Heartbeat
};

std::string getDiskSerialNumber() {
    // Get the first physical drive
    HANDLE hDevice = CreateFileW(L"\\\\.\\PhysicalDrive0", 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
    if (hDevice == INVALID_HANDLE_VALUE) {
        std::cerr << "Error opening PhysicalDrive0: " << GetLastError() << std::endl;
        return "";
    }

    // Get the drive geometry
    STORAGE_PROPERTY_QUERY query;
    query.PropertyId = StorageDeviceProperty;
    query.QueryType = PropertyStandardQuery;

    STORAGE_DESCRIPTOR_HEADER header;
    DWORD bytesReturned;
    if (!DeviceIoControl(hDevice, IOCTL_STORAGE_QUERY_PROPERTY, &query, sizeof(query), &header, sizeof(header), &bytesReturned, NULL)) {
        std::cerr << "Error querying device property: " << GetLastError() << std::endl;
        CloseHandle(hDevice);
        return "";
    }

    // Allocate buffer for the device descriptor
    const DWORD bufferSize = header.Size;
    BYTE* buffer = new BYTE[bufferSize];
    if (!DeviceIoControl(hDevice, IOCTL_STORAGE_QUERY_PROPERTY, &query, sizeof(query), buffer, bufferSize, &bytesReturned, NULL)) {
        std::cerr << "Error querying device property: " << GetLastError() << std::endl;
        delete[] buffer;
        CloseHandle(hDevice);
        return "";
    }

    // Get the serial number from the device descriptor
    STORAGE_DEVICE_DESCRIPTOR* descriptor = reinterpret_cast<STORAGE_DEVICE_DESCRIPTOR*>(buffer);
    if (descriptor->SerialNumberOffset != 0) {
        std::string serialNumber(reinterpret_cast<char*>(buffer + descriptor->SerialNumberOffset));
        delete[] buffer;
        CloseHandle(hDevice);
        return serialNumber;
    }
    else {
        std::cerr << "Error: No serial number found." << std::endl;
        delete[] buffer;
        CloseHandle(hDevice);
        return "";
    }
}

std::string Security::getHardwareId() {

    return getDiskSerialNumber();

}

extern bool unloadRequested;

void Security::StartupServerMessage(HMODULE hmod) {

    // send to server and wait for received confirmation 

    if (true){ // server gave us an okay message 
        // do nothing for now
    }
    else {
        unloadRequested = true;
    }

}

