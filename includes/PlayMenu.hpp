//
// EPITECH PROJECT, 2018
// PlayMenu.hpp
// File description:
// PlayMenu.hpp
//

#ifndef _PLAYMENU_HPP_
# define _PLAYMENU_HPP_

#include "MenuEvent.hpp"
#include "indie.hpp"

class PlayMenu
{
public:
	PlayMenu(t_context &);
	~PlayMenu();

private:
	t_context &_context;
};

#endif /* !_PLAYMENU_HPP_ */
