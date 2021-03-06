#include <iostream>
using namespace std;

#include"TestVisitor.h"
#include "Observer.h"
#include "Template.h"
#include "Command.h"
#include "Adapter.h"
#include "Builder.h"
#include "SpinLock.h"

int main()
{
	testVisitor();
	cout << "\n\n";

	testObserver();
	cout << "\n\n";

	testTemplate();
	cout << "\n\n";

	testCommand();
	cout << "\n\n";

	testAdapter();
	cout << "\n\n";

	testBuilder();
	cout << "\n\n";

	testSpinLock();
	cout << "\n\n";
}
