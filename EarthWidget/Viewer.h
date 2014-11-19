


#ifndef VIEWER_H
#define VIEWER_H

#include <osgViewer/Viewer>
#include <osg/Camera>

#include <osgEarthUtil/EarthManipulator>
#include <osgEarthUtil/Controls>
#include <osgEarth/MapNode>
#include <osgEarth/Viewpoint>
#include <osgGA/StateSetManipulator>
#include <osgViewer/ViewerEventHandlers>



namespace EarthWidget{

class Viewer : public osgViewer::Viewer
{
public:
	Viewer();
	~Viewer();


	bool CreateViewer(osg::Node* node);

	void SetViewPoint(const osgEarth::Viewpoint& view_point, bool bRange=true, bool bHeading = true, bool bPitch=true);

	void SetViewHome();

	static osg::Camera* CreateCamera();


private:

	bool NewViewer(osg::Camera* camera, osg::Node* scene);

	void AddMouseCoords(osgViewer::View* viewer, osgEarth::MapNode* map_node);

	osg::Group*                  root;

	osgEarth::Util::EarthManipulator*   manipulator;

	osgEarth::Viewpoint          current_viewpoint;

//	osgEarth::MapNode*           mapNode;

};


struct MouseCoordsHandler : public osgGA::GUIEventHandler
{
public:

	MouseCoordsHandler(osgEarth::Util::Controls::LabelControl* label, osgEarth::MapNode* _mapNode)
		:mouseLabel(label),mapNode(_mapNode){
			mapNodePath.push_back((osg::Node*)mapNode->getTerrainEngine() );
	}
	bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
	{

		return true;
	}



public:
	osg::ref_ptr<osgEarth::Util::Controls::LabelControl>  mouseLabel;
	osgEarth::MapNode*                                    mapNode;
	osg::NodePath                                         mapNodePath;

};



}



#endif //VIEWER_H