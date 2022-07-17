#pragma once

#ifndef FRAME_H
#define FRAME_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>

class FRAME:public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
<<<<<<< Updated upstream
    explicit FRAME(QObject *parent = 0);
        ~FRAME();
private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void setBrush();
=======
    explicit FRAME(int num, QObject* parent = Q_NULLPTR);
    inline const int& getNumber() const { return number; }
    QRectF boundingRect() const override;

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget* widget) override;
    inline void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override { setPos(mapToScene(event->pos())); }
    int number;
>>>>>>> Stashed changes
};

#endif // FRAME_H
