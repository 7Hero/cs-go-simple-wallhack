#pragma once
#include <Windows.h>
#include <wchar.h>
class Game {
public:
	Game(const char* m_gameTitle);
	
	DWORD pID;
	const char* gameTitle;
	HANDLE pHandle;
	uintptr_t engineBaseAddr;
	uintptr_t clientBaseAddr;
	//uintptr_t csgoBaseAddr;


	template<class T> T Read(DWORD dwAddress);
	uintptr_t getBaseAddr(const wchar_t* moduleName);
	template<class T> void Write(DWORD dwAddress, T i);
};

template<class T>
T Game::Read(DWORD dwAddress)
{
	T cRead;
	ReadProcessMemory(pHandle, (LPVOID)dwAddress, &cRead, sizeof(T), NULL);
	return cRead;
}
template<class T>
void Game::Write(DWORD dwAddress, T i)
{
	WriteProcessMemory(pHandle, (LPVOID)dwAddress, &i, sizeof(i), NULL);
}
