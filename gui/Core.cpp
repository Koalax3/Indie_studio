/*
** EPITECH PROJECT, 2018
** indie studio
** File description:
** Core.cpp
*/

#include "Core.hpp"
#include "MainMenu.hpp"

Core::Core()
{
	E_DRIVER_TYPE driverType = driverChoiceConsole();

	if (driverType == EDT_NULL)
		exit(1);
	device = createDevice(driverType, dimension2d<u32>
	(RES_WIDTH, RES_HEIGHT), 16, false, false, false);
	if (!device)
		exit(1);
	device->setWindowCaption(L"Bomberman");
	driver = device->getVideoDriver();
	smgr = device->getSceneManager();
	guienv = device->getGUIEnvironment();
	metaSelector = smgr->createMetaTriangleSelector();
	Background = new Terrain(*smgr, *driver, "media/menu.jpg");
	font = guienv->getFont("media/bomberfont.xml");
	guienv->getSkin()->setFont(guienv->getFont("media/bomberfont.xml"),
		irr::gui::EGDF_BUTTON);
	guienv->getSkin()->setColor(irr::gui::EGDC_BUTTON_TEXT, SColor(255,
		255, 255, 255));
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
	int posx[4] = {(size - 3), (-size + 3), (size - 3), (-size + 3)};
	int posy[4] = {(size - 3), (size - 3), (-size + 3), (-size + 3)};
	for (int i = 0; i < 4; i++) {
		Bomberman[i] = new Player(*smgr, *driver, Position(posx[i], 0.5, posy[i]));
		Bomberman[i]->addSprite(i);
		Bomberman[i]->setId(i);
	}
}

t_context Core::getContext()
{
	t_context context;

	context.device = device;
	context.driver = driver;
	context.scene = smgr;
	context.gui = guienv;
	context.font = font;
	context.button[ID_CONTINUED] = context.gui->addButton(
		irr::core::rect<irr::s32>(
			RES_WIDTH / 2 - 100, RES_HEIGHT / 2 - 150,
			RES_WIDTH / 2 + 100, RES_HEIGHT / 2 - 150 + 50), 0, ID_CONTINUED, L"CONTINUED");
	context.button[ID_PLAY] = context.gui->addButton(
		irr::core::rect<irr::s32>(
			RES_WIDTH / 2 - 100, RES_HEIGHT / 2 - 50,
			RES_WIDTH / 2 + 100, RES_HEIGHT / 2 - 50 + 50), 0, ID_PLAY, L"NEW");
	context.button[ID_OPTION] = context.gui->addButton(
		irr::core::rect<irr::s32>(
			RES_WIDTH / 2 - 100, RES_HEIGHT / 2 + 50,
			RES_WIDTH / 2 + 100, RES_HEIGHT / 2 + 50 + 50), 0, ID_OPTION, L"OPTION");
	context.button[ID_QUIT] = context.gui->addButton(
		irr::core::rect<irr::s32>(
			RES_WIDTH / 2 - 100, RES_HEIGHT / 2 + 150,
			RES_WIDTH / 2 + 100, RES_HEIGHT / 2 + 150 + 50), 0, ID_QUIT, L"QUIT");
	context.button[ID_MAN1] = context.gui->addButton(
		irr::core::rect<irr::s32>(
			75, 75,
			375, 75 + 200), 0, ID_MAN1, L"man 1");
	context.button[ID_MAN2] = context.gui->addButton(
		irr::core::rect<irr::s32>(
			RES_WIDTH - 375, 75,
			RES_WIDTH - 75, 75 + 200), 0, ID_MAN2, L"man 2");
	context.button[ID_MAN3] = context.gui->addButton(
		irr::core::rect<irr::s32>(
			75, RES_HEIGHT - 75 - 200,
			375, RES_HEIGHT - 75), 0, ID_MAN3, L"man 3");
	context.button[ID_MAN4] = context.gui->addButton(
		irr::core::rect<irr::s32>(
			RES_WIDTH - 375, RES_HEIGHT - 75 - 200,
			RES_WIDTH - 75, RES_HEIGHT - 75), 0, ID_MAN4, L"man 4");
	context.button[ID_NEXT] = context.gui->addButton(
		irr::core::rect<irr::s32>(
			RES_WIDTH / 2 - 75, RES_HEIGHT / 2 - 75,
			RES_WIDTH / 2 + 75, RES_HEIGHT / 2 - 75 + 40), 0, ID_NEXT, L"NEXT");
	context.button[ID_BACK] = context.gui->addButton(
		irr::core::rect<irr::s32>(
			RES_WIDTH / 2 - 75, RES_HEIGHT / 2,
			RES_WIDTH / 2 + 75, RES_HEIGHT / 2 + 40), 0, ID_BACK, L"BACK");
	context.button[ID_START] = context.gui->addButton(
		irr::core::rect<irr::s32>(
			RES_WIDTH / 2 - 75, RES_HEIGHT - 150,
			RES_WIDTH / 2 + 75, RES_HEIGHT - 150 + 40), 0, ID_START, L"START");
	context.button[ID_PBACK] = context.gui->addButton(
		irr::core::rect<irr::s32>(
			RES_WIDTH / 2 - 75, RES_HEIGHT - 100,
			RES_WIDTH / 2 + 75, RES_HEIGHT - 100 + 40), 0, ID_PBACK, L"BACK");
	context.button[ID_CLASSIC] = context.gui->addButton(
		irr::core::rect<irr::s32>(
			75, RES_HEIGHT / 2 - 150,
			RES_WIDTH / 2 - 75, RES_HEIGHT / 2 - 150 + 300), 0, ID_CLASSIC, L"CLASSIC");
	context.button[ID_MODERN] = context.gui->addButton(
		irr::core::rect<irr::s32>(
			RES_WIDTH / 2 + 75, RES_HEIGHT / 2 + 150 - 300,
			RES_WIDTH - 75, RES_HEIGHT / 2 + 150), 0, ID_MODERN, L"MODERN");
	context.button[ID_OBACK] = context.gui->addButton(
		irr::core::rect<irr::s32>(
			RES_WIDTH / 2 - 75, RES_HEIGHT / 2 + 200,
			RES_WIDTH / 2 + 75, RES_HEIGHT / 2 + 200 + 50), 0, ID_OBACK, L"BACK");
	context.button[ID_P1] = context.gui->addButton(
		irr::core::rect<irr::s32>(
			RES_WIDTH / 2 - 500, RES_HEIGHT / 2 - 300,
			RES_WIDTH / 2 - 300, RES_HEIGHT / 2 - 300 + 50), 0, ID_P1, L"PLAYER 1");
	context.button[ID_P2] = context.gui->addButton(
		irr::core::rect<irr::s32>(
			RES_WIDTH / 2 - 500, RES_HEIGHT / 2 - 200,
			RES_WIDTH / 2 - 300, RES_HEIGHT / 2 - 200 + 50), 0, ID_P2, L"PLAYER 2");
	context.button[ID_P3] = context.gui->addButton(
		irr::core::rect<irr::s32>(
			RES_WIDTH / 2 - 500, RES_HEIGHT / 2 - 100,
			RES_WIDTH / 2 - 300, RES_HEIGHT / 2 - 100 + 50), 0, ID_P3, L"PLAYER 3");
	context.button[ID_P4] = context.gui->addButton(
		irr::core::rect<irr::s32>(
			RES_WIDTH / 2 - 500, RES_HEIGHT / 2,
			RES_WIDTH / 2 - 300, RES_HEIGHT / 2 + 50), 0, ID_P4, L"PLAYER 4");
	context.seed = context.gui->addEditBox(
		L"Enter seed", irr::core::rect<irr::s32>(RES_WIDTH / 2 + 75, 20,
							 RES_WIDTH - 75, 70));
	context.seed->setOverrideFont(context.font);
	context.launch = 0;
	context.continued = 0;
	return (context);
}

void Core::callMainMenu(t_context &context)
{
	menu = new MainMenu(context);
}

void Core::buttonSkin(t_context &context)
{
	int counter = ID_CONTINUED;

	while (counter < ID_P4 + 1) {
		context.button[counter]->setImage(context.driver->getTexture("media/button.jpg"));
		context.button[counter]->setUseAlphaChannel(true);
		context.button[counter]->setDrawBorder(0);
		counter++;
	}
}

MType Core::loopMenu()
{
	IGUIStaticText *title = guienv->addStaticText(L"BomberMan\nMercury Edition", irr::core::rect<irr::s32>(
			RES_WIDTH / 2 - 100, RES_HEIGHT / 2 - 200,
			RES_WIDTH / 2 + 250, RES_HEIGHT / 2 - 200 +150));
	camera = new Camera(*smgr, 0.01, MENU);
	Mesh *mesh = new Mesh(*smgr, BMESHIDLE, core::vector3df(5, 1, 7));
	mesh->addTexture(*driver, BTEXTURE[6]);
	mesh->getNode()->setScale(core::vector3df(1.5,1.5,1.5));
	t_context context = getContext();
	title->setOverrideFont(context.font);
	MenuEvent event(context);

	buttonSkin(context);
	callMainMenu(context);
	device->setEventReceiver(&event);
	mesh->setRot(275, 24, 298);
	while (device->run() && context.launch == 0) {
		menu->changeSize(driver->getScreenSize());
		driver->beginScene(true, true, SColor(255, 64, 115, 158));
		smgr->drawAll();
		guienv->drawAll();
		driver->endScene();
	}
	mesh->getNode()->setVisible(false);
	if (context.launch != 0)
		return ARENA;
	return END;
}

void Core::GiveCollision()
{
	metaSelector->removeAllTriangleSelectors();
	Arena->MapCollision(*metaSelector);
	Background->addCollision(*metaSelector);
	Bomberman[0]->getSprite()->applyCollision(metaSelector);
	Bomberman[1]->getSprite()->applyCollision(metaSelector);
}
void Core::CreateArena(int size, MapPath Path)
{
	guienv->clear();
	device->setEventReceiver(&Controller);
	Background->changeTexture("media/lava.jpeg", 0.5);
	Arena = new Map(size, 0, RANDOM);
	initBomberman(Arena->getSize());
	Arena->MapGenGui(*smgr, *driver, Path);
	GiveCollision();
	camera = new Camera(*smgr, 0.01, ARENA);
}

int Core::isVictory()
{
	int i;
	int id = -1;
	int life = 0;
	for(i = 0; i < 4; i++) {
		if(Bomberman[i]->isLife() == true) {
			id = Bomberman[i]->getId();
			life++;
		}
	}
	if (life != 1)
		return -1;
	return id;
}

MType Core::loopArena(int size, MapPath Path)
{
	CreateArena(size, Path);
	while (device->run()) {
		driver->beginScene(true, true, SColor(255, 64, 115, 158));
		smgr->drawAll();
		guienv->drawAll();
		driver->endScene();
		windowFPS();
		for (int i = 0; i < 4; i++) {
			Controller.ControlPlayer(Bomberman[i]);
			Bomberman[i]->CheckBombs();
			CheckBombs(i);
		}
		State = Controller.ControlState();
		Winner = isVictory();
		if (Winner != -1)
			return VICTORY;
		if (State != RUN) {
			smgr->clear();
			Background->applyScene();
			return State;
		}
	}
}

void Core::CheckBombs(int i)
{
	for (int b = 0; b < Bomberman[i]->getStockBomb()->size(); b++) {
		if (Bomberman[i]->getStockBomb()->at(b)->isBlast()) {
			if (Arena->Blast(
				Bomberman[i]->getStockBomb()->at(b),
				smgr) == 1)
				GiveCollision();
			Bomberman[i]->getStockBomb()->at(i)->getSprite()
				->getNode()->setVisible(false);
			Bomberman[i]->getStockBomb()->erase
				(Bomberman[i]->getStockBomb()->begin() +
				i);
			}
		}
}
