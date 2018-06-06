/*
** EPITECH PROJECT, 2017
** Indie
** File description:
** Created by nauroy_s
*/

#ifndef INDIE_ENTITY_HPP
#define INDIE_ENTITY_HPP

#include "Dimension.hpp"
#include "Position.hpp"
#include "Utils.hpp"
#include "Mesh.hpp"

class Entity : public Dimension, public Position
{
public:
	Entity(BType EntityType, Position Pos = (0, 0, 0));
	virtual ~Entity();
	BType getEntityType() const;
	Compass getFacing() const;
	Mesh *getSprite() const;
	void setEntityType(BType EntityType);
	void setFacing(Compass Facing);
	void setSprite(Mesh *sprite);
	void print();
protected:
	BType EntityType;
	Compass Facing;
	Mesh	*Sprite;

};

#endif //INDIE_ENTITY_HPP
