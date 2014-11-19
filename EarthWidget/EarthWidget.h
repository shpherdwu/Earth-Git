

/* file EarthWidget.h
 * \suthor      wu bian
 * \version     ver1.0
 * \date        2014-11-19
 * \brief       界面控制
 * 版权所有
 * \warning     警告描述
 * \note        注意事项描述
 * \bug         本文档还存在的bug描述
 * \history   \n
 * 修改日期： \n
 * 版 本 号： \n
 * 修 改 人： \n
 * 修改内容： \n
*/

#ifndef EARTHWIDGET_H
#define EARTHWIDGET_H

#include "earthwidget_global.h"

#include "Functions.h"

#include <Qt/qtimer.h>
#include <QtGui/QWidget>
#include <QtGui/QLabel>
#include <QtGui/QHBoxLayout>

#include <QtGui/QGraphicsView>
#include <QtCore/QString>

#include <string>
#include <iostream>


namespace EarthWidget{
using namespace std;

class EARTHWIDGET_EXPORT EarthWidget : public QWidget
{
	Q_OBJECT
public:
	EarthWidget();
	~EarthWidget();

	bool LoadEarthFile(const string& path, const string& name);

	void Unload();

private:

	bool bLoad;

	Functions*  functions;
	//UI

	QWidget*  centralWidget;
	QHBoxLayout* layout_main;

	QLabel*    lbl_left;




};
}
#endif // EARTHWIDGET_H
