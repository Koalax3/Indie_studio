/*
** EPITECH PROJECT, 2017
** Indie
** File description:
** Created by nauroy_s
*/

#include <iostream>
#include "Range.hpp"

Range::Range(int Min, int Max) : Min(Min), Max(Max)
{}

Range::~Range()
{

}

int Range::getMin() const
{
	return Min;
}

int Range::getMax() const
{
	return Max;
}

void Range::setMin(int Min)
{
	Range::Min = Min;
}

void Range::setMax(int Max)
{
	Range::Max = Max;
}

void Range::print()
{
	std::cout << "Range : [" << Min << "] - [" << Max << "]" << std::endl;
}
