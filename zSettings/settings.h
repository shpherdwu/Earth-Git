




#ifndef  _Settings_H_
#define  _Settings_H_

#ifdef _DEBUG

/*#pragma comment(lib,"geos_d.lib")*/

 #pragma comment(lib,"osgd.lib")
 #pragma comment(lib,"osgDBd.lib")
 #pragma comment(lib,"osgViewerd.lib")
 #pragma comment(lib,"OpenThreadsd.lib")
 #pragma comment(lib,"osgGAd.lib")
 #pragma comment(lib,"osgSimd.lib")
 #pragma comment(lib,"osgUtild.lib")
 #pragma comment(lib,"osgTextd.lib")
 #pragma comment(lib,"osgFXd.lib")
 #pragma comment(lib,"osgQtd.lib")
 #pragma comment(lib,"osgTerraind.lib")
// 
#pragma comment(lib,"QtGuid4.lib")
#pragma comment(lib,"QtCored4.lib")
#pragma comment(lib,"QtOpenGLd4.lib")
//#pragma comment(lib,"QtWebKitd4.lib")
#pragma comment(lib, "qtmaind.lib")
#pragma comment(lib,"gdal_i.lib")
//#pragma comment(lib,"proj_i.lib")

// 
 #pragma comment(lib,"osgEarthAnnotationd.lib")
 #pragma comment(lib,"osgEarthd.lib")
 #pragma comment(lib,"osgEarthFeaturesd.lib")
 #pragma comment(lib,"osgEarthQtd.lib")
 #pragma comment(lib,"osgEarthSymbologyd.lib")
 #pragma comment(lib,"osgEarthUtild.lib")
// 




#else
#pragma comment(lib,"osg.lib")
#pragma comment(lib,"osgDB.lib")
#pragma comment(lib,"osgViewer.lib")
#pragma comment(lib,"OpenThreads.lib")
#pragma comment(lib,"osgGA.lib")
#pragma comment(lib,"osgSim.lib")
#pragma comment(lib,"osgUtil.lib")
#pragma comment(lib,"osgText.lib")
#pragma comment(lib,"osgFX.lib")
#pragma comment(lib,"osgQt.lib")

#pragma comment(lib,"QtGui4.lib")
#pragma comment(lib,"QtCore4.lib")
#pragma comment(lib,"QtWebKit4.lib")

#pragma comment(lib,"gdal_i.lib")

#endif

#endif