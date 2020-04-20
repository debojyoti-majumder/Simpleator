#include "pch.h"
#include "WindowsProcess.h"

WindowsProcess::WindowsProcess(const std::wstring& processPath, LPWSTR commandLine) : _processPath(processPath), _commandLine(commandLine) {
    ZeroMemory(&_emulatorProcessInfo, sizeof(_emulatorProcessInfo));
    ZeroMemory(&_emulatorStartupInformation, sizeof(_emulatorStartupInformation));

    _processCreationFlags = EXTENDED_STARTUPINFO_PRESENT;
}

void WindowsProcess::launch() {
    
}

WindowsProcess::~WindowsProcess() {
}
