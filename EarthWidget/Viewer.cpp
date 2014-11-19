


#ifndef VIEWER_CPP

#define VIEWER_CPP

#include "Viewer.h"
namespace EarthWidget{

	Viewer::Viewer()
	{
		root    = NULL;
/*		mapNode = NULL;*/

		manipulator = NULL;
		

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

 	osg::Camera* Viewer::CreateCamera()
 	{
		osg::ref_ptr<osg::Camera> camera = new osg::Camera;
		camera->setClearColor(osg::Vec4(0.2f, 0.0f, 0.6f,1.0f) );
		return camera.release();
 	}




	bool Viewer::NewViewer(osg::Camera* camera, osg::Node* scene)
	{
		osg::ref_ptr<osg::Group> root = new osg::Group;
		manipulator = new osgEarth::Util::EarthManipulator();

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

	void  Viewer::SetViewPoint(const osgEarth::Viewpoint& view_point, bool bRange, bool bHeading, bool bPitch)
	{
		osgEarth::Viewpoint vp = manipulator->getViewpoint();
		vp.x() = view_point.x();
		vp.y() = view_point.y();
		vp.z() = view_point.z();
		if(bHeading)
			vp.setHeading(view_point.getHeading());
		if (bPitch)
		{
			vp.setPitch(view_point.getPitch());
		}
		if (bRange)
		{
			vp.setRange(view_point.getRange());
		}
		if(manipulator)
			manipulator->setViewpoint(vp,2);

	}

	void  Viewer::SetViewHome()
	{
		/*manipulator->home()*/
	}


	void Viewer::AddMouseCoords(osgViewer::View* viewer, osgEarth::MapNode* map_node)
	{
		osgEarth::Util::Controls::ControlCanvas* canvas = osgEarth::Util::Controls::ControlCanvas::get(viewer);
		osgEarth::Util::Controls::LabelControl* mouseCoords = new osgEarth::Util::Controls::LabelControl();

		mouseCoords->setHorizAlign(osgEarth::Util::Controls::Control::ALIGN_CENTER);
		mouseCoords->setVertAlign(osgEarth::Util::Controls::Control::ALIGN_BOTTOM);
		mouseCoords->setBackColor(0,0,0,0.5);
		mouseCoords->setSize(300,50);
		mouseCoords->setMargin(10);
		canvas->addControl(mouseCoords);

		viewer->addEventHandler(new MouseCoordsHandler(mouseCoords, map_node));

	}

}


#endif //VIEWER_CPP