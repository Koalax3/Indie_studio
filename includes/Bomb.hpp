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
	bool isBlast() const;
	time_t getTimer() const;
	time_t getDuration() const;
	void setTimer(time_t Timer);
	void setDuration(time_t Duration);
	void setBlast(bool Blast);
	absolute getRange() const;
	absolute getStrength() const;
	void setRange(absolute Range);
	void setStrength(absolute Strength);
	void check();
protected:
	bool Blast;
	std::time_t Timer;
	std::time_t Duration;
	absolute Range;
	absolute Strength;
};

#endif /* !BOMB_HPP_ */
