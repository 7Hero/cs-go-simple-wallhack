#pragma once
#include <cstdint>
#include <cstddef>
#include <fstream>
#include "json.hpp"
using json = nlohmann::json;


// 2021-05-25 18:59:43.237060700 UTC

namespace hazedumper {
	constexpr ::std::int64_t timestamp = 1621969183;
	std::ifstream file("csgo.json");
	json j = json::parse(file);
	namespace netvars {
		uintptr_t m_iTeamNum = j["netvars"]["m_iTeamNum"];
		uintptr_t m_iGlowIndex = j["netvars"]["m_iGlowIndex"];
	} // namespace netvars
	namespace signatures {
		uintptr_t dwLocalPlayer = j["signatures"]["dwLocalPlayer"];
		uintptr_t dwGlowObjectManager = j["signatures"]["dwGlowObjectManager"];
		uintptr_t dwEntityList = j["signatures"]["dwEntityList"];
	} // namespace signatures
} // namespace hazedumper


/*
class Netvars {
	Netvars(char* signame) {
		std::ifstream file("csgo.json");
		json j = json::parse(file);
		uintptr_t dwLocalPlayer = j["signatures"]["dwLocalPlayer"];
		uintptr_t dwGlowObjectManager = j["signatures"]["dwGlowObjectManager"];
		uintptr_t dwEntityList = j["signatures"]["dwEntityList"];
		uintptr_t m_iTeamNum = j["netvars"]["m_iTeamNum"];
		uintptr_t m_iGlowIndex = j["netvars"]["m_iGlowIndex"];
	}
	uintptr_t dwLocalPlayer;
	uintptr_t m_iTeamNum;
	uintptr_t dwGlowObjectManager;
	uintptr_t dwEntityList;
	uintptr_t m_iGlowIndex;
};*/