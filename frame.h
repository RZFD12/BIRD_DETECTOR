#pragma once

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
    explicit FRAME(int num, QObject* parent = Q_NULLPTR);
    inline const int& getNumber() const { return number; }
    QRectF boundingRect() const override;

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget* widget) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
    int number;
};

#endif // FRAME_H
