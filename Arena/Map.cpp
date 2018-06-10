/*
** EPITECH PROJECT, 2017
** Indie
** File description:
** Created by nauroy_s
*/

#include <sstream>
#include <iomanip>
#include "Utils.hpp"
#include "Map.hpp"

Map::Map(int Size, absolute Seed, MapFormat Format) : Size(Size), Seed(Seed),
						      Format(Format)
{
	Move[DOWN] = &Map::down;
	Move[LEFT] = &Map::left;
	Move[RIGHT] = &Map::right;
	Move[UP] = &Map::up;
	Rotate[0] = &Map::rotation2PI;
	Rotate[1] = &Map::rotationPI2;
	Rotate[2] = &Map::rotationPI;
	Rotate[3] = &Map::rotation3PI2;
	setSize(Size + (1 - (Size % 2)));
	Min = -((getSize() - 1) / 2);
	Max = ((getSize() - 1) / 2);
	if (Seed == 0)
		setSeed(std::time(NULL));
	std::srand(getSeed());
	Field = new std::vector<std::vector<Chunk *>>;
	MapGen();
	if (Format == RANDOM) {
		Msc = new Mask(Max);
		MaskIt();
		Msc->reverse();
		MaskIt();
	}
}

Map::~Map()
{

}

void Map::MapGen()
{
	for (int i = Min; i <= Max; i++) {
		auto tmpI = new std::vector<Chunk *>;
		for (int j = Min; j <= Max; j++) {
			auto tmpJ = new Chunk(BOARD, Position(i, j, 0));
			if ((abs(i) % 2 == 1 && abs(j) % 2 == 1) ||
			    (i == Min || j == Min || i == Max || j == Max))
				tmpJ->addEntity(BRICK);
			else if ((i || j) && (abs(i) < Max - 2
				 || abs(j) < Max - 2))
				tmpJ->addEntity(BOX);
			tmpI->push_back(tmpJ);
		}
		Field->push_back(*tmpI);
	}
}

void Map::MapGenGui(ISceneManager &smgr, IVideoDriver &driver, MapPath Path)
{
	for (int i = 0; i < Field->size(); i++)
		for (int j = 0; j < Field->at(i).size(); j++)
			for (int k = 0; k < Field->at(i).at(j)->getEntities()
				->size(); k++) {
				Chunk *chunk = Field->at(i).at(j);
				Position pos = chunk->getPos();
				BType type =
					chunk->getEntities()->at(k)->getEntityType();
				if (Path.MapMesh.find(type) != Path.MapMesh.end()) {
					Mesh *mesh = new Mesh(smgr, Path.MapMesh[type],
						core::vector3df(pos.getX()*2,0.5,
						pos.getY()*2));
					mesh->setRot(0,180,0);
					mesh->addTexture(driver, Path.MapTexture[type]);
					chunk->getEntities()->at(k)->setSprite(mesh);
				}
				else
					chunk->getEntities()->at(k)->setSprite(nullptr);
			}
}

void Map::MapCollision(IMetaTriangleSelector &metaSelector)
{
		for (int i = 0; i < Field->size(); i++)
		for (int j = 0; j < Field->at(i).size(); j++)
			for (int k = 0; k < Field->at(i).at(j)->getEntities()
				->size(); k++)
				if ((Field->at(i).at(j)->getEntities()->at(k)->getSprite()) != nullptr) {
						Field->at(i).at(j)->getEntities()
							->at(k)->getSprite()
							->addCollision(metaSelector);
					}
}

void Map::print()
{
	std::cout << "Seed : <" << Seed << ">" << std::endl;
	std::cout << "Size : " << Size << std::endl;
	Range::print();
	Msc->print();
	std::cout << std::endl;
	for (int j = Max; j >= Min; j--) {
		for (int i = Min; i <= Max; i++) {
			std::stringstream ss;
			ss << std::setw(2) << std::setfill('+') <<
			   getChunk(Position(i, j))->getX();
			std::stringstream ss_;
			ss_ << std::setw(2) << std::setfill('+') <<
			    getChunk(Position(i, j))->getY();
			std::cout << " [ " << ss.str()
				  << "; " << ss_.str() << " ] ";
		}
		std::cout << std::endl;
	}
}

int Map::getSize() const
{
	return Size;
}

absolute Map::getSeed() const
{
	return Seed;
}

MapFormat Map::getFormat() const
{
	return Format;
}

Mask *Map::getMsc() const
{
	return Msc;
}

std::vector<std::vector<Chunk *>> *Map::getField() const
{
	return Field;
}

void Map::setSize(int Size)
{
	Map::Size = Size;
}

void Map::setSeed(absolute Seed)
{
	Map::Seed = Seed;
}

void Map::setFormat(MapFormat Format)
{
	Map::Format = Format;
}

void Map::setMsc(Mask *Msc)
{
	Map::Msc = Msc;
}

void Map::setField(std::vector<std::vector<Chunk *>> *Field)
{
	Map::Field = Field;
}

Chunk *Map::getChunk(Position Pos)
{
	int i;
	int j;

	for (i = 0; i < Field->size() &&
		    Field->at(i).at(0)->getX() < Pos.getX(); i++);
	for (j = 0; Field->at(i).size() &&
		    Field->at(i).at(j)->getY() < Pos.getY(); j++);
	return Field->at(i).at(j);
}

void Map::addEntity(BType EntityType, Position Pos)
{
	getChunk(Pos)->addEntity(EntityType);
}

void Map::printChunks()
{
	for (int j = Max; j >= Min; j--) {
		for (int i = Min; i <= Max; i++) {
			getChunk(Position(i, j))->print();
		}
	}
}

void Map::printMap()
{
	for (int j = Max; j >= Min; j--) {
		for (int i = Min; i <= Max; i++) {
			std::cout << "[";
			getChunk(Position(i, j))->printIt();
			std::cout << "]";
		}
		std::cout << std::endl;
	}
}

void Map::MaskIt()
{
	Position pos(Min + 1, Min + 1);
	Chunk *tmp;
	for (int i = 0; i < Msc->getMaskFormat()->size(); i++) {
		tmp = getChunk(pos);
		for (int j = 0; j < 4; j++) {
			tmp = getChunk(rotate(pos, j));
			if (tmp->getEntities()->back()->getEntityType()
				 == BRICK)
				tmp->getEntities()->pop_back();
				tmp->addEntity(BOX);
			if (i < 2)
				while (tmp->getEntities()->back()
					  ->getEntityType() != BOARD)
					tmp->getEntities()->pop_back();
		}
		tmp = move(Msc->getMaskFormat()->at(i), pos);
		pos = tmp->getPos();
	}
}

Chunk *Map::move(Compass Dir, Position Pos)
{
	if (Move.find(Dir) != Move.end())
		return getChunk((*this.*Move[Dir])(Pos));
	return nullptr;
}

Position Map::down(Position Pos)
{
	if (Pos.getY() == Min)
		return Position(Pos.getX(), Max);
	return Position(Pos.getX(), Pos.getY() - 1);
}

Position Map::left(Position Pos)
{
	if (Pos.getX() == Min)
		return Position(Max, Pos.getY());
	return Position(Pos.getX() - 1, Pos.getY());
}

Position Map::right(Position Pos)
{
	if (Pos.getX() == Max)
		return Position(Min, Pos.getY());
	return Position(Pos.getX() + 1, Pos.getY());
}

Position Map::up(Position Pos)
{
	if (Pos.getY() == Max)
		return Position(Pos.getX(), Min);
	return Position(Pos.getX(), Pos.getY() + 1);
}

Position Map::rotate(Position Pos, double angle)
{
	if (Rotate.find(angle) != Move.end())
		return (*this.*Rotate[angle])(Pos);
	return Pos;
}

Position Map::rotation2PI(Position Pos)
{
	return Pos;
}

Position Map::rotationPI2(Position Pos)
{
	return Position(-Pos.getY(), Pos.getX());
}

Position Map::rotationPI(Position Pos)
{
	return Position(-Pos.getX(), -Pos.getY());
}

Position Map::rotation3PI2(Position Pos)
{
	return Position(Pos.getY(), -Pos.getX());
}


int Map::Blast(Bomb *&bomb, ISceneManager *pManager)
{
	int res = 0;
	double x;
	double y;
	modf(bomb->getX() / 2, &x);
	modf(bomb->getZ() / 2, &y);
	auto Pos = Position(x , y);
	auto block = getChunk(Pos)->getEntities()->back();
	for (int i = 0; i <= bomb->getRange() && block->getEntityType() !=
						 BRICK;
	     i++) {
		std::cout << "pos : " << x << " : " << y <<
			  std::endl;
		std::cout << "POS : " << Pos.getX() << " : " << Pos.getY() <<
			  std::endl;
		std::cout << ENTITY_TYPE[block->getEntityType()] <<
			  std::endl;
		if (block->getEntityType() == BOX) {
			getChunk(Pos)->getEntities()->back()->getSprite()
				     ->getNode()->setVisible(false);
			getChunk(Pos)->getEntities()->back()->getSprite()
				     ->getNode()->setTriangleSelector(nullptr);
			getChunk(Pos)->getEntities()->pop_back();
		}
		Pos.setX(x + i + 1);
		block = getChunk(Pos)->getEntities()->back();
		res = 1;
	}
	std::cout << std::endl;
	return res;
}

