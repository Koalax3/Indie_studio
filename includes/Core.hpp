/*
** EPITECH PROJECT, 2018
** indie studio
** File description:
** Core.hpp
*/

#ifndef INDIE_CORE_HPP
#define INDIE_CORE_HPP

#include "Camera.hpp"
#include "Mesh.hpp"
#include "Terrain.hpp"
#include "Control.hpp"
#include "Entity.hpp"
#include "Map.hpp"
#include "MenuEvent.hpp"

class Core
{
public:
	Core();
	virtual ~Core();
	E_DRIVER_TYPE driverChoiceConsole();
	IVideoDriver *getDriver() const;
	ISceneManager *getScene() const;
	scene::IMetaTriangleSelector *getSelector() const;
	void windowFPS();
	void initBomberman(int size);
	void buttonSkin(t_context &context);
	t_context getContext();
	void callMainMenu(t_context &);	
	void CreateArena(int size, MapPath Path);
	MType loopArena(int size, MapPath Path);
	MType loopMenu();
	int isVictory();
	void CheckBombs(int i);
	void GiveCollision();
private:
	IrrlichtDevice *device;
	IVideoDriver *driver;
	ISceneManager *smgr;
	IGUIEnvironment *guienv;
	IGUIFont *font;
	Camera *camera;
	Terrain *Background;
	scene::IMetaTriangleSelector *metaSelector;
	Control Controller;
	MType State;
	Map *Arena;	
	Player *Bomberman[4];
	int Winner;
	
	MainMenu *menu;
};

#endif //INDIE_CORE_HPP
