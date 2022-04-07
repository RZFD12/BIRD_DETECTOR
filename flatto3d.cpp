#include "flatto3d.h"
#include <QtMath>

#define pi 3.1415

flatto3d::flatto3d(QObject *parent)
    : QObject{parent}
{

}

void flatto3d::Start(QVector<int> &px, QVector<int> &py, QVector<int> &lx, QVector<int> &ly)
{
    for (int i=0;i<px.length ();i++)
    {
        this->alphaprav.append((this->videoHalfWidth-px[i])*this->tetaxprav);
        this->bettaprav.append((this->videoHalfHeight-py[i])*this->tetayprav*2*pi/360);
        this->alphalev.append((this->videoHalfWidth-lx[i])*this->tetaxlev);
        this->bettalev.append((this->videoHalfHeight-ly[i])*this->tetaylev*2*pi/360);
        if (px[i]<=this->videoHalfWidth)
        {
            this->alpha1.append((45-this->alphaprav[i])*2*pi/360);
        }
        else
        {
            this->alpha1.append((45+this->alphaprav[i])*2*pi/360);
        }
        if (lx[i]<=this->videoHalfWidth)
        {
            this->alpha2.append((45+this->alphalev[i])*2*pi/360);
        }
        else
        {
            this->alpha2.append((45-this->alphalev[i])*2*pi/360);
        }
        this->gamma.append(pi-(this->alpha1[i]+this->alpha2[i]));
        this->x1.append(this->rangeCam*sin(this->alpha2[i])/sin(this->gamma[i])*cos(this->angle*2*pi/360));
        this->x2.append(this->rangeCam*sin(this->alpha1[i])/sin(this->gamma[i])*cos(this->angle*2*pi/360));
        this->h1.append(tan(this->bettaprav[i])*this->x1[i]);
        this->h2.append(tan(this->bettalev[i])*this->x2[i]);
        this->x.append(this->rangeCam*tan(this->alpha1[i])/(tan(this->alpha1[i])+tan(this->alpha2[i])));
        this->y.append(tan(this->alpha2[i])*this->x[i]);
        this->y.append(tan(this->alpha2[i])*this->x[i]);
        this->h11.append(tan(this->angle*2*pi/360)*this->x1[i]);
        if (py[i]<=this->videoHalfHeight)
        {
            this->h3.append(this->h1[i]+this->h11[i]+1);
        }
        else
        {
            this->h3.append(this->h11[i]-this->h1[i]+1);
        }
    }
    this->alphaprav.clear (); this->alphaprav.squeeze ();
    this->bettaprav.clear (); this->bettaprav.squeeze ();
    this->alphalev.clear (); this->alphalev.squeeze ();
    this->bettalev.clear (); this->bettalev.squeeze ();
    this->alpha1.clear (); this->alpha1.squeeze ();
    this->alpha2.clear (); this->alpha2.squeeze ();
    this->gamma.clear (); this->gamma.squeeze ();
    this->x1.clear (); this->x1.squeeze ();
    this->x2.clear (); this->x2.squeeze ();
    this->h1.clear (); this->h1.squeeze ();
    this->h2.clear (); this->h2.squeeze ();
    this->x.clear (); this->x.squeeze ();
    this->y.clear (); this->y.squeeze ();
    this->h11.clear (); this->h11.squeeze ();
    this->h3.clear (); this->h3.squeeze ();
}

float flatto3d::getRangeCam() const
{
    return rangeCam;
}

void flatto3d::setRangeCam(float newRangeCam)
{
    rangeCam = newRangeCam;
}

float flatto3d::getTetaxprav() const
{
    return tetaxprav;
}

void flatto3d::setTetaxprav(float newTetaxprav)
{
    tetaxprav = newTetaxprav;
}

float flatto3d::getTetayprav() const
{
    return tetayprav;
}

void flatto3d::setTetayprav(float newTetayprav)
{
    tetayprav = newTetayprav;
}

float flatto3d::getTetaxlev() const
{
    return tetaxlev;
}

void flatto3d::setTetaxlev(float newTetaxlev)
{
    tetaxlev = newTetaxlev;
}

float flatto3d::getTetaylev() const
{
    return tetaylev;
}

void flatto3d::setTetaylev(float newTetaylev)
{
    tetaylev = newTetaylev;
}

const QVector<float> &flatto3d::getX() const
{
    return x;
}

const QVector<float> &flatto3d::getY() const
{
    return y;
}

const QVector<float> &flatto3d::getH3() const
{
    return h3;
}