//
// EPITECH PROJECT, 2018
// MenuEvent.cpp
// File description:
// MenuEvent.cpp
//

#include "MenuEvent.hpp"

MenuEvent::MenuEvent(t_context &context) : _context(context)
{
}

bool MenuEvent::OnEvent(const irr::SEvent &event)
{
	irr::s32 id;

	if (event.EventType == irr::EET_GUI_EVENT) {
		id = event.GUIEvent.Caller->getID();
		switch (event.GUIEvent.EventType) {
		case irr::gui::EGET_BUTTON_CLICKED:
			switch (id) {
			case ID_PLAY:
				callPlayMenu();
				return (true);
			case ID_OPTION:
				callOptionMenu();
				return (true);
			case ID_QUIT:
				_context.device->closeDevice();
				return (true);
			case ID_NEXT:
				callMapMenu();
				return (true);
			case ID_BACK:
				callMainMenu();
				return (true);
			case ID_OBACK:
				callMainMenu();
				return (true);
			case ID_PBACK:
				callPlayMenu();
				return (true);
			case ID_START:
				_context.launch = 1;
				return (true);
			default:
				return (false);
			}
		default:
			break;
		}
	}
	return (false);
}

void MenuEvent::callMainMenu()
{
	MainMenu menu(_context);
}

void MenuEvent::callPlayMenu()
{
	PlayMenu menu(_context);
}

void MenuEvent::callMapMenu()
{
	MapMenu menu(_context);
}

void MenuEvent::callOptionMenu()
{
	OptionMenu menu(_context);
}
