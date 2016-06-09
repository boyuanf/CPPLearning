#include "stdafx.h"
#include "Tweeter.h"
#include <iostream>


Tweeter::Tweeter(std::string first, std::string last,
	int arbitrary, std::string handle) :Person(first, last, arbitrary),
										twitterhandle(handle)
{
	std::cout << "constructing Tweeter " <<
		twitterhandle << " " << lastname << std::endl;
}


Tweeter::~Tweeter()
{
	std::cout << "destructing  Tweeter " <<
		twitterhandle << " " << lastname << std::endl;
}
