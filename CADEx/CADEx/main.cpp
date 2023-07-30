
#include <iostream>
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"
#include <vector>
#include <algorithm>
#include <memory>


using namespace std;


ostream& operator<< (std::ostream& os, const Circle& obj) {
	os << "Radius: " << obj.getRadius();
	return os;
}

bool comparePointers(const shared_ptr<Circle> a, const shared_ptr<Circle> b) {
	return *a < *b;
}


int main() {
	srand(time(NULL));
	double sumRadii{0};// sum of radii

	//Populate a container
	//of objects of these types created in random manner 
	//with random parameters.
	vector<shared_ptr<Circle>>first{};
	
	int counter = 0;
	int choise{ 0 };

	while (counter < 15) {
		choise = rand() % 3;
		//cout << "Choise: " << choise << endl;
		if (choise == 0)
			first.push_back(make_shared<Circle>( double(rand() % 100) ));
			
		else if(choise == 1)
			first.push_back(make_shared<Ellipse>(double(rand() % 100), double(rand() % 100)));
			
		else if(choise == 2)
			first.push_back(make_shared<Helix>(double(rand() % 100), double(rand() % 100)));

		counter++;
	}

	first.shrink_to_fit();

	//Print coordinates of points and derivatives of all curves in the container at t=PI/4
	cout << "\n-------Print first----------\n" << endl;
	for (auto vec : first) {
		cout << "*******" << endl;
		vec->printPoint(PI / 4);
		vec->printVector(PI / 4);
	}
	
	

	/*Populate a second container that would
	contain only circles from the first container.
	Make sure the second container shares(i.e. not clones) 
	circles of the first one, e.g.via pointers*/
	vector<shared_ptr<Circle>>second{};

	for (const auto& vec : first) {
			if (typeid(Circle) == typeid(*vec))
				second.push_back(vec);
	}


	cout << "\n-------Print Second--------\n" << endl;
	for (auto vec : second) {	
		vec->printPoint(PI / 4);
	}

	cout << "\n---Printing radiuses of Circles---\n" << endl;
	for (auto vec : second) {
		cout << *vec << endl;
	}

	std::sort(second.begin(), second.end(), comparePointers);

	cout << "\n---Printing Radiuses of sorted Circles---\n" << endl;
	for (auto vec : second) {
		cout << *vec << endl;
		sumRadii += vec->getRadius();
	}

	cout << "Total sum of radii: " << sumRadii << endl;
}