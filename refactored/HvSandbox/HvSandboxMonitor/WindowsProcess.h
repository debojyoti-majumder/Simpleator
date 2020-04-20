#pragma once

#include <string>
#include <Windows.h>

class WindowsProcess {
    private:
        const std::wstring  _processPath;
        STARTUPINFOEX       _emulatorStartupInformation;
        PROCESS_INFORMATION _emulatorProcessInfo;
        DWORD               _processCreationFlags;
        LPWSTR              _commandLine;

    public:
        explicit WindowsProcess(const std::wstring& processName, LPWSTR commandLine);

        void launch();
        inline void makeSuspended() { _processCreationFlags |= CREATE_SUSPENDED; }
        
        ~WindowsProcess();
};