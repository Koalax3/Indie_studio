/*
** EPITECH PROJECT, 2017
** Indie
** File description:
** Created by nauroy_s
*/

#ifndef INDIE_RANGE_HPP
#define INDIE_RANGE_HPP

class Range
{
public:
	Range(int Min = 0, int Max = 0);
	virtual ~Range();
	int getMin() const;
	int getMax() const;
	void setMin(int Min);
	void setMax(int Max);
	void print();
protected:
	int Min;
	int Max;
};

#endif //INDIE_RANGE_HPP
