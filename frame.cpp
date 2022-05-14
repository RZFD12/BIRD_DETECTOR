#include "frame.h"

FRAME::FRAME(int num, QObject* parent)
{
    this->number = num;
    Q_UNUSED(parent);
}

QRectF FRAME::boundingRect() const
{
    return QRectF(-25,-25,50,50);
}
void FRAME::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    painter->setPen(QColor(255,255/number,255/number));
    painter->drawRoundedRect(-25,-25,50,50,10,10);
    painter->drawText(-10,-10,QString::number(this->number));
    QPen pen;
    pen.setColor(QColor(255,255/number,255/number));
    pen.setWidth(3);
    painter->setPen(pen);
    painter->drawPoint(0,0);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
void FRAME::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    this->setPos(mapToScene(event->pos()));
}
void FRAME::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if (event->button() == Qt::RightButton)
    {
        this->setCursor(QCursor(Qt::ClosedHandCursor));
    }
}

void FRAME::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}

const int& FRAME::getNumber() const
{
    return number;
}
