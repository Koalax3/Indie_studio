//
// Created by depret-l on 15/05/18.
//

#include "Core.hpp"

Core::Core()
{
	E_DRIVER_TYPE driverType = driverChoiceConsole();
	if (driverType == EDT_NULL)
		exit(1);
	device = createDevice(driverType, dimension2d<u32>(RES_WIDTH, RES_HEIGHT), 16,
			      false, false, false, &Controller);
	if (!device)
		exit(1);
	device->setWindowCaption(L"Bomberman");
	driver = device->getVideoDriver();
	smgr = device->getSceneManager();
	guienv = device->getGUIEnvironment();
	metaSelector = smgr->createMetaTriangleSelector();
	Background = new Terrain(*smgr, *driver, "media/weed.jpg");	
}

Core::~Core()
{
	smgr->drop();
	driver->drop();
	guienv->drop();
}

E_DRIVER_TYPE Core::driverChoiceConsole()
{
	std::cout << "Please select the driver you want for this example:\n ("
		     "a) OpenGL 1.5\n (b) Direct3D 9.0c\n (c) Direct3D 8.1\n ("
		     "d) Burning's Software Renderer\n (e) Software Renderer\n"
		     " (otherKey) exit\n$> ";
	char i;
	std::cin >> i;
	switch (i) {
	case 'a':
		return video::EDT_OPENGL;
	case 'b':
		return video::EDT_DIRECT3D9;
	case 'c':
		return video::EDT_DIRECT3D8;
	case 'd':
		return video::EDT_BURNINGSVIDEO;
	case 'e':
		return video::EDT_SOFTWARE;
	default:
		return video::EDT_NULL;
	}
}

IVideoDriver *Core::getDriver() const
{
	return driver;
}
ISceneManager *Core::getScene() const
{
	return smgr;
}
scene::IMetaTriangleSelector *Core::getSelector() const
{
	return metaSelector;
}

void Core::windowFPS()
{
	int fps = driver->getFPS();
	core::stringw tmp(L"Bomberman[");
	tmp += driver->getName();
    	tmp += L"] fps: ";
   	tmp += fps;
  	device->setWindowCaption(tmp.c_str());
}

void Core::initBomberman(int size)
{
	int posx[4] = {(size-2), (-size+2), (size-2), (-size+2)};
	int posy[4] = {(size-2), (size-2), (-size+2), (-size+2)};
	for (int i = 0; i < 4; i++) {
		Bomberman[i] = new Player(*smgr, *driver, Position(posx[i], 0.5, posy[i]));
		Bomberman[i]->addSprite(i);
	}
}

MType Core::loopArena(int size, MapPath Path)
{
	//Mesh *mesh = new Mesh(*smgr, AMESH);
	//mesh->addTexture(*driver, ATEXTURE);
	//mesh->getNode()->setScale(core::vector3df(5,5,5));
	Arena = new Map(size);
	initBomberman(size);
	Arena->MapGenGui(*smgr, *driver, Path);
	metaSelector->removeAllTriangleSelectors();
	Arena->MapCollision(*metaSelector);
	Background->addCollision(*metaSelector);
	camera = new Camera(*smgr, 0.01, ARENA);
	Bomberman[0]->getSprite()->applyCollision(metaSelector);
	while (device->run()) {
		driver->beginScene(true, true, SColor(255, 64, 115, 158));
		smgr->drawAll();
		guienv->drawAll();
		driver->endScene();
		windowFPS();
		Controller.ControlPlayer(Bomberman[0]);
		State = Controller.ControlState();
		if (State != RUN) {
			smgr->clear();
			Background->applyScene();
			return State;
		}

	}
}