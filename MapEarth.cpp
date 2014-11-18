

#ifndef MAPEARTH_CPP
#define MAPEARTH_CPP



#include "MapEarth.h"

namespace EarthWidget{

	MapEarth::MapEarth()
	{
		mapNode        = NULL;
		elevationQuery = NULL;
	}

	MapEarth::~MapEarth()
	{

	}

	bool  MapEarth::MapLoad(const std::string& strFileNode)
	{
		printf(" osgDB::readNodeFile: %s\n", strFileNode.c_str() );

		osg::Node* node = osgDB::readNodeFile(strFileNode.c_str());
		mapNode = osgEarth::MapNode::findMapNode(node);
		if(!mapNode){
			return false;
		}
		ViewPointUpdate();
		return true;

	}

	void MapEarth::ViewPointUpdate()
	{

	}


}



#endif //MAPEARTH_CPP
