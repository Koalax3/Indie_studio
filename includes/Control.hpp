/*
** EPITECH PROJECT, 2018
** indie studio
** File description:
** Control.hpp
*/

#ifndef CONTROL_HPP_
#define CONTROL_HPP_

#include "indie.hpp"
#include "Player.hpp"
#include "Map.hpp"

class Control : public IEventReceiver
{
public:
	Control();
	~Control();
	bool OnEvent(const SEvent &event);
	bool IsKeyDown(EKEY_CODE keyCode) const;
	MType	ControlState();
	bool	ControlPlayer(Player *player);
	void IA(Player **player, int i, Map *map);
	Position findClosest(Player **player, int i);
	Compass findWay(Position start, Position target, Map *map);
	Compass flee(Position start, Position target, Map *map);
	double Euler(Position lhs, Position rhs);
private:
	double Time;
	bool KeyIsDown[KEY_KEY_CODES_COUNT];
	EKEY_CODE TouchPlayer[4][5];
};

#endif /* !CONTROL_HPP_ */
