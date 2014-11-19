#include "EarthWidget.h"


namespace EarthWidget{

EarthWidget::EarthWidget()
{
	bLoad = false;

	functions = NULL;
	//UI

	centralWidget = new QWidget;
	layout_main = new QHBoxLayout;
	lbl_left = new QLabel;
}

EarthWidget::~EarthWidget()
{

}


bool LoadEarthFile(const string& path, const string& name)
{


	return true;

}

void Unload()
{

}


}