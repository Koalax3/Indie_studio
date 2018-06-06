/*
** EPITECH PROJECT, 2018
** indie studio
** File description:
** Player.cpp
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Entity.hpp"
#include "Bomb.hpp"

class Player: public Entity {
public:
	Player(ISceneManager &smgr, IVideoDriver &driver, Position Pos = (0, 0, 0));
	~Player();
	void DropBomb();
	void addSprite(int index = 0);
	void MoveLeft(float speed);
	void MoveRight(float speed);
	void MoveUp(float speed);
	void MoveDown(float speed);

protected:
	ISceneManager &smgr;
	IVideoDriver &driver;
	std::vector<Bomb *> StockBomb;
	int MaxBomb;
};

#endif /* !PLAYER_HPP_ */
