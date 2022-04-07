#ifndef FLATTO3D_H
#define FLATTO3D_H

#include <QObject>

class flatto3d : public QObject
{
    Q_OBJECT
public:
    explicit flatto3d(QObject *parent = nullptr);
    void Start(QVector<int> px, QVector<int> py, QVector<int> lx, QVector<int> ly);
    void Clear();

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

    float getAngle() const;
    void setAngle(float newAngle);

private:
    float rangeCam=80;
    float angle=5;
    float tetaxprav=0.043;
    float tetayprav=0.038;
    float tetaxlev=0.056;
    float tetaylev=0.095;
    int videoHalfWidth=960;
    int videoHalfHeight=540;
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
    QVector<float>h3;

signals:

};

#endif // FLATTO3D_H
