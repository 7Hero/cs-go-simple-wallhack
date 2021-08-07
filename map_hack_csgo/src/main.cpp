#include <Windows.h>
#include <iostream>
#include <fstream>
#include <tlhelp32.h>
#include <wchar.h>
#include "Game.h"
#include "Header.hpp"
#include <string>
#include "json.hpp"
using namespace hazedumper::netvars;
using namespace hazedumper::signatures;
int main() {
	SetConsoleTitle(L"LEANCA TEODOR - WALLHACK v1.337");
	// toggle la perete
	bool toggle = true;
	struct glowStructEnemy {
		float red = 1.f;
		float green = 0.f;
		float blue = 0.f;
		float alpha = 0.7f;
		uint8_t padding[8];
		float unknown = 1.f;
		uint8_t padding2[4];
		BYTE renderOccluded = true;
		BYTE renderUnoccluded = false;
		BYTE fullBloom = false;
	} glowEnm;

	struct glowStructLocal {
		float red = 0.f;
		float green = 0.f;
		float blue = 1.f;
		float alpha = 0.5f;
		uint8_t padding[8];
		float unknown = 1.f;
		uint8_t padding2[4];
		BYTE renderOccluded = true;
		BYTE renderUnoccluded = false;
		BYTE fullBloom = false;
	} glowLocal;

	Game* game = new  Game("Counter-Strike: Global Offensive");
	DWORD LocalPlayer = game->Read<DWORD>(game->clientBaseAddr + dwLocalPlayer);
	int MyTeam = game->Read<int>(LocalPlayer + m_iTeamNum);
	while (1) {
		if (GetAsyncKeyState(VK_CAPITAL) == -32767) toggle = !toggle;
		//check for toggle
		if (toggle) {
		DWORD GlowOBJ = game->Read<DWORD>(game->clientBaseAddr + dwGlowObjectManager);
		// Treci prin toate entitatile .
		for (short int i = 1; i < 32; i++) {
			DWORD EntityList = game->Read<DWORD>(game->clientBaseAddr + dwEntityList + i * 0x10);
			int GlowINDX = game->Read<int>(EntityList + m_iGlowIndex);
			int entityTeam = game->Read<int>(EntityList + m_iTeamNum);

			// Deseneaza glow pe pidari
			if (MyTeam == entityTeam) {
				game->Write<glowStructLocal>(GlowOBJ + (GlowINDX * 0x38) + 0x8, glowLocal);
			}
			else if (MyTeam != entityTeam) {
				game->Write<glowStructEnemy>(GlowOBJ + (GlowINDX * 0x38) + 0x8, glowEnm);
			}
		} //check for toggle
		Sleep(10);
		}
	}
	return 0;
}

/*

	char* a = new char[50];
	a[0] = '|';

	std::cout << "\r" << "Apasa pe enter ca sa continui      " << std::flush;
	getchar();
	std::cout << "\r" << "VASEA GLOW HACK v1.337 activated , hacking into the gate.      " << std::flush;
	Sleep(1000);
	std::cout << "\r" << "VASEA GLOW HACK v1.337 activated , hacking into the gate.      " << std::flush;
	Sleep(1000);
	std::cout << "\r" << "VASEA GLOW HACK v1.337 activated , hacking into the gate..     " << std::flush;
	Sleep(1000);
	std::cout << "\r" << "VASEA GLOW HACK v1.337 activated , hacking into the gate...    " << std::flush;
	Sleep(1000);
	std::cout << "\r" << "VASEA GLOW HACK v1.337 activated , hacking into the gate.....  " << std::flush;
	Sleep(1000);
	std::cout << "\r" << "VASEA GLOW HACK v1.337 activated , hacking into the gate......." << std::flush;
	Sleep(1000);
	std::cout << "\r" << "trying to breach the firewall.                                   " << std::flush;
	Sleep(1000);
	std::cout << "\r" << "trying to breach the firewall..                                  " << std::flush;
	Sleep(1000);
	std::cout << "\r" << "trying to breach the firewall...                                 " << std::flush;
	Sleep(1000);
	std::cout << "\r" << "trying to breach the firewall.....                               " << std::flush;
	Sleep(1000);
	std::cout << "\r" << "disabling VAC.                                                    " << std::flush;
	Sleep(1000);
	std::cout << "\r" << "disabling VAC..                                                  " << std::flush;
	Sleep(1000);
	std::cout << "\r" << "disabling VAC...                                                  " << std::flush;
	Sleep(1000);
	std::cout << "\r" << "disabling VAC.....                                                  " << std::flush;
	Sleep(1000);
	std::cout << "\r" << "PUNE SUKA PAROLA AI CREZUT CA II GRATIS SAU CE HUILA?            " << std::flush<< std::endl;
	do {
		if(a[0]!= '|') std::cout << "WE PULA AI PUS PAROLA GRESITA" << std::endl;
		std::cin >> a;
	} while (_stricmp(a, "Casilias1") != 0);
		std::cout << "CHEAT ACTIVATED GLOBAL OFFENSIVEIN DOUA ZILE SUKA" << std::endl;


	*/
	//Glow staff old stuff doesn't work anymore
					/*
					if (MyTeam == entityTeam)
					{
						game->Write<float>(GlowOBJ + ((GlowINDX * 0x38) + 0x4), 0);
						game->Write<float>(GlowOBJ + ((GlowINDX * 0x38) + 0x8), 0);
						game->Write<float>(GlowOBJ + ((GlowINDX * 0x38) + 0xC), 2);
						game->Write<float>(GlowOBJ + ((GlowINDX * 0x38) + 0x10), 1);
					}
					else
					{
						game->Write<float>(GlowOBJ + ((GlowINDX * 0x38) + 0x4), 9);
						game->Write<float>(GlowOBJ + ((GlowINDX * 0x38) + 0x8), 0);
						game->Write<float>(GlowOBJ + ((GlowINDX * 0x38) + 0xC), 0);
						game->Write<float>(GlowOBJ + ((GlowINDX * 0x38) + 0x10), 1);
					}
					game->Write<bool>(GlowOBJ + ((GlowINDX * 0x38) + 0x24), true);
					game->Write<bool>(GlowOBJ + ((GlowINDX * 0x38) + 0x25), false);
					*/