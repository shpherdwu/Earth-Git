#ifndef EARTHGLWIDGET_H
#define EARTHGLWIDGET_H

#include <osgEarthQt/Common>
#include <osgEarth/Map>
#include <osgQt/GraphicsWindowQt>
#include <osgViewer/ViewerBase>

#include <QtCore/QTimer>

#include "earthtoolz_global.h"
#include "../zSettings/settings.h"

namespace EarthWidget{
class EarthGLWidget : public osgQt::GLWidget
{
	Q_OBJECT;

public:
	
	EarthGLWidget(osg::Node* scene= NULL);
	EarthGLWidget(osgViewer::ViewerBase* viewer);

	virtual ~EarthGLWidget();

	osgViewer::ViewerBase* GetViewer() { return viewerBase.get(); }

	template<typename T>
	void getViews(T& views) const {
		osgViewer::ViewerBase::Views temp;
		viewerBase->getViews(temp);
		views.insert( views.end(), temp.begin(), temp.end() );
	}

  
public slots:
	
	void setTimerInterval(int milliseconds);

private:
	QTimer timer;

	void installFrameTimer();

	void CreateViewer();

	void reconfigure(osgViewer::View*);

	void painEvent(QPaintEvent* event);


	osg::observer_ptr<osgViewer::ViewerBase>    viewerBase;
	osg::ref_ptr<osg::GraphicsContext>          gc;

};

}

#endif // EARTHGLWIDGET_H
