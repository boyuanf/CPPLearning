#include "stdafx.h"

#include "Person.h"
#include <iostream>

using namespace std;

Person::Person() : firstname(""),lastname(""),arbitrarynumber(0)
{
}

Person::Person(string first,string last,
	int arbitrary) : firstname(first),lastname(last),
	arbitrarynumber(arbitrary)
{ 
	if (arbitrarynumber==0)
	{
		throw invalid_argument("arbitrary number for a person cannot be 0");
	}
	cout << "constructing Person" <<
		firstname << " " << lastname << endl;
}

Person::~Person()
{
	cout << "destructing  Person" <<
		firstname << " " << lastname << endl;
}

bool Person::operator<(Person& p)
{
	return arbitrarynumber < p.arbitrarynumber;
}

bool Person::operator<(int i)
{
	return arbitrarynumber < i;
}

bool operator<(int i, Person& p)
{
	return i < p.arbitrarynumber;
}
