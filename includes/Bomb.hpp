/*
** EPITECH PROJECT, 2018
** indie studio
** File description:
** Bomb.hpp
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "Entity.hpp"

class Bomb: public Entity {
public:
	Bomb(Position Pos);
	~Bomb();
	void addSprite(ISceneManager &smgr, IVideoDriver &driver);
protected:
};

#endif /* !BOMB_HPP_ */
