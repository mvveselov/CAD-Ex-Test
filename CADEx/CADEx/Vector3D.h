#pragma once
#include <iostream>

//если можно обойтись без информации о точке, то оставить без параметра или Point3D

struct Vector3D {
	double x, y, z;

	Vector3D(double xp, double yp, double zp) :x{ xp }, y{ yp }, z{ xp }{}
	Vector3D() : Vector3D(0, 0, 0) {};

	void print();
};


inline void Vector3D::print() {
	std::cout << "Vector: " << "X: " << x << " Y: " << y << " Z: " << z << std::endl;
}