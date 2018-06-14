/*
** EPITECH PROJECT, 2018
** indie studio
** File description:
** Player.cpp
*/

#include "Player.hpp"

Player::Player(ISceneManager &smgr, IVideoDriver &driver, Position Pos, bool AI) :
	Entity(B_MAN, Pos), smgr(smgr), driver(driver), MaxBomb(1), Life(true), IA(AI)
{
	StockBomb = new std::vector<Bomb *>;
	lifeTimer = time(nullptr);
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

bool Player::DropBomb()
{
	bool bomba = false;
	if (MaxBomb > StockBomb->size()) {
		vector3df pos = getSprite()->getNode()->getPosition();
		Bomb *boom = new Bomb(Position(pos.X, pos.Y, pos.Z));
		boom->addSprite(smgr, driver);
		StockBomb->push_back(boom);
		bomba = true;
	}
	return bomba;
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

void Player::addCollisonBomb(IMetaTriangleSelector &selector)
{
	for (int i = 0; i < StockBomb->size(); i++) {
		StockBomb->at(i)->getSprite()->addCollision(selector);
	}
}

std::vector<Bomb *> *Player::getStockBomb() const
{
	return StockBomb;
}

ISceneManager &Player::getSmgr() const
{
	return smgr;
}

IVideoDriver &Player::getDriver() const
{
	return driver;
}

int Player::getMaxBomb() const
{
	return MaxBomb;
}

int Player::getID() const
{
	return ID;
}

bool Player::isIA() const
{
	return IA;
}

void Player::setSmgr(ISceneManager &smgr)
{
	Player::smgr = smgr;
}

void Player::setDriver(IVideoDriver &driver)
{
	Player::driver = driver;
}

void Player::setStockBomb(std::vector<Bomb *> *StockBomb)
{
	Player::StockBomb = StockBomb;
}

void Player::setMaxBomb(int MaxBomb)
{
	Player::MaxBomb = MaxBomb;
}

void Player::setID(int ID)
{
	Player::ID = ID;
}

void Player::setIA(bool IA)
{
	Player::IA = IA;
}

void Player::Move(Compass direction, float speed)
{
	if (direction == RIGHT)
		MoveRight(speed);
	else if (direction == LEFT)
		MoveLeft(speed);
	else if (direction == UP)
		MoveUp(speed);
	else
		MoveDown(speed);
}

Position Player::getFront(Compass dir)
{
	if (dir == RIGHT)
		return Position(getX() + 1, getY());
	else if (dir == LEFT)
		return Position(getX() - 1, getY());
	else if (dir == UP)
		return Position(getX(), getY() + 1);
	else
		return Position(getX(), getY() - 1);
}

void Player::HitboxBomb(Bomb *bomba)
{
	auto tmp = bomba->getPosition();
	for (absolute i = 0; i < bomba->getRange(); i++)
	{
		if ((Position(tmp.getX(), tmp.getY()) == getPosition()) ||
		    (Position(tmp.getX() + i, tmp.getY()) == getPosition()) ||
		    (Position(tmp.getX() - i, tmp.getY()) == getPosition()) ||
		    (Position(tmp.getX(), tmp.getY() + i) == getPosition()) ||
		    (Position(tmp.getX(), tmp.getY() - i) == getPosition())) {
			Life = false;
			Sprite->getNode()->setVisible(false);
		}
	}
}

double Player::getLifeTimer() const
{
	return lifeTimer;
}
