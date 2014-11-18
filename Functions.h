


#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Viewer.h"
#include "MapEarth.h"
#include "EarthGLWidget.h"
#include "../zSettings/settings.h"

#include <string>
#include <osgEarth/Registry>


namespace EarthWidget{

class  Fuctions
{
public:
	Fuctions();
	virtual ~Fuctions();

	void frame() {return theViewer.frame();}

	bool earthFileLoad(const std::string& path,const std::string& name);

	Viewer* getViewer() { return &theViewer; }

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
