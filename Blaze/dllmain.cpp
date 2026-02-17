#include "framework.h"
#include "SDK.hpp"
#include "Window.h"

DWORD WINAPI MainThread(LPVOID lParams)
{
    AllocConsole();
    FILE* f;


    freopen_s(&f, "CONIN$", "r", stdin);
    freopen_s(&f, "CONOUT$", "w", stderr);
    freopen_s(&f, "CONOUT$", "w", stdout);
    SetConsoleTitleA("Blaze Console DLL (FortniteWin32) UE 4.12");

    CreateThread(0, 0, RUNWINDOW, 0, 0, 0);

    return 0;
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved) {
    if (reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);
        HANDLE hThread = CreateThread(nullptr, 0, MainThread, hModule, 0, nullptr);
        if (!hThread) {
            MessageBoxA(NULL, "CreateThread failed!", "Error", MB_OK | MB_ICONERROR);
        }
        else {
            CloseHandle(hThread);
        }
    }
    return TRUE;
}

