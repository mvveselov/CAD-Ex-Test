#pragma once
#include "Point3D.h"
#include "Vector3D.h"
#include "Constants.h"


class Circle {
protected:
	double R1; // Radius
	double cx;
	double cy; // Center coordinates
	
public:
	Circle(double r, double cx_p = 0, double cy_p = 0);
	Circle();
	//methods
	
	double getRadius() const { return R1; }
	virtual double getX(double t) const;
	virtual double getY(double t) const;
	virtual double getZ(double t = 0) const { return 0.0; }

	virtual Point3D getPoint(double t) const;
	virtual void printPoint(double t) const;

	virtual Vector3D derive_at(double t);
	virtual void printVector(double t);
	virtual ~Circle() { /*std::cout << "Circle destructor called" << std::endl;*/ }
	bool operator<(const Circle& obj);
};
 
