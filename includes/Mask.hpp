/*
** EPITECH PROJECT, 2017
** Indie
** File description:
** Created by nauroy_s
*/

#ifndef INDIE_MASK_HPP
#define INDIE_MASK_HPP

#include "Utils.hpp"

class Mask
{
public:
	Mask(absolute Size = 0);
	virtual ~Mask();
	std::vector<Compass> *getMaskFormat() const;
	void setMaskFormat(std::vector<Compass> *MaskFormat);
	void print();
	void reverse();
protected:
	int R;
	int U;
	std::vector<Compass> *MaskFormat;
};

#endif //INDIE_MASK_HPP
