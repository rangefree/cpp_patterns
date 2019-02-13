#include "VisitorTarget.h"
#include "Visitor.h"

void Target::accept(Visitor& rV)
{
	cout << "Target accept(): ";
	rV.add(*this);
}


void Target1::accept(Visitor& rV)
{
	cout << "Target1 accept(): ";
	rV.add(*this);
}

void Target1::accept(SpecificVisitor& rV)
{
	cout << "Target1 accept(): ";
	rV.add(*this);
}

void Target2::accept(SpecificVisitor& rV)
{
	cout << "Target2 accept(): ";
	rV.add(*this);
}