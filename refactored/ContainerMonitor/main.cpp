// MyVMProv.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"

#include <iostream>
#include <Windows.h>
#include <conio.h>

int wmain(int argc, wchar_t* argv[])
{
    STARTUPINFOEX emulatorStartupInformation;
    PROCESS_INFORMATION emulatorProcessInfo;

    // Intilizing start up information for the process
    ZeroMemory(&emulatorProcessInfo, sizeof(emulatorProcessInfo));
    ZeroMemory(&emulatorStartupInformation, sizeof(emulatorStartupInformation));

    // Creating the process, in a suspended state
    auto processCreatingResult = CreateProcess(L"emulator.exe",
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
    getch();
    return 0;
}
