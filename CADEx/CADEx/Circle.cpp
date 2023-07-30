#include <cmath>
#include "Circle.h"



//Overloaded constructor
Circle::Circle(double r, double cx_p, double cy_p)
   :R1{ abs(r) }, cx{ cx_p }, cy{ cy_p } {/*std::cout << "Circle constructor called" << std::endl;*/ }

//Default contructor
Circle::Circle()
	: Circle(0,0,0) {}


//Methods
double Circle::getX(double t) const {
	return R1 * cos(t) + cx;
}

double Circle::getY(double t) const {
	return R1 * sin(t) + cy;
}
 

Point3D Circle::getPoint(double t) const {
   Point3D point{};
   point.x = getX(t);
   point.y = getY(t);
   point.z = getZ(t);
   return point;
}


void Circle::printPoint(double t) const {
   Point3D point = getPoint(t);
  std::cout << "Circle Point_ "  << "X: " << point.x << " Y: " << point.y << " Z: " << point.z << std::endl;
}

Vector3D Circle::derive_at(double t) {
   Vector3D vec{};
   vec.x = -R1 * sin(t);
   vec.y = R1 * cos(t);
   vec.z = 0.0;
   return vec;
}

//возможно придется определить дерайв здесь внутри
void Circle::printVector(double t) {
   Vector3D vec{};
   vec = derive_at(t);
   std::cout << "Circle Vector " << "X: " << vec.x << " Y: " << vec.y << " Z: " << vec.z << std::endl;
}

bool Circle::operator<(const Circle& obj) {
   return this->R1 < obj.R1;
}