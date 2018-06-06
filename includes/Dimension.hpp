/*
** EPITECH PROJECT, 2017
** Indie
** File description:
** Created by nauroy_s
*/

#ifndef INDIE_DIMENSION_HPP
#define INDIE_DIMENSION_HPP

#include "Utils.hpp"

class Dimension
{
public:
	Dimension(absolute Length = 1, absolute Depth = 1, absolute Height = 1);
	virtual ~Dimension();
	absolute getLength() const;
	absolute getDepth() const;
	absolute getHeight() const;
	void setLength(absolute Length);
	void setDepth(absolute Depth);
	void setHeight(absolute Height);
protected:
	absolute Length;
	absolute Depth;
	absolute Height;
};

#endif //INDIE_DIMENSION_HPP
