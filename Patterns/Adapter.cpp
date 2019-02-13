#include "Adapter.h"


void testAdapter()
{
	NewWidget NW("123-456");
	OldWidgetAdapter OWA(456, 123);

	//"NewWidget->getToken(): "

	cout << typeid(NW).name() << "::getToken(): " << NW.getToken() << endl;
	cout << typeid(OWA).name() << "::getToken(): " << OWA.getToken() << endl;
}