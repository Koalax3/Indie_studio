//
// Created by depret-l on 16/05/18.
//

#include "Mesh.hpp"

Mesh::Mesh(ISceneManager &smgr, irr::io::path pathMesh, core::vector3df vec) : smgr(smgr)
{
	if (pathMesh != "") {
		IAnimatedMesh *mesh = smgr.getMesh(pathMesh);
		node = smgr.addAnimatedMeshSceneNode(mesh);
		node->setPosition(vec);
	}
}

void Mesh::setPos(float x,float y, float z)
{
	node->setPosition(core::vector3df(x,y,z));
}

void Mesh::setRot(float x,float y, float z)
{
	node->setRotation(core::vector3df(x,y,z));
}

Mesh::~Mesh()
{
	node->remove();
	node->drop();
}

void Mesh::addCollision(IMetaTriangleSelector &metaSelector)
{
	scene::ITriangleSelector *selector = smgr.createTriangleSelectorFromBoundingBox(node);
	metaSelector.addTriangleSelector(selector);
    selector->drop();

}

void Mesh::applyCollision(IMetaTriangleSelector *metaSelector)
{
	scene::ISceneNodeAnimator *anim = smgr.createCollisionResponseAnimator(
	    metaSelector, node, core::vector3df(0.5, 0.01, 0.5),
	    core::vector3df(0, -5, 0), core::vector3df(0, 0, 0));
	if (this->anim != anim){
		node->removeAnimators();
		node->addAnimator(anim);
	}
}

void Mesh::addTexture(IVideoDriver &driver, irr::io::path pathTexture)
{
	if (pathTexture != "")
		node->setMaterialTexture(0, driver.getTexture(pathTexture));
	node->setMaterialFlag(EMF_LIGHTING, false);
}

IAnimatedMeshSceneNode *Mesh::getNode() const
{
    return node;
}

void Mesh::setNode(IAnimatedMeshSceneNode *node)
{
    Mesh::node = node;
}
