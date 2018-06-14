/*
** EPITECH PROJECT, 2017
** Indie
** File description:
** Created by nauroy_s
*/

#ifndef INDIE_POSITION_HPP
#define INDIE_POSITION_HPP

class Position
{
public:
	Position(float X = 0, float Y = 0, float Z = 0);
	virtual ~Position();
	float getX() const;
	float getY() const;
	float getZ() const;
	Position getPosition();
	void setX(double X);
	void setY(double Y);
	void setZ(int Z);
	void setPosition(Position Pos);
	bool operator==(const Position &rhs) const;
	bool operator!=(const Position &rhs) const;
	void operator+(const Position &rhs);
	void operator-(const Position &rhs);
protected:
	float X;
	float Y;
	float Z;
};

#endif //INDIE_POSITION_HPP
