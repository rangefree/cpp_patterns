#include "Observer.h"
void testObserver()
{
	Observable O;
	ConcreteObserver a(O), b(O), c(O);

	O.Notify();//broadcast notification
}

