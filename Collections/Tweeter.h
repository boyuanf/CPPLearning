#pragma once   //
#include "Person.h"
#include <string>

#ifndef _TWEETER_H
#define _TWEETER_H

class Tweeter :
	public Person
{
public:
	std::string twitterhandle;
public:
	Tweeter(std::string first, std::string last,
		int arbitrary, std::string handle);
	~Tweeter();
	std::string GetName() const { return Person::GetName() + " " + twitterhandle; }
};
#endif


