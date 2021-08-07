#include "Game.h"
#include <tlhelp32.h>
#include <wchar.h>
#include <iostream>
Game::Game(const char* m_gameTitle) {
	gameTitle = m_gameTitle;
	HWND hwnd = FindWindowA(0, m_gameTitle);
	GetWindowThreadProcessId(hwnd, &pID);
	pHandle = OpenProcess(PROCESS_ALL_ACCESS, 0, pID);
	engineBaseAddr = getBaseAddr(L"engine.dll");
	clientBaseAddr = getBaseAddr(L"client.dll");

}
uintptr_t Game::getBaseAddr(const wchar_t* moduleName) {
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pID);

	MODULEENTRY32 moduleSnap;

	if (hSnap != INVALID_HANDLE_VALUE) {
		moduleSnap.dwSize = sizeof(MODULEENTRY32);
		Module32First(hSnap, &moduleSnap);
		do
			if (_wcsicmp(moduleSnap.szModule, moduleName)== 0) {

				CloseHandle(hSnap);
				return (uintptr_t)moduleSnap.modBaseAddr;
			}
		while (Module32Next(hSnap, &moduleSnap));
	}
	return 0;
}
