#include <windows.h>
#include <stdio.h>

HWND WINAPI GetConsoleWindowNT(void)
{
    // declare function pointer type
    typedef HWND WINAPI (*GetConsoleWindowT)(void);

    // declare one such function pointer
    GetConsoleWindowT GetConsoleWindow;

    // get a handle on kernel32.dll
    HMODULE hk32Lib = GetModuleHandle(TEXT("KERNEL32.DLL"));

    // assign procedure address to function pointer
    GetConsoleWindow = (GetConsoleWindowT)GetProcAddress(hk32Lib, TEXT("GetConsoleWindow"));

    // check if the function pointer is valid
    // since the function is undocumented
    if (GetConsoleWindow == NULL)
    {
        return NULL;
    }

    // call the undocumented function
    return GetConsoleWindow();
}

// sumber: https://www.codeincodeblock.com/2011/03/move-console-windows-using-codeblock.html
// via: https://www.youtube.com/watch?embeds_referring_euri=https%3A%2F%2Fwww.codeincodeblock.com%2F&source_ve_path=MTY0OTksMTY0OTksMjg2NjQsMTY0NTAz&feature=emb_share&v=c7CLdmo-7Zg
