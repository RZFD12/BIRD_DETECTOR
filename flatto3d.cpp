#include "flatto3d.h"

flatto3d::flatto3d(QObject* parent)
    : QObject(parent),
      rangeCam(1.39),
      angle(0.0),
      btwangle(0.0),
      tetayprav(0.053089),
      tetaxprav(0.054808),
      tetaylev(0.053089),
      tetaxlev(0.054808),
      videoHalfWidth(960),
      videoHalfHeight(540),
      alphaprav(),
      bettaprav(),
      alphalev(),
      bettalev(),
      alpha1(),
      alpha2(),
      gamma(),
      x1(),
      x2(),
      h1(),
      h2(),
      h11(),
      vec3D()
{}

void flatto3d::Start(QVector<QPoint> r, QVector<QPoint> l)
{
    for (int i = 0; i < r.length(); i++)
    {
        this->vec3D.push_back(QVector3D());
        this->alphaprav.append(abs((r[i].x())*this->tetaxprav));
        this->bettaprav.append((r[i].y())*this->tetayprav*2*M_PI/360);
        this->alphalev.append(abs((l[i].x())*this->tetaxlev));
        this->bettalev.append((l[i].y())*this->tetaylev*2*M_PI/360);
        if (r[i].x() <= 0)
        {
            this->alpha1.append((this->btwangle-this->alphaprav[i])*2*M_PI/360);
        }
        else
        {
            this->alpha1.append((this->btwangle+this->alphaprav[i])*2*M_PI/360);
        }
        if (l[i].x() <= 0)
        {
            this->alpha2.append((this->btwangle+this->alphalev[i])*2*M_PI/360);
        }
        else
        {
            this->alpha2.append((this->btwangle-this->alphalev[i])*2*M_PI/360);
        }
        this->gamma.append(M_PI-(this->alpha1[i]+this->alpha2[i]));
        this->x1.append(this->rangeCam*sin(this->alpha2[i])/sin(this->gamma[i])*cos(this->angle*2*M_PI/360));
        this->x2.append(this->rangeCam*sin(this->alpha1[i])/sin(this->gamma[i])*cos(this->angle*2*M_PI/360));
        this->h1.append(tan(this->bettaprav[i])*this->x1[i]);
        this->h2.append(tan(this->bettalev[i])*this->x2[i]);
        this->vec3D[i].setX(this->rangeCam*tan(this->alpha1[i])/(tan(this->alpha1[i])+tan(this->alpha2[i])));
        this->vec3D[i].setY(tan(this->alpha2[i])*this->vec3D[i].x());
        this->h11.append(tan(this->angle*2*M_PI/360)*this->x1[i]);
        if (r[i].ry() <= this->videoHalfHeight)
        {
            this->vec3D[i].setZ(this->h1[i]+this->h11[i]+1.5);
        }
        else
        {            
            this->vec3D[i].setZ(this->h11[i]-this->h1[i]+1.5);
        }
    }
}

void flatto3d::Clear()
{
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
    this->h11.clear (); this->h11.squeeze ();
    this->vec3D.clear(); this->vec3D.squeeze();
}
