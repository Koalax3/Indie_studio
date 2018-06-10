//
// Created by depret-l on 15/05/18.
//

#ifndef INDIE_CAMERA_HPP
#define INDIE_CAMERA_HPP

#include "indie.hpp"

class Camera {
public:
    Camera(ISceneManager &smgr, float speed, MType type = FPS);
    virtual ~Camera();
    void FPSMode(ISceneManager &smgr, float speed);
    void ArenaMode(ISceneManager &smgr);
    void MenuMode(ISceneManager &smgr);
    ICameraSceneNode *getCamera() const;
    void setCamera(ICameraSceneNode *camera);
    void setPos(float z,float y, float x);
    void setRot(float z,float y, float x);
    void applyCollision(scene::IMetaTriangleSelector *metaSelector);    

private:
    ICameraSceneNode *camera;
    ISceneManager &smgr;
};


#endif //INDIE_CAMERA_HPP
