#include "frame.h"

<<<<<<< Updated upstream
FRAME::FRAME(QObject *parent)
{

}

FRAME::~FRAME()
{

}
=======
FRAME::FRAME(int num, QObject* parent)
    : QObject(parent),
      number(num)
{}
>>>>>>> Stashed changes

QRectF FRAME::boundingRect() const
{
    return QRectF(-25,-25,50,50);
}
void FRAME::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QColor(155,44,200));
    painter->drawRoundedRect(-25,-25,50,50,10,10);
    painter->drawText(0,0,"10");
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
<<<<<<< Updated upstream
void FRAME::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()));
    Q_UNUSED(event);
}
void FRAME::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if (event->button() & Qt::RightButton)
    {
        this->setCursor(QCursor(Qt::ClosedHandCursor));
        Q_UNUSED(event);
        //this->deleteLater();
    }
}

void FRAME::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
=======
>>>>>>> Stashed changes
