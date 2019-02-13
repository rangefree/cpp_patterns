#pragma once
#include"Visitor.h"
#include "VisitorTarget.h"
#include <iostream>
using namespace std;

void testVisitor()
{
	Target t;
	Target1 t1;
	Target2 t2;

	Visitor v;
	SpecificVisitor sv;

	t.accept(v);
	//	t.accept(sv);//t does not support sv

	t1.accept(v);
	t1.accept(sv);

	t2.accept(sv);
	//	t2.accept(v); //t2 does not support v
}