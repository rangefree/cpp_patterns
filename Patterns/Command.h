#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

//Abstract Command
class Command
{
public:
	virtual bool execute()=0;
};


//Receiver:
class Action
{
	std::string name;
	bool success;
public:
	Action(const char* p, bool aResult=true) : name(p), success(aResult) {}
	virtual bool apply() 
	{ 
		cout << "Applying " << name; 
		if (success)
			cout << endl;
		else
			cout << " failed\n";

		return success;
	}

	virtual bool remove() { cout << "Removing " << name << endl; return true; };
};


//Concreet Command: Action executer
class InstallAction : public Command
{
	Action* pA;
public:
	InstallAction(Action* A) :pA(A) {}
	virtual bool execute() { return pA->apply(); }
	void remove() { pA->remove(); }
	~InstallAction() { cout << "~InstallAction()\n"; }
};


class Installer
{
	std::vector<InstallAction*> history;
	
	void rollBack()
	{
		std::vector<InstallAction*>::reverse_iterator it(history.rbegin() );
		while (it != history.rend())
		{
			(*it)->remove();
			++it;
		}
	}

public:
	bool doCommand(InstallAction *c)
	{
		history.push_back(c);
		if (c->execute())
			return true;

		rollBack();
		return false;
	}

	~Installer()
	{
		std::vector<InstallAction*>::iterator it(history.begin());
		while (it != history.end())
		{
			delete *it;
			++it;
		}
	}
};


void testCommand();

