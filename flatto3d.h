#pragma once

#ifndef FLATTO3D_H
#define FLATTO3D_H

#include <QObject>
#include <QVector3D>
#include <QPoint>
#include <QtMath>
#include <QtDebug>

class flatto3d final : public QObject
{
    Q_OBJECT
public:
    explicit flatto3d(QObject *parent = nullptr);
    inline const float& getRangeCam() const { return rangeCam; }
    inline void setRangeCam(float newRangeCam) { rangeCam = newRangeCam; }
    inline const float& getAngle() const { return angle; }
    inline void setAngle(float newAngle) { angle = newAngle; }
    inline const float& getTetaxprav() const { return tetaxprav; }
    inline void setTetaxprav(float newTetaxprav) { tetaxprav = newTetaxprav; }
    inline const float& getTetayprav() const { return tetayprav; }
    inline void setTetayprav(float newTetayprav) { tetayprav = newTetayprav; }
    inline const float& getTetaxlev() const { return tetaxlev; }
    inline void setTetaxlev(float newTetaxlev) { tetaxlev = newTetaxlev; }
    inline const float& getTetaylev() const { return tetaylev; }
    inline void setTetaylev(float newTetaylev) { tetaylev = newTetaylev; }
    inline const float &getBtwangle() const { return btwangle; }
    inline void setBtwangle(float newBtwangle) { btwangle = newBtwangle; }
    inline const QVector<QVector3D>& getVec3D() const { return vec3D; }
    void Start(QVector<QPoint> r, QVector<QPoint> l);
    void Clear();

private:
    float rangeCam;
    float angle;
    float btwangle;
    float tetayprav;
    float tetaxprav;
    float tetaylev;
    float tetaxlev;
    int videoHalfWidth;
    int videoHalfHeight;
    QVector<float>alphaprav;
    QVector<float>bettaprav;
    QVector<float>alphalev;
    QVector<float>bettalev;
    QVector<float>alpha1;
    QVector<float>alpha2;
    QVector<float>gamma;
    QVector<float>x1;
    QVector<float>x2;
    QVector<float>h1;
    QVector<float>h2;
    QVector<float>h11;
    QVector<QVector3D> vec3D;

};

#endif // FLATTO3D_H
