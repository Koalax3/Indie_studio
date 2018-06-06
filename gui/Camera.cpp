//
// Created by depret-l on 15/05/18.
//

#include "Camera.hpp"

Camera::Camera(ISceneManager &smgr, float speed, MType type) : smgr(smgr)
{
	switch (type) {
		case FPS :
			FPSMode(smgr, speed);
			break;
		case ARENA :
			ArenaMode(smgr, speed);
			break;
	}
}

Camera::~Camera()
{
}

void Camera::FPSMode(ISceneManager &smgr, float speed)
{
	SKeyMap keyMap[5];
	keyMap[0].Action = EKA_MOVE_FORWARD;
	keyMap[0].KeyCode = KEY_UP;
	keyMap[1].Action = EKA_MOVE_BACKWARD;
	keyMap[1].KeyCode = KEY_DOWN;
	keyMap[2].Action = EKA_STRAFE_LEFT;
	keyMap[2].KeyCode = KEY_LEFT;
	keyMap[3].Action = EKA_STRAFE_RIGHT;
	keyMap[3].KeyCode = KEY_RIGHT;
	keyMap[4].Action = EKA_JUMP_UP;
	keyMap[4].KeyCode = KEY_SPACE;
	camera = smgr.addCameraSceneNodeFPS(0, 100, speed, -1, keyMap, 5, false, 1.f);
	setPos(0, 2, 0);
}

void Camera::ArenaMode(ISceneManager &smgr, float speed)
{
	camera = smgr.addCameraSceneNode(0,core::vector3df(0,19,15));
	camera->setTarget(core::vector3df(0,-9,0));
}

void Camera::setPos(float z, float y, float x)
{
	camera->setPosition(core::vector3df(z, y, x));
}

void Camera::setRot(float z, float y, float x)
{
	camera->setRotation(core::vector3df(z, y, x));
}

void Camera::applyCollision(IMetaTriangleSelector *metaSelector)
{
	scene::ISceneNodeAnimator *anim = smgr.createCollisionResponseAnimator(
	    metaSelector, camera, core::vector3df(0.4, 0.1, 0.4),
	    core::vector3df(0, -5, 0), core::vector3df(0, 1, 0));
	camera->addAnimator(anim);
	anim->drop();
}

ICameraSceneNode *Camera::getCamera() const
{
	return camera;
}

void Camera::setCamera(ICameraSceneNode *camera)
{
	Camera::camera = camera;
}
