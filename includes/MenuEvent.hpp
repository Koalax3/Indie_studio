//
// EPITECH PROJECT, 2018
// MenuEvent.hpp
// File description:
// MenuEvent.hpp
//

#ifndef _MENUEVENT_HPP_
# define _MENUEVENT_HPP_
#include "Utils.hpp"
#include "MainMenu.hpp"
#include "PlayMenu.hpp"
#include "MapMenu.hpp"
#include "OptionMenu.hpp"

class MenuEvent : public irr::IEventReceiver
{
public:
	MenuEvent(t_context &);
	virtual bool OnEvent(const irr::SEvent &);
	void callMainMenu();
	void callPlayMenu();
	void callMapMenu();
	void callOptionMenu();

private:
	t_context &_context;
};

#endif /* !_MENUEVENT_HPP_ */
