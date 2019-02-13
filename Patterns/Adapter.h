#pragma once
#include <string>
#include <iostream>
#include <sstream>
using namespace std;


class OldWidget
{
	int id;
	int sessionId;
public:
	OldWidget(int aId, int aCode ) : id(aId), sessionId(aCode) {}

	int getId()const {return id; }
	int getSessionId()const { return sessionId; }

};

class WidgetInterface
{
public:
	virtual std::string getToken()const = 0;
};

class NewWidget : public WidgetInterface
{
	std::string token;
public:
	NewWidget(const std::string& aToken) : token(aToken) {}
	virtual std::string getToken()const { return token; }
};

class OldWidgetAdapter :
	public WidgetInterface,
	public OldWidget
{
	std::string token;
public:
	OldWidgetAdapter(int aId, int aCode) : OldWidget(aId, aCode)
	{
		std::stringstream ss;
		ss << getSessionId() << "-" << getId();
		token = ss.str();
	}

	virtual std::string getToken()const { return token;}
};

void testAdapter();

