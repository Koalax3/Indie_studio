//
// EPITECH PROJECT, 2018
// MapMenu.cpp
// File description:
// MapMenu.cpp
//

#include "MapMenu.hpp"

MapMenu::MapMenu(t_context &context) : _context(context)
{
	_context.button[ID_CONTINUED]->setVisible(false);
	_context.button[ID_PLAY]->setVisible(false);
	_context.button[ID_OPTION]->setVisible(false);
	_context.button[ID_QUIT]->setVisible(false);
	_context.button[ID_MAN1]->setVisible(false);
	_context.button[ID_MAN2]->setVisible(false);
	_context.button[ID_MAN3]->setVisible(false);
	_context.button[ID_MAN4]->setVisible(false);
	_context.button[ID_NEXT]->setVisible(false);
	_context.button[ID_BACK]->setVisible(false);
	_context.button[ID_START]->setVisible(true);
	_context.button[ID_PBACK]->setVisible(true);
	_context.button[ID_CLASSIC]->setVisible(true);
	_context.button[ID_MODERN]->setVisible(true);
	_context.button[ID_OBACK]->setVisible(false);
	_context.button[ID_P1]->setVisible(false);
	_context.button[ID_P2]->setVisible(false);
	_context.button[ID_P3]->setVisible(false);
	_context.button[ID_P4]->setVisible(false);
	_context.seed->setVisible(true);
}

MapMenu::~MapMenu()
{
}
