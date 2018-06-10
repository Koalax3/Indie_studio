/*
** EPITECH PROJECT, 2017
** Indie
** File description:
** Created by nauroy_s
*/

#include "Chunk.hpp"

Chunk::Chunk(BType EntityType, Position Pos) : EntityType(EntityType)
{
	X = Pos.getX();
	Y = Pos.getY();
	Z = Pos.getZ();
	Entities = new std::vector<Entity *>;
	Entities->push_back(new Entity(EntityType, Position(X, Y, Z)));
}

Chunk::~Chunk()
{

}

BType Chunk::getEntityType() const
{
	return EntityType;
}

std::vector<Entity *> *Chunk::getEntities() const
{
	return Entities;
}

void Chunk::setEntityType(BType EntityType)
{
	Chunk::EntityType = EntityType;
}

void Chunk::setEntities(std::vector<Entity *> *Entities)
{
	Chunk::Entities = Entities;
}

void Chunk::print()
{
	for (absolute i = 0; i < Entities->size(); i++)
		Entities->at(i)->print();
}

void Chunk::addEntity(BType EntityType)
{
	Entities->push_back(
		new Entity(EntityType, Position(X, Y,
						Entities->back()->getZ() +
						Entities->back()->getHeight())));
}

void Chunk::printIt()
{
	std::cout << ENTITY_DISPLAY[Entities->back()->getEntityType()];
}

Position Chunk::getPos()
{
	return Position(X, Y, Z);
}
