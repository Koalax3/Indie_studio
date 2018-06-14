/*
** EPITECH PROJECT, 2017
** Indie
** File description:
** Created by nauroy_s
*/

#include "Dimension.hpp"

Dimension::Dimension(absolute Length, absolute Depth, absolute Height) :
	Length(Length), Depth(Depth), Height(Height)
{}

Dimension::~Dimension()
{

}

absolute Dimension::getLength() const
{
	return Length;
}

absolute Dimension::getDepth() const
{
	return Depth;
}

absolute Dimension::getHeight() const
{
	return Height;
}

void Dimension::setLength(absolute Length)
{
	Dimension::Length = Length;
}

void Dimension::setDepth(absolute Depth)
{
	Dimension::Depth = Depth;
}

void Dimension::setHeight(absolute Height)
{
	Dimension::Height = Height;
}
