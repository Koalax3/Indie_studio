//
// EPITECH PROJECT, 2018
// MainMenu.cpp
// File description:
// MainMenu.cpp
//

#include "MainMenu.hpp"

MainMenu::MainMenu(t_context &context) : _context(context)
{
	if (_context.continued != 0)
		_context.button[ID_CONTINUED]->setVisible(true);
	else
		_context.button[ID_CONTINUED]->setVisible(false);
	_context.button[ID_PLAY]->setVisible(true);
	_context.button[ID_OPTION]->setVisible(true);
	_context.button[ID_QUIT]->setVisible(true);
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
	_context.button[ID_OBACK]->setVisible(false);
	_context.button[ID_P1]->setVisible(false);
	_context.button[ID_P2]->setVisible(false);
	_context.button[ID_P3]->setVisible(false);
	_context.button[ID_P4]->setVisible(false);
	_context.seed->setVisible(false);
}

MainMenu::~MainMenu()
{
}

void MainMenu::changeSize(core::dimension2d<u32> size)
{
	_context.button[ID_CONTINUED]->setRelativePosition(irr::core::rect<irr::s32>(
	size.Width / 2 - 100, size.Height / 2 - 150,
	size.Width / 2 + 100, size.Height / 2 - 150 + 50));
	_context.button[ID_PLAY]->setRelativePosition(irr::core::rect<irr::s32>(
	size.Width / 2 - 100, size.Height / 2 - 50,
	size.Width / 2 + 100, size.Height / 2 - 50 + 50));
	_context.button[ID_OPTION]->setRelativePosition(irr::core::rect<irr::s32>(
	size.Width / 2 - 100, size.Height / 2 + 50,
	size.Width / 2 + 100, size.Height / 2 + 50 + 50));
	_context.button[ID_QUIT]->setRelativePosition(irr::core::rect<irr::s32>(
	size.Width / 2 - 100, size.Height / 2 + 150,
	size.Width / 2 + 100, size.Height / 2 + 150 + 50));
	_context.button[ID_MAN1]->setRelativePosition(irr::core::rect<irr::s32>(
	75, 75,
	375, 75 + 200));
	_context.button[ID_MAN2]->setRelativePosition(irr::core::rect<irr::s32>(
	size.Width - 375, 75,
	size.Width - 75, 75 + 200));
	_context.button[ID_MAN3]->setRelativePosition(irr::core::rect<irr::s32>(
	75, size.Height - 75 - 200,
	375, size.Height - 75));
	_context.button[ID_MAN4]->setRelativePosition(irr::core::rect<irr::s32>(
	size.Width - 375, size.Height - 75 - 200,
	size.Width - 75, size.Height - 75));
	_context.button[ID_NEXT]->setRelativePosition(irr::core::rect<irr::s32>(
	size.Width / 2 - 75, size.Height / 2 - 75,
	size.Width / 2 + 75, size.Height / 2 - 75 + 40));
	_context.button[ID_BACK]->setRelativePosition(irr::core::rect<irr::s32>(
	size.Width / 2 - 75, size.Height / 2,
	size.Width / 2 + 75, size.Height / 2 + 40));
	_context.button[ID_START]->setRelativePosition(irr::core::rect<irr::s32>(
	size.Width / 2 - 75, size.Height - 150,
	size.Width / 2 + 75, size.Height - 150 + 40));
	_context.button[ID_PBACK]->setRelativePosition(irr::core::rect<irr::s32>(
	size.Width / 2 - 75, size.Height - 100,
	size.Width / 2 + 75, size.Height - 100 + 40));
	_context.button[ID_CLASSIC]->setRelativePosition(irr::core::rect<irr::s32>(
	75, size.Height / 2 - 150,
	size.Width / 2 - 75, size.Height / 2 - 150 + 300));
	_context.button[ID_MODERN]->setRelativePosition(irr::core::rect<irr::s32>(
	size.Width / 2 + 75, size.Height / 2 + 150 - 300,
	size.Width - 75, size.Height / 2 + 150));
	_context.button[ID_OBACK]->setRelativePosition(irr::core::rect<irr::s32>(
	size.Width / 2 - 75, size.Height / 2 + 200,
	size.Width / 2 + 75, size.Height / 2 + 200 + 50));
	_context.button[ID_P1]->setRelativePosition(irr::core::rect<irr::s32>(
	size.Width / 2 - 500, size.Height / 2 - 300,
	size.Width / 2 - 300, size.Height / 2 - 300 + 50));
	_context.button[ID_P2]->setRelativePosition(irr::core::rect<irr::s32>(
	size.Width / 2 - 500, size.Height / 2 - 200,
	size.Width / 2 - 300, size.Height / 2 - 200 + 50));
	_context.button[ID_P3]->setRelativePosition(irr::core::rect<irr::s32>(
	size.Width / 2 - 500, size.Height / 2 - 100,
	size.Width / 2 - 300, size.Height / 2 - 100 + 50));
	_context.button[ID_P4]->setRelativePosition(irr::core::rect<irr::s32>(
	size.Width / 2 - 500, size.Height / 2,
	size.Width / 2 - 300, size.Height / 2 + 50));
	_context.seed->setRelativePosition(irr::core::rect<irr::s32>(
	size.Width / 2 + 75, 20,
	size.Width - 75, 70));
}
