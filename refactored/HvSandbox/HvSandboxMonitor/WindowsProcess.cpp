#include "pch.h"

#include "WindowsProcess.h"
#include "WindowsException.h"

WindowsProcess::WindowsProcess(const std::wstring& processPath, LPWSTR commandLine) : _processPath(processPath), _commandLine(commandLine) {
    ZeroMemory(&_emulatorProcessInfo, sizeof(_emulatorProcessInfo));
    ZeroMemory(&_emulatorStartupInformation, sizeof(_emulatorStartupInformation));

    _processCreationFlags = EXTENDED_STARTUPINFO_PRESENT;
}

void WindowsProcess::launch() {
    // Creating the process, in a suspended state
    auto processCreatingResult = CreateProcess(_processPath.c_str(),
        GetCommandLine(), NULL, NULL, TRUE,
        _processCreationFlags,
        NULL, NULL,
        &_emulatorStartupInformation.StartupInfo,
        &_emulatorProcessInfo);

    // Checking for errors, if not possible throw expection
    if (false == processCreatingResult) {
        std::wstring message(L"Process creation failed for ");
        message += _processPath;

        // Throwing a expection with some message
        throw WindowsException(message);
    }
}

WindowsProcess::~WindowsProcess() {
}
