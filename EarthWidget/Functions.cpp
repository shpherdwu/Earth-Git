

#ifndef Functions_CPP

#define Functions_CPP

#include "Functions.h"


namespace EarthWidget{

	Functions::Functions()
	{
		sPath = "";
		sName = "";
		earthGLWidget = NULL;


	}

	Functions::~Functions()
	{

	}

	

	bool Functions::earthFileLoad(const std::string& path,const std::string& name)
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


#endif //Functions_CPP