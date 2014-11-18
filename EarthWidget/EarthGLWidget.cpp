






#include "EarthGLWidget.h"
#include <iostream>
#include <osgViewer/ViewerEventHandlers>

#include <osgEarthUtil/EarthManipulator>

#include <osgGA/StateSetManipulator>


namespace EarthWidget
{

	EarthGLWidget::EarthGLWidget(osg::Node* scene)
	{
		CreateViewer();
		if(scene){
			dynamic_cast<osgViewer::Viewer*>(viewerBase.get())->setSceneData(scene);
		}

		installFrameTimer();
	}

	EarthGLWidget::EarthGLWidget(osgViewer::ViewerBase* viewer):
	viewerBase(viewer)
	{
		if( !viewerBase.valid() ){
			CreateViewer();
		}else{

			osgViewer::View* tempView = dynamic_cast<osgViewer::View*> (viewer);
			if(tempView ==NULL)
			{
				return;
			}
			reconfigure(tempView);

			viewerBase->setKeyEventSetsDone(0);
			viewerBase->setQuitEventSetsDone(false);
		}

		installFrameTimer();
	}

    EarthGLWidget::~EarthGLWidget()
    {
		timer.stop();
		if(viewerBase.valid())
		{
			viewerBase->stopThreading();
			viewerBase = 0L;
		}

		OE_DEBUG<<"ViewerWidget::DTOR"<<std::endl;

    }

    void EarthGLWidget::setTimerInterval(int milliseconds)
    {
		if( timer.interval() != milliseconds )
		{
			timer.start(milliseconds);
		}
    }

    void EarthGLWidget::installFrameTimer()
    {
		connect(&timer, SIGNAL(timeout()),this, SLOT(update() ) );
		timer.start(10);
    }

    void EarthGLWidget::CreateViewer()
	{
		osgViewer::Viewer* viewer = new osgViewer::Viewer;
		viewer->setThreadingModel(osgViewer::Viewer::CullThreadPerCameraDrawThreadPerContext);
		viewer->setCameraManipulator(new osgEarth::Util::EarthManipulator());

		viewer->addEventHandler(new osgViewer::StatsHandler());
		viewer->addEventHandler(new osgGA::StateSetManipulator());
		viewer->addEventHandler(new osgViewer::ThreadingHandler());

		viewer->setKeyEventSetsDone(0);
		viewer->setQuitEventSetsDone(false);

		reconfigure(viewer);
		viewerBase = viewer;
	}



    void EarthGLWidget::reconfigure(osgViewer::View* view)
	{
		if(!gc.valid())
		{
			osg::DisplaySettings* ds = osg::DisplaySettings::instance().get();
			osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits(ds);
			traits->readDISPLAY();
			if(traits->displayNum<0){
				traits->displayNum = 0;
			}

			traits->windowName = "EarthViewerGLWidget";
			traits->windowDecoration = false;
			traits->x = x();
			traits->y = y();
			traits->width = width();
			traits->height = height();
			traits->doubleBuffer = true;
			traits->inheritedWindowData = new osgQt::GraphicsWindowQt::WindowData(this);

			gc = new osgQt::GraphicsWindowQt(traits.get());
		}

		osg::Camera* camera = view->getCamera();
		if(camera->getGraphicsContext()!= gc.get())
		{
			camera->setGraphicsContext(gc.get());
			if( !camera->getViewport())
			{
				camera->setViewport(new osg::Viewport(0, 0, gc->getTraits()->width, gc->getTraits()->height));
			}
			camera->setProjectionMatrixAsPerspective(
				30.0f, camera->getViewport()->width()/camera->getViewport()->height(), 1.0f, 10000.0f);
		}

	}

    void EarthGLWidget::painEvent(QPaintEvent* event)
    {
		if(viewerBase->getRunFrameScheme() == osgViewer::ViewerBase::CONTINUOUS||viewerBase->checkNeedToDoFrame())
		{
			viewerBase->frame();
		}

    }


}