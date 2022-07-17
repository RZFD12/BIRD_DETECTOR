#include "frame.h"

FRAME::FRAME(int num, QObject* parent)
    : QObject(parent),
      number(num)
{
    Q_UNUSED(parent);
}

QRectF FRAME::boundingRect() const
{
    return QRectF(-25,-25,50,50);
}
void FRAME::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    painter->setPen(QColor::colorNames().at(number));
    painter->drawRoundedRect(-25,-25,50,50,10,10);
    painter->drawText(-10,-10,QString::number(this->number));
    QSharedPointer<QPen> pen(new QPen(QColor::colorNames().at(number)));
    pen->setWidth(3);
    painter->setPen(*pen);
    painter->drawPoint(0,0);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
void FRAME::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    this->setPos(mapToScene(event->pos()));
}
