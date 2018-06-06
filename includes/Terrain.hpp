//
// Created by depret-l on 17/05/18.
//

#ifndef INDIE_TERRAIN_HPP
#define INDIE_TERRAIN_HPP

#include "indie.hpp"

class Terrain {
public:
    Terrain(ISceneManager &smgr, IVideoDriver &driver, irr::io::path pathTexture = "");
    virtual ~Terrain();
    void addCollision(scene::IMetaTriangleSelector &metaSelector);
    void changeTexture(irr::io::path pathTexture);
    void applyScene();


private:
    scene::IMesh *plane;
    scene::ISceneNode* node;
    ISceneManager &smgr;
    IVideoDriver &driver;
    irr::io::path path;
};


#endif //INDIE_TERRAIN_HPP
