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
	Player(ISceneManager &smgr, IVideoDriver &driver,
	       Position Pos = (0, 0, 0), bool IA = true);
	~Player();
	bool DropBomb();
	void addSprite(int index = 0);
	void MoveLeft(float speed);
	void MoveRight(float speed);
	void MoveUp(float speed);
	void MoveDown(float speed);
	int getId();
	void setId(int id);
	bool isLife();
	void setLife(bool stat);
	void CheckBombs();
	void addCollisonBomb(IMetaTriangleSelector &selector);
	std::vector<Bomb *> *getStockBomb() const;
	void Move(Compass direction, float speed);
	Position getFront(Compass dir);
	ISceneManager &getSmgr() const;
	IVideoDriver &getDriver() const;
	int getMaxBomb() const;
	int getID() const;
	bool isIA() const;
	void setSmgr(ISceneManager &smgr);
	void setDriver(IVideoDriver &driver);
	void setStockBomb(std::vector<Bomb *> *StockBomb);
	void setMaxBomb(int MaxBomb);
	void setID(int ID);
	void setIA(bool IA);
	void HitboxBomb(Bomb *bomba);
	double getLifeTimer() const;
protected:
	ISceneManager &smgr;
	IVideoDriver &driver;
	std::vector<Bomb *> *StockBomb;
	int MaxBomb;
	int Id;
	bool Life;
	int ID;
	bool IA;
	double lifeTimer;
};

#endif /* !PLAYER_HPP_ */
