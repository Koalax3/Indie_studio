/*
** EPITECH PROJECT, 2018
** indie studio
** File description:
** Player.cpp
*/

#include "Player.hpp"

Player::Player(ISceneManager &smgr, IVideoDriver &driver, Position Pos) :
	Entity(B_MAN, Pos), smgr(smgr), driver(driver), MaxBomb(1), Life(true)
{
	StockBomb = new std::vector<Bomb *>;
}

Player::~Player()
{
}

void Player::addSprite(int index)
{
	Mesh *mesh = new Mesh(smgr, BMESH);
	mesh->setPos(getX(), getY(), getZ());
	mesh->getNode()->setScale(vector3df(0.7,0.7,0.7));
	mesh->addTexture(driver, BTEXTURE[index]);
	setSprite(mesh);
}

void Player::DropBomb()
{
	if (MaxBomb > StockBomb->size())	{
		vector3df pos = getSprite()->getNode()->getPosition();
		Bomb *boom = new Bomb(Position(pos.X, pos.Y, pos.Z));
		boom->addSprite(smgr, driver);
		StockBomb->push_back(boom);
	}
}

void Player::MoveUp(float speed)
{
	vector3df pos = getSprite()->getNode()->getPosition();	
	getSprite()->setPos(pos.X, pos.Y, pos.Z-speed);
	setZ(pos.Z);
	getSprite()->setRot(0, -90,0);
}
void Player::MoveLeft(float speed)
{
	vector3df pos = getSprite()->getNode()->getPosition();	
	getSprite()->setPos(pos.X+speed, pos.Y, pos.Z);
	setX(pos.X);
	getSprite()->setRot(0,180,0);
}
void Player::MoveRight(float speed)
{
	vector3df pos = getSprite()->getNode()->getPosition();	
	getSprite()->setPos(pos.X-speed, pos.Y, pos.Z);
	setZ(pos.Z);
	getSprite()->setRot(0,0,0);
	
}
void Player::MoveDown(float speed)
{
	vector3df pos = getSprite()->getNode()->getPosition();	
	getSprite()->setPos(pos.X, pos.Y, pos.Z+speed);
	setX(pos.X);
	getSprite()->setRot(0,90,0);
}

int Player::getId()
{
	return Id;
}

void Player::setId(int id)
{
	Id = id;
}

bool Player::isLife()
{
	return Life;
}

void Player::setLife(bool stat)
{
	Life = stat;
}

void Player::CheckBombs()
{
	for (int i = 0; i < StockBomb->size(); i++) {
		StockBomb->at(i)->check();
	}
}

std::vector<Bomb *> *Player::getStockBomb() const
{
	return StockBomb;
}