#pragma once

#ifndef FLATTO3D_H
#define FLATTO3D_H

#include <QObject>
<<<<<<< Updated upstream
=======
#include <QVector3D>
#include <QPoint>
#include <QtMath>
#include <QtDebug>
>>>>>>> Stashed changes

class flatto3d : public QObject
{
    Q_OBJECT
public:
<<<<<<< Updated upstream
    explicit flatto3d(QObject *parent = nullptr);
    void Start(QVector<int> px, QVector<int> py, QVector<int> lx, QVector<int> ly);

    float getRangeCam() const;
    void setRangeCam(float newRangeCam);

    float getTetaxprav() const;
    void setTetaxprav(float newTetaxprav);

    float getTetayprav() const;
    void setTetayprav(float newTetayprav);

    float getTetaxlev() const;
    void setTetaxlev(float newTetaxlev);

    float getTetaylev() const;
    void setTetaylev(float newTetaylev);

    const QVector<float> &getX() const;

    const QVector<float> &getY() const;

    const QVector<float> &getH3() const;

    void clear_data();

private:
    float rangeCam=80;
    float angle=5;
    float tetaxprav=0.043;
    float tetayprav=0.038;
    float tetaxlev=0.056;
    float tetaylev=0.095;
    int videoHalfWidth=960;
    int videoHalfHeight=540;
=======
    explicit flatto3d(QObject *parent = Q_NULLPTR);
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
    inline const QVector<QVector3D>& getVec3D() const { return vec3D; }
    inline const float &getBtwangle() const { return btwangle; }
    inline void setBtwangle(float newBtwangle) { btwangle = newBtwangle; }
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
>>>>>>> Stashed changes
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
    QVector<float>x;
    QVector<float>y;
    QVector<float>h11;
<<<<<<< Updated upstream
    QVector<float>h3;

signals:

=======
    QVector<QVector3D> vec3D;
>>>>>>> Stashed changes
};

#endif // FLATTO3D_H
