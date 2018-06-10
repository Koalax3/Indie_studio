//
// EPITECH PROJECT, 2018
// MapMenu.hpp
// File description:
// MapMenu.hpp
//

#ifndef _MAPMENU_HPP_
# define _MAPMENU_HPP_

#include "MenuEvent.hpp"
#include "indie.hpp"

class MapMenu
{
public:
	MapMenu(t_context &);
	~MapMenu();

private:
	t_context &_context;
};

#endif /* !_MAPMENU_HPP_ */
