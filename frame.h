#ifndef FRAME_H
#define FRAME_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>

class FRAME final : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    explicit FRAME(int num, QObject* parent = nullptr);
    const int& getNumber() const;
    QRectF boundingRect() const;


private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget* widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    void setBrush();
    int number;
};

#endif // FRAME_H
