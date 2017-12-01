#include "renderarea.h"

static std::vector<QPoint> pathPoints;
static RenderArea* renderArea;

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

}

RenderArea* RenderArea::getInstance(){
    if(renderArea==NULL){
        renderArea=new RenderArea;
        renderArea->Init();
    }
    return renderArea;
}

void RenderArea::Init(){
    pathPoints.clear();
}


void RenderArea::mousePressEvent(QMouseEvent *event){
    //float x = event->pos().x();
    //float y=event->pos().y();

}

void RenderArea::SetPathPoint(std::vector<QPoint> newPath){

    pathPoints.insert(pathPoints.end(),newPath.begin(),newPath.end());
}


void RenderArea::paintEvent(QPaintEvent *){

    QColor black=QColor(0,0,0);
    QPainter painter(this);

    painter.setPen(QPen(black,0));

    QPainterPath path;

    if(pathPoints.size()>0){
        path.moveTo(pathPoints[0]);
        for(int i=0;i<pathPoints.size();i++){
            path.lineTo(pathPoints[i]);
        }
    }

    painter.drawPath(path);
}
