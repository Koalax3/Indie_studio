//
// Created by depret-l on 16/05/18.
//

#ifndef INDIE_MESH_HPP
#define INDIE_MESH_HPP

#include "indie.hpp"

class Mesh {
public:
    Mesh(ISceneManager &smgr, irr::io::path pathMesh, core::vector3df vec = core::vector3df(0,0.5,0));
    virtual ~Mesh();
    void setPos(float x,float y, float z);
    void setRot(float x,float y, float z);
    IAnimatedMeshSceneNode *getNode() const;
    void setNode(IAnimatedMeshSceneNode *node);
    void addCollision(scene::IMetaTriangleSelector &metaSelector);
    void addTexture(IVideoDriver &driver, irr::io::path pathTexture = "");  
    void applyCollision(IMetaTriangleSelector *metaSelector);
    
private:
    IAnimatedMeshSceneNode *node;
    ISceneManager &smgr;
};


#endif //INDIE_MESH_HPP
