//
// Created by depret-l on 17/05/18.
//

#include "Terrain.hpp"

Terrain::Terrain(ISceneManager &smgr, IVideoDriver &driver, irr::io::path pathTexture) : smgr(smgr), driver(driver)
{
	path = pathTexture;
	const irr::scene::IGeometryCreator *geomentryCreator =
	    smgr.getGeometryCreator();
	plane = geomentryCreator->createPlaneMesh(
	    irr::core::dimension2d<irr::f32>(1, 1),
	    irr::core::dimension2d<irr::u32>(100, 100));
	node = smgr.addMeshSceneNode(plane);
	driver.getMeshManipulator()->makePlanarTextureMapping(plane, 0.07);
	if (pathTexture != "")
		node->setMaterialTexture(0, driver.getTexture(pathTexture));
	node->setMaterialFlag(EMF_LIGHTING, false);
	node->setPosition(core::vector3df(0, 0, 0));
	geomentryCreator->drop();
}

void Terrain::applyScene()
{
	node = smgr.addMeshSceneNode(plane);
	if (path != "")
		node->setMaterialTexture(0, driver.getTexture(path));
	node->setMaterialFlag(EMF_LIGHTING, false);
	node->setPosition(core::vector3df(0, 0, 0));
}

void Terrain::changeTexture(irr::io::path pathTexture, float detail)
{
	driver.getMeshManipulator()->makePlanarTextureMapping(plane, detail);
	node->setMaterialTexture(0, driver.getTexture(pathTexture));
	path = pathTexture;
}
Terrain::~Terrain()
{
	node->remove();
	node->drop();
}

void Terrain::addCollision(IMetaTriangleSelector &metaSelector)
{
	scene::ITriangleSelector *selector = smgr.createTriangleSelectorFromBoundingBox(node);
	metaSelector.addTriangleSelector(selector);
    	selector->drop();
}

