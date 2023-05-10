/*
Simple demo project showcasing a very basic function hook and how dlls are made in general.
This function contains the entry point of the .dll file when injected into a process (DllMain)
*/
#include "hook.h"
#include <iostream>
#include <chrono>

void Main(HMODULE); // Forward-declaration of the Main function to make the code easier to read
BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID)
{
    // the DLL_PROCESS_ATTACH event is only triggered one time per injection when the dll is loaded in the target process
    // this essentially replaces the 'main' function of a traditional console application
    if (reason == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hModule); // improves performance
        // you generally don't want to run dll code on the DllMain thread
        // to avoid this, you can create a seperate thread using the windows api
        // this is basically like calling the function 'Main(hModule)' normally, except here it runs concurrently in another context
        HANDLE threadHandle = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)Main, hModule, 0, nullptr);
        if (threadHandle)
            CloseHandle(threadHandle); // Close the open handle to the thread because we won't use it anyway
    }
    return TRUE;
}

/* ------------ Hook functions ------------ */
// This hook will unlock the 'Demonic Tyranny' illusion clientside (it will still be locked serverside)
bool Hook_MatchesCondition(void* player, int condition, int* a3)
{
    // The condition id for Demonic Tyranny is 49247
    if (condition == 49247) 
    {
        return true; // Returning true tells the caller that the player condition is unlocked
    }

    // If the condition being checked is not Demonic Tyranny, return the original value
    return hook::GetSourceFunction<decltype(Hook_MatchesCondition)>(Hook_MatchesCondition)(player, condition, a3);
}

/*
Main dll loop, runs in a seperate thread created by DllMain
This function will create any hooks and can accept input from the console
When this function exits, the dll is uninjected through 'FreeLibraryAndExitThread'
*/
bool DllExit = false;
void Main(HMODULE module)
{
    /* ------------ Initialization ------------*/
    AllocConsole(); // Allocate a console window for the dll
    // When a new console is allocated, you need to re-open the output/input streams for the console window
    FILE* f_out = freopen("CONOUT$", "w", stdout); // Opens stdout in 'write' mode (std::cout, printf, ...)
    FILE* f_in = freopen("CONIN$", "r", stdin); // Opens stdin in 'read' mode (std::cin)

    /* ------------ Hooks ------------*/
    /*
    Hooking or 'detouring' a function means that whenever the game tries to call the original function, it will actually call your
    detour instead. In this detour, you can modify the behaviour of the entire function and patch out various checks leading to different
    behaviour. All hooking functions are defined in "hook.h", but the target functions can be defined anywhere.
    */
    uintptr_t WowBase = (uintptr_t)GetModuleHandleA(0); // GetModuleHandleA(0) essentially returns the base address of the host process
    uintptr_t OffsetMatchesCondition = 0x789630;        // The offset of MatchesCondition in game memory
                                                        // This offset can be found through reverse-engineering in IDA Pro/Ghidra
                                                        // In WoW build 26124, it's 0x789630 (=7902768)
    hook::CreateHookAddress(WowBase + OffsetMatchesCondition, Hook_MatchesCondition);
    printf("Hooks created.\nConsole is now active.\n");

    /* ------------ Console I/O ------------*/
    std::string Command = ""; // Stores the current command
    while (!DllExit) // This code runs until DllExit is set to true
    {
        std::getline(std::cin, Command); // Get a full line of text from the input stream and store it in the Command variable
        if (Command == "quit") // the 'quit' command
        {
            // this command will set DllExit to true causing the loop to end and exiting the function
            // because we are in the context of the "while (!DllExit)" loop, we can just use 'break' instead as it has the same effect
            // DllExit = true;
            break;
        }
        /*
        normally, you would sleep this thread for a couple of milliseconds to reduce the CPU usage
        this isn't required when you accept input from the user as std::getline will block the thread automatically
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        */
    }

    /* ------------ Cleanup & exit ------------*/
    printf("Exiting.\n");
    // Close the console in/out handles opened by freopen
    if (f_out) fclose(f_out);
    if (f_in) fclose(f_in);
    FreeConsole(); // Frees the previously allocated console
    FreeLibraryAndExitThread(module, 0); // Exits this thread and "uninjects" the dll from the process
}
