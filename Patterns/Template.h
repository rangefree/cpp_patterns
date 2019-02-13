#pragma once
#include <iostream>
using namespace std;

//Template pattern impl:
class BaseTransaction
{
	unsigned max;

protected:
	void setAllowedMax(unsigned ammount) { max = ammount; }
	unsigned getAllowedMax() { return max; }
	virtual bool Allowed(unsigned ammount) = 0;
	virtual void Begin() = 0;
	virtual void End() = 0;

public:

	//Template method
	void withdraw(unsigned ammount)
	{
		Begin();

		cout << "Withdraw " << ammount << " ";
		if (Allowed(ammount))
			cout << " withdraw is complete\n";
		else
			cout << " withdraw is not allowed\n";

		End();
	}
};

class NormalTran : public BaseTransaction
{
protected:
	virtual bool Allowed(unsigned ammount)
	{
		if (getAllowedMax() >= ammount)
		{
			cout << "Normal Transaction: ";
			return true;
		}
		else
		{
			cout << "Normal Transaction maximum is " << getAllowedMax() << ". ";
			return false;
		}
	}

	virtual void Begin() {
		cout << "Begin Normal Transaction:\n";
	}
	
	virtual void End()
	{
		cout << "End Normal Transaction.\n";
	}
public:
	NormalTran() : BaseTransaction() { setAllowedMax(1000); }
};


class AdvTran : public BaseTransaction
{
	unsigned min;

protected:
	virtual bool Allowed(unsigned ammount)
	{

		if (ammount <= getAllowedMax())
		{
			if (min > ammount)
			{
				cout << "Advanced transaction minimum is " << min << ", ";
				return false;
			}
			else
			{
				cout << "Advanced Transaction: ";
				return true;
			}

		}
		else
		{
			cout << "Advanced transaction maximum is " << getAllowedMax() << ", ";
			return false;
		}

	}
	virtual void Begin() {
		cout << "Begin Advanced Transaction:\n";
	}

	virtual void End()
	{
		cout << "End Advanced Transaction.\n";
	}

public:
	AdvTran() : BaseTransaction(), min(500) { setAllowedMax(2000); }
};

void testTemplate();

