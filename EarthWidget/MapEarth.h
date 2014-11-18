

#ifndef MAPEARTH_H
#define MAPEARTH_H

#include <string>
#include <osgEarth/MapNode>
#include <osgEarth/ElevationQuery>
#include <osgEarth/Viewpoint>

#include "../zSettings/settings.h"



namespace EarthWidget{

using namespace std;

class  MapEarth
{
public:
	MapEarth();
	virtual ~MapEarth();

	bool MapLoad(const std::string& strFileNode);

	osgEarth::MapNode* getMapNode(){ return mapNode;}

	vector<osgEarth::Viewpoint>& GetViewPoints() { return vec_viewpoints ;}

	osgEarth::Viewpoint& GetViewPoint(int index) { return vec_viewpoints[index];}
	




private:

	void ViewPointUpdate();

	osgEarth::ElevationQuery*         elevationQuery;
	osgEarth::MapNode*                mapNode;
	std::vector<osgEarth::Viewpoint>  vec_viewpoints;

};


}


#endif //MAPEARTH_H