/*
** EPITECH PROJECT, 2017
** Indie
** File description:
** Created by nauroy_s
*/

#ifndef INDIE_CHUNK_HPP
#define INDIE_CHUNK_HPP

#include "Utils.hpp"
#include "Entity.hpp"

class Chunk : public Dimension, public Position
{
public:
	Chunk(BType EntityType = BOARD, Position Pos = (0, 0, 0));
	virtual ~Chunk();
	BType getEntityType() const;
	std::vector<Entity *> *getEntities() const;
	Position getPos();
	void setEntityType(BType EntityType);
	void setEntities(std::vector<Entity *> *Entities);
	void addEntity(BType EntityType);
	void print();
	void printIt();
private:
	BType EntityType;
	std::vector<Entity *> *Entities;
};

#endif //INDIE_CHUNK_HPP
