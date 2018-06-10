/*
** EPITECH PROJECT, 2018
** indie studio
** File description:
** Bomb.cpp
*/

#include "Bomb.hpp"

Bomb::Bomb(Position Pos): Entity(BOMB, Pos), Blast(false), Timer(time(nullptr)),
			  Duration(2), Range(1), Strength(1)
{
}

void Bomb::addSprite(ISceneManager &smgr, IVideoDriver &driver)
{
	Mesh *mesh = new Mesh(smgr, BOMBMESH);
	mesh->setPos(getX(), getY(), getZ());
	mesh->getNode()->setScale(vector3df(0.5,0.5,0.5));
	mesh->addTexture(driver, BOMBTEXTURE);
	setSprite(mesh);
}

Bomb::~Bomb()
{
}


time_t Bomb::getTimer() const
{
	return Timer;
}

time_t Bomb::getDuration() const
{
	return Duration;
}

void Bomb::setTimer(time_t Timer)
{
	Bomb::Timer = Timer;
}

void Bomb::setDuration(time_t Duration)
{
	Bomb::Duration = Duration;
}

void Bomb::check()
{
	if (time(nullptr) >= Timer + Duration) {
		setBlast(true);
	}
}

bool Bomb::isBlast() const
{
	return Blast;
}

void Bomb::setBlast(bool Blast)
{
	Bomb::Blast = Blast;
}

absolute Bomb::getRange() const
{
	return Range;
}

absolute Bomb::getStrength() const
{
	return Strength;
}

void Bomb::setRange(absolute Range)
{
	Bomb::Range = Range;
}

void Bomb::setStrength(absolute Strength)
{
	Bomb::Strength = Strength;
}
