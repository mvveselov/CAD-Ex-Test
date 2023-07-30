#pragma once
#include "Circle.h"
#include "Constants.h"

class Ellipse: public Circle {
	double R2;
public:
	Ellipse(double r1, double r2, double cx_p=0, double cy_p=0);
	Ellipse();

	virtual double getX(double t) const;
	virtual double getY(double t) const;
	virtual double getZ(double t = 0) const { return 0.0; }

	virtual Point3D getPoint(double t) const;
	virtual void printPoint(double t) const;

	virtual Vector3D derive_at(double t);
	virtual void printVector(double t);

	virtual ~Ellipse() { /*std::cout << "Ellipse destructor called" << std::endl;*/ }
};

