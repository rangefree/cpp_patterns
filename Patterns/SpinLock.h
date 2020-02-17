#pragma once
class SpinLock
{
public:
	SpinLock();
	~SpinLock();
};

#include <iostream>
#include <memory>
#include <vector>
#include <atomic>
#include <thread>

struct Node {
	int number;
	std::atomic_bool latch;

	Node() : number() {}
	void add()
	{
		lock();
		++number;
		unlock();
	}

	void lock()
	{
		bool unlatched;
		while (!latch.compare_exchange_weak(unlatched, true, std::memory_order_acquire))
			unlatched = false;
	}

	void unlock()
	{
		latch.store(false, std::memory_order_release);
	}
};

void testSpinLock();
