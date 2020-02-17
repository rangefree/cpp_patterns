#include "SpinLock.h"



SpinLock::SpinLock()
{
}


SpinLock::~SpinLock()
{
}


void thread_proc(Node& node)
{
	for (int i = 0; i < 1000000; ++i)
		node.add();
}

void testSpinLock()
{
	Node node;
	std::thread t1(thread_proc, std::ref(node));
	std::thread t2(thread_proc, std::ref(node));
	t1.join();
	t2.join();
	std::cout << node.number << '\n';
}

