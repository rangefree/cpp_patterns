#pragma once
#include <set>
#include <iostream>

using namespace std;

class Observer
{
public:
	virtual void Notify() = 0;
};


class Observable
{ 
	set<Observer*> observers;

public:
	bool add(Observer* pO) 
	{ 
		if (!pO)
			return false;

		observers.insert(pO);
		return true;
	}

	void remove(Observer* pO)
	{
		observers.erase(pO);
	}

	void Notify()
	{
		std::cout << "Do broadcasting:\n";
		set<Observer*>::iterator it(observers.begin());
		while (it != observers.end())
		{//notify all
			try { (*it)->Notify(); }
			catch (...) {}
			++it;
		}
	}
};

class ConcreteObserver : public Observer
{
public:
	ConcreteObserver(Observable& r)
	{
		if (r.add(this))
			std::cout << this << " is attached to Observable\n";
		else
			std::cout << this << " failed to attach to Observable\n";
	}

	virtual void Notify() { std::cout << "  " << this << " is notified..." << std::endl; }
};

void testObserver();
