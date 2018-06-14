/*
** EPITECH PROJECT, 2018
** indie studio
** File description:
** Control.cpp
*/

#include "Control.hpp"

Control::Control()
{
	for (u32 i = 0; i < KEY_KEY_CODES_COUNT; ++i)
		KeyIsDown[i] = false;
	for (int i = 0; i < 4; i++)
		for (int y = 0; y < 5; y++)
			TouchPlayer[i][y] = DEFAULTCONTROL[i][y];
	Time = time(nullptr);
}

Control::~Control()
{
}

bool Control::OnEvent(const SEvent &event)
{
	if (event.EventType == irr::EET_KEY_INPUT_EVENT)
		KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
	return false;
}

bool Control::IsKeyDown(EKEY_CODE keyCode) const
{
	return KeyIsDown[keyCode];
}

bool	Control::ControlPlayer(Player *player)
{
	bool boom = false;
	if (IsKeyDown(TouchPlayer[player->getId()][0]))
		player->MoveUp(0.1);	
	if (IsKeyDown(TouchPlayer[player->getId()][1]))
		player->MoveLeft(0.1);		
	if (IsKeyDown(TouchPlayer[player->getId()][2]))
		player->MoveDown(0.1);		
	if (IsKeyDown(TouchPlayer[player->getId()][3]))
		player->MoveRight(0.1);
	if (IsKeyDown(TouchPlayer[player->getId()][4])) {
		if (player->DropBomb())
			boom = true;
	}
	return boom;
}

MType	Control::ControlState()
{
	if (IsKeyDown(KEY_KEY_R))
		return ARENA;
	if (IsKeyDown(KEY_ESCAPE))
		return END;
	return RUN;
}

void Control::IA(Player **player, int i, Map *map)
{
	Player *tmp = player[i];
	tmp->setPosition(Position(player[i]->getX() / 2, player[i]->getZ() / 2));

	Position target = findClosest(player, i);
	Compass way = findWay(tmp->getPosition(), target, map);
	if (!tmp->getStockBomb()->empty()) {
		way = UP;
		if (player[i]->getFacing() == RIGHT)
			way = LEFT;
		else if (player[i]->getFacing() == LEFT)
			way = RIGHT;
		else if (player[i]->getFacing() == UP)
			way = DOWN;
		player[i]->Move(way, 0.1);
	} else if (abs(player[i]->getX()) < map->getMax() &&
		   abs(player[i]->getY()) < map->getMax() &&
		   map->getChunk(player[i]->getFront(way))->getEntities()->back
		()->getEntityType() == BOX && player[i]->getLifeTimer() -
					      time(nullptr) < -4 && player[i]->isLife()) {
		player[i]->DropBomb();
		player[i]->setFacing(way);
	}
	player[i]->Move(way, 0.1);
}

Position Control::findClosest(Player **player, int i)
{
	auto tmp = player[i]->getPosition();
	tmp.setPosition(Position((int)player[i]->getX() / 2,
				  (int)player[i]->getZ() / 2));

	Position pos(0, 0, 0);
	for (int p = 0; p < 4; p++) {
		if (Euler(tmp.getPosition(),
			  Position((int)player[p]->getX() / 2,
				   (int)player[p]->getZ() / 2)) <
		    Euler(tmp.getPosition(), pos)) {
			pos.setPosition(Position((int)player[p]->getX()
						 / 2,
						 (int)player[p]->getZ
								       () / 2));
		}
	}
	return pos;
}

double Control::Euler(Position lhs, Position rhs)
{
	return sqrt(pow(rhs.getX() - lhs.getX(), 2) +
		    pow(rhs.getY() - lhs.getY(), 2));
}

Compass Control::findWay(Position start, Position target, Map *map)
{
	Position direct((target.getX() - start.getX()) /
			Euler(start.getPosition(), target.getPosition()),
			(target.getY() - start.getY()) /
			Euler(start.getPosition(), target.getPosition()));
	if (abs(direct.getX()) >= abs(direct.getY())) {
		if (direct.getX() >= 0 && map->getChunk(Position(start.getX()
								 + 1, start.getY()))->getEntities()->back()->getEntityType() != BRICK)
			return RIGHT;
		else
			return LEFT;
	} else if (direct.getY() >= 0 && map->getChunk(Position(start.getX(),
								start.getY() + 1))->getEntities()->back()->getEntityType() != BRICK)
		return UP;
	else
		return DOWN;
}