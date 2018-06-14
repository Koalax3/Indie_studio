/*
** EPITECH PROJECT, 2017
** Indie
** File description:
** Created by nauroy_s
*/

#include "Entity.hpp"

Entity::Entity(BType EntityType, Position Pos) : EntityType(EntityType)
{
	if (EntityType == B_MAN) {
		Height = 2;
		Facing = DOWN;
	}
	if (EntityType == BOARD)
		Height = 0;
	X = Pos.getX();
	Y = Pos.getY();
	Z = Pos.getZ();
}

Entity::~Entity()
{

}

BType Entity::getEntityType() const
{
	return EntityType;
}

Compass Entity::getFacing() const
{
	return Facing;
}

void Entity::setEntityType(BType EntityType)
{
	Entity::EntityType = EntityType;
}

void Entity::setFacing(Compass Facing)
{
	Entity::Facing = Facing;
}

Mesh *Entity::getSprite() const
{
	return Sprite;
}

void Entity::setSprite(Mesh *sprite)
{
	Sprite = sprite;
}

void Entity::print()
{
	std::cout << ENTITY_TYPE[EntityType] << std::endl;
	std::cout << "Pos : " << X << " - " << Y << " - " << Z << std::endl;
	std::cout << "Dim : " << Length << " - " << Depth << " - " << Height
		  << std::endl;
}
