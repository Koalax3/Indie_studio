/*
** EPITECH PROJECT, 2017
** Indie
** File description:
** Created by nauroy_s
*/

#include "Position.hpp"

Position::Position(float X, float Y, float Z) : X(X), Y(Y), Z(Z)
{}

Position::~Position()
{

}

float Position::getX() const
{
	return X;
}

float Position::getY() const
{
	return Y;
}

float Position::getZ() const
{
	return Z;
}

void Position::setX(double X)
{
	Position::X = X;
}

void Position::setY(double Y)
{
	Position::Y = Y;
}

void Position::setZ(int Z)
{
	Position::Z = Z;
}

Position Position::getPosition()
{
	return Position(X, Y, Z);
}

void Position::setPosition(Position Pos)
{
	X = Pos.getX();
	Y = Pos.getY();
	Z = Pos.getZ();
}
