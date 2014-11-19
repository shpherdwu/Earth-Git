


#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Viewer.h"
#include "MapEarth.h"
#include "EarthGLWidget.h"
#include "../zSettings/settings.h"

#include <string>
#include <osgEarth/Registry>


namespace EarthWidget{

class  Functions
{
public:
	Functions();
	virtual ~Functions();

	void frame() {return theViewer.frame();}

	bool earthFileLoad(const std::string& path,const std::string& name);

	Viewer* GetViewer() { return &theViewer; }

	QWidget*  GetGLQWidget() { return earthGLWidget; }

	

private:
	
	osgQt::GLWidget*     earthGLWidget;
	Viewer               theViewer;
	MapEarth             mapEarth;
	std::string          sPath;
	std::string          sName;

};

}
#endif //FUNCTIONS_H
