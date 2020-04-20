#pragma once

#include <string>

class WindowsException {
    private:
        DWORD           _errorCode;
        std::wstring    _message;

    public:
        explicit WindowsException(const std::wstring& userMessage);
        std::wstring getMessage();
};

