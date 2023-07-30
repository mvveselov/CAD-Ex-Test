#pragma once
#include "Circle.h"
#include "Constants.h"
//extern const double PI;

//extern PI;

class Helix:public Circle
{
	double step;
public:

	Helix(double r1, double s, double cx_p = 0, double cy_p = 0);
	Helix();

	virtual Vector3D derive_at(double t);
	virtual double getZ(double t = 0) const { return t / 2 / PI * step; }
	virtual Point3D getPoint(double t) const;

	virtual void printPoint(double t) const;
	virtual void printVector(double t);
	virtual ~Helix() {};
};

