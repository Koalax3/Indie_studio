//
// EPITECH PROJECT, 2018
// MainMenu.hpp
// File description:
// MainMenu.hpp
//

#ifndef _MAINMENU_HPP_
#define _MAINMENU_HPP_

#include "indie.hpp"

enum Id {
	ID_CONTINUED = 101,
	ID_PLAY,
	ID_OPTION,
	ID_QUIT,
	ID_MAN1,
	ID_MAN2,
	ID_MAN3,
	ID_MAN4,
	ID_NEXT,
	ID_BACK,
	ID_START,
	ID_PBACK,
	ID_OBACK,
	ID_CLASSIC,
	ID_MODERN,
	ID_P1,
	ID_P2,
	ID_P3,
	ID_P4
};

typedef struct s_context {
	irr::IrrlichtDevice *device;
	irr::video::IVideoDriver *driver;
	irr::scene::ISceneManager *scene;
	irr::gui::IGUIEnvironment *gui;
	irr::gui::IGUIFont *font;
	std::map<int, irr::gui::IGUIButton *> button;
	irr::gui::IGUIEditBox *seed;
	int continued;
	int launch;
} t_context;

class MainMenu
{
public:
	MainMenu(t_context &);
	~MainMenu();
	void changeSize(core::dimension2d<u32> size);
private:
	t_context &_context;
};

#endif /* !_MAINMENU_HPP_ */
