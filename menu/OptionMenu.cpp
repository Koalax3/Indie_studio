//
// EPITECH PROJECT, 2018
// OptionMenu.cpp
// File description:
// OptionMenu.cpp
//

#include "OptionMenu.hpp"

OptionMenu::OptionMenu(t_context &context) : _context(context)
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
	_context.button[ID_START]->setVisible(false);
	_context.button[ID_PBACK]->setVisible(false);
	_context.button[ID_CLASSIC]->setVisible(false);
	_context.button[ID_MODERN]->setVisible(false);
	_context.button[ID_OBACK]->setVisible(true);
	_context.button[ID_P1]->setVisible(true);
	_context.button[ID_P2]->setVisible(true);
	_context.button[ID_P3]->setVisible(true);
	_context.button[ID_P4]->setVisible(true);
	_context.seed->setVisible(false);
}

OptionMenu::~OptionMenu()
{
}
