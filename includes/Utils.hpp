/*
** EPITECH PROJECT, 2017
** Indie
** File description:
** Created by nauroy_s
*/

#ifndef INDIE_UTILS_HPP
#define INDIE_UTILS_HPP

#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cmath>
#include "irrlicht.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

const std::string ENTITY_TYPE[] = {"BLANK", "BLAST", "B_MAN", "BOARD", "BOMB",
				   "BONUS", "BOX", "BRICK"};
const std::string ENTITY_DISPLAY[] = {"", "*", "M", " ",
				      "@", "B", "¤", "#"};
const std::string COMPASS[] = {"NONE", "DOWN", "LEFT", "RIGHT", "UP"};

const io::path BTEXTURE[] = {"media/Bomberman/AO.png",
	"media/Bomberman/AO_blue.png", "media/Bomberman/AO_red.png",
	"media/Bomberman/AO_yellow.png, media/Bomberman/AO_green.png",
	"media/Bomberman/AO_sky_blue.png", "media/Bomberman/AO_black.png",
	"media/Bomberman/Freddy_mercury.png"};
const io::path BMESH = "media/Bomberman/bomberman_walk.ms3d";
const io::path BMESHIDLE = "media/Bomberman/bomberman_idle.ms3d";

const io::path BOMBMESH = "media/Bomb/bombe.obj";
const io::path BOMBTEXTURE = "media/Bomb/AORed.png";
const EKEY_CODE DEFAULTCONTROL[4][5] = {{KEY_UP, KEY_LEFT, KEY_DOWN, KEY_RIGHT, KEY_END},
			   {KEY_KEY_Z, KEY_KEY_Q, KEY_KEY_S, KEY_KEY_D, KEY_LSHIFT},
			   {KEY_KEY_I, KEY_KEY_J, KEY_KEY_K, KEY_KEY_L, KEY_RSHIFT},
			   {KEY_KEY_T, KEY_KEY_F, KEY_KEY_G, KEY_KEY_H, KEY_SPACE}};

typedef unsigned int absolute;

enum MType {
    FPS = 0,
    ARENA,
    MENU,
    RUN,
    VICTORY,
    END
};

enum Compass {
	NONE,
	DOWN,
	LEFT,
	RIGHT,
	UP

};

enum BType {
	BLANK,
	BLAST,
	B_MAN,
	BOARD,
	BOMB,
	BONUS,
	BOX,
	BRICK
};

enum MapFormat {
	CLASSIC,
	RANDOM
};

struct MapPath {
	std::map<BType, io::path> MapMesh;
	std::map<BType, io::path> MapTexture;
};

#endif //INDIE_UTILS_HPP
