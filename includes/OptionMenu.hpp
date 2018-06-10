//
// EPITECH PROJECT, 2018
// OptionMenu.hpp
// File description:
// OptionMenu.hpp
//

#ifndef _OPTIONMENU_HPP_
# define _OPTIONMENU_HPP_

#include "MenuEvent.hpp"
#include "indie.hpp"

class OptionMenu
{
public:
	OptionMenu(t_context &);
	~OptionMenu();

private:
	t_context &_context;
};

#endif /* !_OPTIONMENU_HPP_ */
