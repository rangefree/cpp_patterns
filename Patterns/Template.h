#pragma once
#include <iostream>
using namespace std;

class BaseTransaction
{
	unsigned max;

protected:
	void setAllowedMax(unsigned ammount) { max = ammount; }
	unsigned getAllowedMax() { return max; }
	virtual bool allowed(unsigned ammount) = 0;

public:

	void withdraw(unsigned ammount)
	{
		cout << "Withdraw " << ammount << " ";
		if (allowed(ammount))
			cout << " withdraw is complete\n";
		else
			cout << " withdraw is not allowed\n";
	}
};

class NormalTran : public BaseTransaction
{
protected:
	virtual bool allowed(unsigned ammount)
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

public:
	NormalTran() : BaseTransaction() { setAllowedMax(1000); }
};


class AdvTran : public BaseTransaction
{
	unsigned min;

protected:
	virtual bool allowed(unsigned ammount)
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

public:
	AdvTran() : BaseTransaction(), min(500) { setAllowedMax(2000); }
};

void testTemplate();

