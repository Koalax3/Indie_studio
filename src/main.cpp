/*
** EPITECH PROJECT, 2018
** indie studio
** File description:
** main.cpp
*/

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

#include "Game.hpp"

int main()
{
	Game game;
	game.menu();
}
