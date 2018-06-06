/*
** EPITECH PROJECT, 2018
** indie studio
** File description:
** Bomb.cpp
*/

#include "Bomb.hpp"

Bomb::Bomb(Position Pos): Entity(BOMB, Pos)
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
