/*
** EPITECH PROJECT, 2018
** indie studio
** File description:
** Control.hpp
*/

#ifndef CONTROL_HPP_
#define CONTROL_HPP_

#include "indie.hpp"
#include "Player.hpp"

class Control : public IEventReceiver
{
      public:
	Control();
	~Control();
	bool OnEvent(const SEvent &event);
	bool IsKeyDown(EKEY_CODE keyCode) const;
	MType	ControlState();
	void	ControlPlayer(Player *player);
	

      private:
	bool KeyIsDown[KEY_KEY_CODES_COUNT];
};

#endif /* !CONTROL_HPP_ */
