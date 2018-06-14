/*
** EPITECH PROJECT, 2017
** Indie
** File description:
** Created by nauroy_s
*/

#include <iostream>
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

bool Position::operator==(const Position &rhs) const
{
	bool x = (int)X == (int)rhs.X &&
	(int)Y == (int)rhs.Y &&
	(int)Z == (int)rhs.Z;
	return (int)X == (int)rhs.X &&
		(int)Y == (int)rhs.Y &&
		(int)Z == (int)rhs.Z;
}

bool Position::operator!=(const Position &rhs) const
{
	return !(rhs == *this);
}

void Position::operator+(const Position &rhs)
{
	X += rhs.getX();
	Y += rhs.getY();
	Z += rhs.getZ();
}

void Position::operator-(const Position &rhs)
{
	X -= rhs.getX();
	Y -= rhs.getY();
	Z -= rhs.getZ();
}
