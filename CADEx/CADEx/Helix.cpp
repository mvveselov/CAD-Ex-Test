#include "Helix.h"


Helix::Helix(double r1, double s, double cx_p, double cy_p) 
   :Circle{ r1, cx_p, cy_p }, step{ s } {}

Helix::Helix() : Helix{ 0,0 } {}

Vector3D Helix::derive_at(double t) {
   Vector3D vec{};
   vec.x = -R1 * sin(t);
   vec.y = R1 * cos(t);
   vec.z = 1/PI*step;
   return vec;
}


Point3D Helix::getPoint(double t) const {
   Point3D point{};
   point.x = getX(t);
   point.y = getY(t);
   point.z = getZ(t);
   return point;
}

void Helix::printPoint(double t) const {
   Point3D point = getPoint(t);
   std::cout << "Helix Point_ " << "X: " << point.x << " Y: " << point.y << " Z: " << point.z << std::endl;
}

void Helix::printVector(double t) {
   Vector3D vec{};
   vec = derive_at(t);
   std::cout << "Helix Vector " << "X: " << vec.x << " Y: " << vec.y << " Z: " << vec.z << std::endl;
}