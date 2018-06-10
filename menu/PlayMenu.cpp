//
// EPITECH PROJECT, 2018
// PlayMenu.cpp
// File description:
// PlayMenu.cpp
//

#include "PlayMenu.hpp"

PlayMenu::PlayMenu(t_context &context) : _context(context)
{
	_context.button[ID_CONTINUED]->setVisible(false);
	_context.button[ID_PLAY]->setVisible(false);
	_context.button[ID_OPTION]->setVisible(false);
	_context.button[ID_QUIT]->setVisible(false);
	_context.button[ID_MAN1]->setVisible(true);
	_context.button[ID_MAN2]->setVisible(true);
	_context.button[ID_MAN3]->setVisible(true);
	_context.button[ID_MAN4]->setVisible(true);
	_context.button[ID_NEXT]->setVisible(true);
	_context.button[ID_BACK]->setVisible(true);
	_context.button[ID_START]->setVisible(false);
	_context.button[ID_PBACK]->setVisible(false);
	_context.button[ID_CLASSIC]->setVisible(false);
	_context.button[ID_MODERN]->setVisible(false);
	_context.button[ID_OBACK]->setVisible(false);
	_context.button[ID_P1]->setVisible(false);
	_context.button[ID_P2]->setVisible(false);
	_context.button[ID_P3]->setVisible(false);
	_context.button[ID_P4]->setVisible(false);
	_context.seed->setVisible(false);
}

PlayMenu::~PlayMenu()
{
}
