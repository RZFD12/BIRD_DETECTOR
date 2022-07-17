#ifndef FLATTO3D_H
#define FLATTO3D_H

#include <QObject>
#include <QVector3D>
#include <QPoint>

class flatto3d final : public QObject
{
    Q_OBJECT
public:
    explicit flatto3d(QObject *parent = nullptr);
    void Start(QVector<QPoint> r, QVector<QPoint> l);
    const float& getRangeCam() const;
    void setRangeCam(float newRangeCam);
    const float& getAngle() const;
    void setAngle(float newAngle);
    const float& getTetaxprav() const;
    void setTetaxprav(float newTetaxprav);
    const float& getTetayprav() const;
    void setTetayprav(float newTetayprav);
    const float& getTetaxlev() const;
    void setTetaxlev(float newTetaxlev);
    const float& getTetaylev() const;
    void setTetaylev(float newTetaylev);
    const QVector<QVector3D>& getVec3D() const;
    void Clear();
    const float &getBtwangle() const;
    void setBtwangle(float newBtwangle);

private:
    float rangeCam = 1.39;
    float angle = 0.0;
    float btwangle = 0.0;
    float tetayprav = 0.053089;
    float tetaxprav = 0.054808;
    float tetaylev = 0.053089;
    float tetaxlev = 0.054808;
    int videoHalfWidth = 960;
    int videoHalfHeight = 540;
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

signals:

};

#endif // FLATTO3D_H
