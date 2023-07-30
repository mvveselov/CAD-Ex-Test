#pragma once
#include <iostream>

//перезагрузить оператор= и оператор<

struct Point3D {
	double x, y, z;
	Point3D(): x{ 0 }, y{ 0 }, z{ 0 } {}
	void print();
};


inline void Point3D::print() {
	std::cout << "Point: " << "X: " << x << " Y: " << y << " Z: " << z << std::endl;
}

//struct Point3D {
//	
////	Point3D() :x{ 0 }, y{ 0 }, z{ 0 } {}
//
//	/*void setX(double p) { x = p; }
//	void setY(double p) { y = p; }
//	void setZ(double p) { z = p; }
//
//	double getX() { return x; }
//	double getY() { return y; }
//	double getZ() { return z; }*/
//};