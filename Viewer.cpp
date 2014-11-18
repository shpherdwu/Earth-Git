


#ifndef VIEWER_CPP

#define VIEWER_CPP

#include "Viewer.h"
namespace EarthWidget{

	Viewer::Viewer()
	{
		root    = NULL;
/*		mapNode = NULL;*/

	}
	Viewer::~Viewer()
	{

	}


	bool Viewer::CreateViewer(osg::Node* node)
	{

		if(!node){
			//do something
		}
		osg::Camera* camera = osg::View::getCamera();
		if(!camera){
			return false;
		}

		camera->setSmallFeatureCullingPixelSize(4.0f);
		return NewViewer(camera,node);

	}

// 	osg::Camera* Viewer::CreateCamera()
// 	{
// 
// 	}




	bool Viewer::NewViewer(osg::Camera* camera, osg::Node* scene)
	{
		osg::ref_ptr<osg::Group> root = new osg::Group;
		root->addChild(scene);
		osgEarth::MapNode* mapnode = osgEarth::MapNode::findMapNode(scene);

		setSceneData(root);
		setThreadingModel(osgViewer::Viewer::CullThreadPerCameraDrawThreadPerContext);
		//setCameraManipulator();
		addEventHandler(new osgViewer::StatsHandler);
		addEventHandler(new osgViewer::ThreadingHandler);
		addEventHandler(new osgViewer::LODScaleHandler);
		addEventHandler(new osgViewer::WindowSizeHandler);

		osg::ref_ptr<osgGA::StateSetManipulator> stateSetManipulator = new osgGA::StateSetManipulator(
			osg::View::getCamera()->getOrCreateStateSet());
		addEventHandler(stateSetManipulator);

		return true;
	}


}


#endif //VIEWER_CPP