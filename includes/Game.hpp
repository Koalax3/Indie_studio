/*
** EPITECH PROJECT, 2018
** Indie Studio
** File description:
** Game.hpp
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "Core.hpp"
class Game
{
public:
	Game();
	void arena(int size = 15);
	void menu();
	void initMapPath();
	~Game();

protected:
private:
	Core *Gui;
	MapPath Path;
};

#endif /* !GAME_HPP_ */
