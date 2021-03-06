#include "stdafx.h"

#include "Person.h"
#include <iostream>

using namespace std;

Person::Person() : firstname(""), lastname(""), arbitrarynumber(0)/*, pResource(nullptr)*/
{
}

//Person::Person(const Person& p) : firstname(p.firstname), lastname(p.lastname),
//arbitrarynumber(p.arbitrarynumber), pResource(new Resource(p.pResource->GetName()))
//{
//}
//
Person::Person(string first,string last,
	int arbitrary) : firstname(first),lastname(last),
	arbitrarynumber(arbitrary)/*, pResource(nullptr)*/
{ 
	if (arbitrarynumber==0)
	{
		throw invalid_argument("arbitrary number for a person cannot be 0");
	}
	cout << "constructing Person " <<
		firstname << " " << lastname << endl;
}

Person::~Person()
{
	//delete pResource;
	cout << "destructing  Person " <<
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

void Person::AddResource()
{
	pResource.reset();
	pResource = std::make_shared<Resource>("Resource for " + GetName());
}

bool operator<(int i, Person& p)
{
	return i < p.arbitrarynumber;
}

void Person::SetFirstName(string fName)
{
	firstname = fName;
}

//Person& Person::operator=(const Person& p)
//{
//	firstname=p.firstname;
//	lastname = p.lastname;
//	arbitrarynumber = p.arbitrarynumber;
//	delete pResource;
//	pResource=new Resource(p.pResource->GetName());
//	return *this;
//}
