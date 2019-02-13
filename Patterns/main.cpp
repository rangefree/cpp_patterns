#include <iostream>
using namespace std;

#include"TestVisitor.h"
#include "Observer.h"
#include "Template.h"


int main()
{
	testVisitor();
	cout << "\n\n";

	testObserver();
	cout << "\n\n";

	testTemplate();
	cout << "\n\n";

}
