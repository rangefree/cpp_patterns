#pragma once
#include <iostream>
using namespace std;

class Target;
class Target1;
class Target2;

class Visitor
{
public:
	void add(Target& t)
	{
		cout << "Visitor add(Target& t)" << endl;
	}

	void add(Target1& t)
	{
		cout << "Visitor add(Target1& t)" << endl;
	}
};

class SpecificVisitor
{
public:
	void add(Target1& t)
	{
		cout << "SpecificVisitor add(Target1& t)" << endl;
	}

	void add(Target2& t)
	{
		cout << "SpecificVisitor add(Target2& t)" << endl;
	}

};

