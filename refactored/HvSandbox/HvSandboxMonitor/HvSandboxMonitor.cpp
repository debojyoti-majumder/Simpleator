#include "pch.h"

#include <iostream>
#include <string>
#include <conio.h>

#include "WindowsProcess.h"

static const std::wstring emulatorBinaryName{ L"emulator.exe" };

using namespace std;

int _tmain() {
    cout << "HVSnadBox Monitor!\n"; 
    
    WindowsProcess emulatorProgram(emulatorBinaryName, GetCommandLine());
    emulatorProgram.makeSuspended();
    emulatorProgram.launch();

    // TODO: Wait for the emulator program to end also, on a thread
    // Waiting for user input to continue
    cout << "Press any ket to exit\n";
    int n;
    cin >> n;

    // Just for fun
    return n;
}

