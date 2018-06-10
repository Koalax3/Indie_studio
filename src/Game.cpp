/*
** EPITECH PROJECT, 2018
** Indie studio
** File description:
** Game.cpp
*/

#include "Game.hpp"

Game::Game()
{
	Gui = new Core();
}

void Game::initMapPath()
{
	Path.MapMesh[BRICK] = "media/Wall/mur.obj";
	Path.MapTexture[BRICK] = "media/Wall/AO.png";
	Path.MapMesh[BOX] = "media/Box/caisse.obj";
	Path.MapTexture[BOX] = "media/Box/caisse_AO.png";
}

void Game::arena(int size)
{
	initMapPath();
	if (Gui->loopArena(size, Path) == ARENA)
		arena(size);
}

void Game::menu()
{
	if (Gui->loopMenu() == ARENA)
		arena();
}

Game::~Game()
{
}
