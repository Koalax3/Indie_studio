//
// Created by depret-l on 15/05/18.
//

#ifndef INDIE_CORE_HPP
#define INDIE_CORE_HPP

#include "Camera.hpp"
#include "Mesh.hpp"
#include "Terrain.hpp"
#include "Control.hpp"
#include "Entity.hpp"
#include "Map.hpp"

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
	MType loopArena(int size, MapPath Path);

private:
	IrrlichtDevice *device;
	IVideoDriver *driver;
	ISceneManager *smgr;
	IGUIEnvironment *guienv;
	Camera *camera;
	Terrain *Background;
	scene::IMetaTriangleSelector *metaSelector;
	Control Controller;
	MType State;
	Map *Arena;	
	Player *Bomberman[4];
};

#endif //INDIE_CORE_HPP
