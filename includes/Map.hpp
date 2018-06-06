/*
** EPITECH PROJECT, 2017
** Indie
** File description:
** Created by nauroy_s
*/

#ifndef INDIE_MAP_HPP
#define INDIE_MAP_HPP

#include "Utils.hpp"
#include "Chunk.hpp"
#include "Range.hpp"
#include "Mask.hpp"
#include "indie.hpp"

class Map : public Range
{
public:
	Map(int Size = 20, absolute Seed = 0, MapFormat Format = RANDOM);
	virtual ~Map();
	void MapGen();
	void print();
	void printChunks();
	void printMap();
	int getSize() const;
	absolute getSeed() const;
	MapFormat getFormat() const;
	Mask *getMsc() const;
	std::vector<std::vector<Chunk *>> *getField() const;
	Chunk *getChunk(Position Pos);
	void setSize(int Size);
	void setSeed(absolute Seed);
	void setFormat(MapFormat Format);
	void setMsc(Mask *Msc);
	void setField(std::vector<std::vector<Chunk *>> *Field);
	void addEntity(BType EntityType, Position Pos);
	void MaskIt();
	void MapGenGui(ISceneManager &smgr, IVideoDriver &driver, MapPath Path);
	void MapCollision(IMetaTriangleSelector &metaSelector);
	Chunk *move(Compass Dir, Position Pos);
	Position down(Position Pos);
	Position left(Position Pos);
	Position right(Position Pos);
	Position up(Position Pos);
	Position rotate(Position Pos, double angle);
	Position rotation2PI(Position Pos);
	Position rotationPI2(Position Pos);
	Position rotationPI(Position Pos);
	Position rotation3PI2(Position Pos);
private:
	int Size;
	absolute Seed;
	MapFormat Format;
	Mask *Msc;
	std::vector<std::vector<Chunk *>> *Field;
	std::map<int , Position (Map::*)(Position Pos)> Move;
	std::map<int , Position (Map::*)(Position Pos)> Rotate;
};

#endif //INDIE_MAP_HPP
