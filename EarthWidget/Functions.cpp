

#ifndef FUCTIONS_CPP

#define FUCTIONS_CPP

#include "Functions.h"


namespace EarthWidget{

	Fuctions::Fuctions()
	{
		sPath = "";
		sName = "";
		earthGLWidget = NULL;


	}

	Fuctions::~Fuctions()
	{

	}

	

	bool Fuctions::earthFileLoad(const std::string& path,const std::string& name)
	{

		osg::DisplaySettings::instance()->setMinimumNumStencilBits(8);
		printf(" Functions::earthFileLoad() \n");

		std::string strTerrainEngineName = "quadtree";

		osgEarth::Registry::instance()->setDefaultTerrainEngineDriverName(strTerrainEngineName);
		
		sPath = path;
		sName = name;

		std::string nodefile = sPath + sName;

		if(mapEarth.MapLoad(nodefile) == NULL)
			return false;
		if( !theViewer.CreateViewer(mapEarth.getMapNode()))
			return false;

		osg::Group* rootNode = new osg::Group;
		rootNode->addChild(mapEarth.getMapNode());
		earthGLWidget = new EarthGLWidget(&theViewer);
		theViewer.getDatabasePager()->setUnrefImageDataAfterApplyPolicy(false,false); // what mean
		theViewer.getDatabasePager()->setTargetMaximumNumberOfPageLOD(10); // what mean?

		return true;
	}



}


#endif //FUCTIONS_CPP