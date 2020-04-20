#include "pch.h"
#include "WindowsException.h"

// The construtor would call to the Get the last error code
WindowsException::WindowsException(const std::wstring & userMessage) : _message(userMessage), _errorCode(GetLastError()) {
}

std::wstring WindowsException::getMessage() {
    LPWSTR pSystemMessage;

    // This is the system to get message in default local
    auto messageLength = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
        NULL, _errorCode, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPWSTR)&pSystemMessage, 0, NULL);

    // This mean we have got a message
    if (messageLength > 0) {
        _message += L":";
        _message += std::wstring(pSystemMessage);

        if (pSystemMessage != NULL) LocalFree(pSystemMessage);
    }

    return _message;
}
