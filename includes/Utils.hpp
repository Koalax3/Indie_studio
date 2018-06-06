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

const io::path BTEXTURE[4] = {"media/Bomberman/AO_blue.png",
	"media/Bomberman/AO.png", "media/Bomberman/AO_red.png",
	"media/Bomberman/AO_yellow.png"};
const io::path BMESH = "media/Bomberman/bomberman_walk.ms3d";

const io::path BOMBMESH = "media/Bomb/bombe.obj";
const io::path BOMBTEXTURE = "media/Bomb/AO.png";

typedef unsigned int absolute;

enum MType {
    FPS = 0,
    ARENA,
    MENU,
    RUN,
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
