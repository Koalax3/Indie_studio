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

void	Control::ControlPlayer(Player *player)
{
	if (IsKeyDown(KEY_RIGHT))
		player->MoveRight(0.1);
	if (IsKeyDown(KEY_LEFT))
		player->MoveLeft(0.1);		
	if (IsKeyDown(KEY_UP))
		player->MoveUp(0.1);		
	if (IsKeyDown(KEY_DOWN))
		player->MoveDown(0.1);		
	if (IsKeyDown(KEY_SPACE))
		player->DropBomb();	
}

MType	Control::ControlState()
{
	if (IsKeyDown(KEY_KEY_R))
		return ARENA;
	if (IsKeyDown(KEY_ESCAPE))
		return END;
	return RUN;
}