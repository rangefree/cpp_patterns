#pragma once
#include <iostream>
using namespace std;

class Visitor;
class SpecificVisitor;

class Target
{
public:
	void accept(Visitor& rV);
};


class Target1 : public Target
{
public:
	void accept(Visitor& rV);
	void accept(SpecificVisitor& rV);
};

class Target2 : public Target
{
public:
	void accept(SpecificVisitor& rV);
};
