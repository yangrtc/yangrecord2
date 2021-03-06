#include "yangrecordvideowin.h"
#include <QDebug>
#include <QMouseEvent>
#include <QPaintEngine>
#include "yangutil/yangtype.h"
#include "../yangwinutil/yangrecordcontext.h"
YangRecordVideoWin::~YangRecordVideoWin()
{
    //m_selectUser=nullptr;
   // m_videoHandle=nullptr;
    //YANG_DELETE(m_ypainter);
    // timer = nullptr;
    //m_vb=NULL;
}
YangRecordVideoWin::YangRecordVideoWin(QWidget *parent) : QWidget(parent)
{

    // setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    //  this->setParent(parent);
    setAttribute(Qt::WA_PaintOnScreen);
    // setAttribute(Qt::WA_OpaquePaintEvent); //WA_NoSystemBackground
    setAttribute(Qt::WA_NoSystemBackground);
    //   setAttribute(Qt::WA_DontCreateNativeAncestors, true);

    setAttribute(Qt::WA_NativeWindow, true);//Qt::WA_DontCreateNativeAncestors
    //  setAttribute(Qt::AA_NativeWindows, true);


    setMouseTracking(true);
    setUpdatesEnabled(false);
    sid=1;
     connect(this,SIGNAL(clicked()), this, SLOT(onVideoClick()));
  //  m_videoHandle=nullptr;


}


QPaintEngine* YangRecordVideoWin::paintEngine()const{
    return nullptr;
}
void YangRecordVideoWin::mousePressEvent(QMouseEvent *qe){

    if(qe->button() == Qt::LeftButton){
        YangRecordVideoContext::mainWin->selectBox(sid);
    }
}

void YangRecordVideoWin::onVideoClick(){
    qDebug()<<"...................sid=="<<sid;
    YangRecordVideoContext::mainWin->selectBox(sid);
}

