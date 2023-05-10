/*
Hooking namespace using Microsoft Detours
*/
#pragma once
#include <Windows.h>
#include "detours.h"
#include <unordered_map>

namespace hook
{
	inline std::unordered_map<void*, void*> Hooks; // Stores all active hooks

	template <class S, class T>
	inline void CreateHook(S& source, T& destination)
	{
		DetourTransactionBegin();						// Begins a new detour transaction, any detours created will be applied after the 'DetourTransactionCommit' call
		DetourUpdateThread(GetCurrentThread());			// Specify this thread to be updated during the transaction
		DetourAttach(&(PVOID&)source, destination);		// Attach the hook
		DetourTransactionCommit();						// Commit & apply hooks
		Hooks[(void*)source] = (void*)destination;		// Register the new hook in the Hooks map
	}

	// Template wrapper function that allows you to hook a specific address in memory to a function
	template <class H>
	inline void CreateHookAddress(uintptr_t address, H& destination)
	{
		auto src = reinterpret_cast<decltype(&target)>(address); // cast 'address' to the same type as destination
		return CreateHook(src, target);
	}

	template <class T>
	inline T* GetSourceFunction(T& fnc)
	{
		for (auto& pair : Hooks)
		{
			if (pair.second == (void*)fnc)
			{
				void* pvoid = pair.first;
				return reinterpret_cast<T*>(pvoid);
			}
		}
		return nullptr;
	}
}