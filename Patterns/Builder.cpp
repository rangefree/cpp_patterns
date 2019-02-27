#include "Builder.h"



void testBuilder()
{

	CarFactory f;
	SedanBuilder sedanB;
	SuvBuilder suvB;
	shared_ptr<Car> pCar1(f.construct(suvB));
	shared_ptr<Car> pCar2(f.construct(sedanB));

	//shared_ptr<Car*>car1(f.construct(suvB));
}