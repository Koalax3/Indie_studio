/*
** EPITECH PROJECT, 2017
** Indie
** File description:
** Created by nauroy_s
*/

#include "Mask.hpp"

Mask::Mask(absolute Size)
{
	MaskFormat = new std::vector<Compass>;
	int i = -1;
	R = U = 0;
	Compass tmp;
	while (++i < Size * 2 && R < Size && U < Size) {
		tmp = (Compass) (std::rand() % 2 + 3);
		MaskFormat->push_back(tmp);
		if (tmp == 3)
			R++;
		else
			U++;
	}
	while (R < U) {
		MaskFormat->push_back(RIGHT);
		R++;
	}
	while (U < R) {
		MaskFormat->push_back(UP);
		U++;
	}
}

Mask::~Mask()
{

}

std::vector<Compass> *Mask::getMaskFormat() const
{
	return MaskFormat;
}

void Mask::setMaskFormat(std::vector<Compass> *MaskFormat)
{
	Mask::MaskFormat = MaskFormat;
}

void Mask::print()
{
	std::cout << "Mask : ";
	for (int i = 0; i < MaskFormat->size(); i++)
		std::cout << COMPASS[MaskFormat->at(i)] << " ";
	std::cout << std::endl;
	std::cout << "( R : " << R << " - U : " << U << " )" << std::endl;
}

void Mask::reverse()
{
	for (int i = 0; i < MaskFormat->size(); i++) {
		MaskFormat->at(i) = (Compass) ((MaskFormat->at(i) % 2) + 3);
	}
}
