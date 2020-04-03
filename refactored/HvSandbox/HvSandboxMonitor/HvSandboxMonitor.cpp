#include "pch.h"

#include <iostream>
#include <string>
#include <conio.h>

static const std::wstring emulatorBinaryName{ L"emulator.exe" };

using namespace std;

int _tmain() {
    cout << "HVSnadBox Monitor!\n"; 

    STARTUPINFOEX emulatorStartupInformation;
    PROCESS_INFORMATION emulatorProcessInfo;

    // Intilizing start up information for the process
    ZeroMemory(&emulatorProcessInfo, sizeof(emulatorProcessInfo));
    ZeroMemory(&emulatorStartupInformation, sizeof(emulatorStartupInformation));

    // Creating the process, in a suspended state
    auto processCreatingResult = CreateProcess(emulatorBinaryName.c_str(),
        GetCommandLine(), NULL, NULL, TRUE,
        CREATE_SUSPENDED | EXTENDED_STARTUPINFO_PRESENT,
        NULL, NULL,
        &emulatorStartupInformation.StartupInfo,
        &emulatorProcessInfo);

    // Checking for error codes
    if (false == processCreatingResult) {
        std::wcout << "Was not able to launch the process\n";
        return -1;
    }

    // Waiting for user input to continue
    cout << "Press any ket to exit\n";
    int n;
    cin >> n;

    // Just for fun
    return n;
}

