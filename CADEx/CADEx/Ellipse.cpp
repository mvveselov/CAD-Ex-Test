#include "Ellipse.h"


Ellipse::Ellipse(double r1, double r2, double cx_p, double cy_p)
   : Circle{ r1, cx_p, cy_p }, R2{ abs(r2) } {}

Ellipse::Ellipse() : Ellipse{ 0,0 } {}


double Ellipse::getX(double t) const {
	return R1 * cos(t) + cx;
}

double Ellipse::getY(double t) const {
	return R2 * sin(t) + cy;
}



Point3D Ellipse::getPoint(double t) const{
   Point3D point{};
   point.x = getX(t);
   point.y = getY(t);
   point.z = getZ(t);
   return point;
}


void Ellipse::printPoint(double t) const {
	Point3D point = getPoint(t);
	std::cout << "Ellipse Point_ " << "X: " << point.x << " Y: " << point.y << " Z: " << point.z << std::endl;
}


Vector3D Ellipse::derive_at(double t) {
   Vector3D vec{};
   vec.x = -R1 * sin(t);
   vec.y = R2 * cos(t);
   vec.z = 0.0;
   return vec;
}

//возможно придется определить дерайв здесь внутри
void Ellipse::printVector(double t) {
   Vector3D vec{};
   vec = derive_at(t);
   std::cout << "Ellipse Vector " << "X: " << vec.x << " Y: " << vec.y << " Z: " << vec.z << std::endl;
}