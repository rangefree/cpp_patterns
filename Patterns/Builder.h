#pragma once
#include <string>
#include <iostream>

using namespace std;

struct CarImp
{
	uint16_t sits;
	CarImp() : sits(1) {}
};

struct SedanImp : CarImp
{
	SedanImp() : CarImp() { sits = 5; }
};

struct SuvImp : CarImp
{
	SuvImp() : CarImp() { sits = 5; }
};


class Car
{
	string plate;
	string brand;
	CarImp* hardware;

public:
	Car(): hardware(NULL) {}
	Car(CarImp* aHardware): hardware(aHardware){}
};


class CarBuilder
{
public:
	virtual ~CarBuilder() {};
	virtual CarImp* build() = 0;

protected:
	CarBuilder() {}
};

class SedanBuilder : public CarBuilder
{
public:
	SedanBuilder() {};
	virtual CarImp* build(){return new SedanImp;}
};

class SuvBuilder : public CarBuilder
{
public:
	SuvBuilder() {};
	virtual CarImp* build() { return new SuvImp; }
};


class CarFactory
{
public:
	Car* construct(CarBuilder& builder){ return new Car(builder.build()); }
};



/*
class Factory
{
public:
};


class Product
{
};

class Builder
{
public:
	virtual Product* getProduct() = 0;
};

class ConcreteProduct1
{
	int partA;
	int partB;
public:
	ConcreteProduct1() : partA(0), partB(0) {}
	void show() { cout << "I am Product1 (" << partA << "," << partB << ") \n"; }
};


class ConcreteProduct2
{
	int partA;
	int partB;
	int partC;
public:
	ConcreteProduct2(): partA(0), partB(0), partC(0){}
	void show() { cout << "I am Product2 (" << partA << ","	<< partB << "," << partC <<	") \n"; }
};

class BuilderForProd1 : public Builder
{
public:
	BuilderForProd1() {};

};
*/

void testBuilder();

