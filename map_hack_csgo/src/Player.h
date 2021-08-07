#include <Windows.h>
#include <iostream>
#include "Game.h"

struct Vec3 {
	double x, y, z;
};
struct Player {
	int Health, Armor;
	Vec3 Position;
	bool Dormant;
	int Team, ID;
	DWORD EntityBase;
}player;


