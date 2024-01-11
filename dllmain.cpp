// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"

#include "windows.h"
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// evil code
	MessageBox(NULL, TEXT("已加载 evildll"), TEXT("test"), MB_OK);
	STARTUPINFO si = { sizeof(si) };
	PROCESS_INFORMATION pi;
	CreateProcess(TEXT("C:\\Windows\\System32\\calc.exe"), NULL, NULL, NULL, false, 0, NULL, NULL, &si, &pi);

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

