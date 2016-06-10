#include "stdafx.h"
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

//#include "Person.h"
#include "Tweeter.h"
#include "Status.h"
#include "Accum.h"
#include "Resource.h"

using namespace  std;

void LearnInheritance()
{
	Person p1("Kate", "Gregory", 123);
	{
		Tweeter  p2("Someone", "Else", 456,"@whoever");
	}
	std::cout << "after innermost block" << std::endl;
	Status s = Pending;
	s = Approved;
}

//void testa(){}
//int testa(){}

template <class T> 
T max(T &t1, T &t2)
{
	return t1 < t2 ? t2 : t1; 
}

void ImmediateIf()
{
	int x = 99;
	string sign = x > 0 ? "positive" : "0 or negative";
	cout << sign << endl;
}

void learnfunctiontemplate()
{
	Person p1("Kate", "Gregory", 123);
	Person p2("Someone", "Else", 456);
	cout << "p1 is ";
	if (!(p1 < p2))
		cout << "not ";
	cout << "less than p2" << endl;

	cout << "p1 is ";
	if (!(p1 < 300))
		cout << "not ";
	cout << "less than 300" << endl;

	cout << "300 is ";
	if (!(300 < p1))
		cout << "not ";
	cout << "less than p1" << endl;

	cout << max(33, 44) << endl;
	string s1 = "hello";
	string s2 = "world";
	cout << max(s1, s2) << endl;
	cout << "max of " << p1.GetName() << " and " << p2.GetName() <<
		" is " << max(p1, p2).GetName() << endl;
}

void classtemplate()
{
	Accum<int> integers(0);
	integers += 3;
	integers += 7;
	cout << integers.GetTotal() << endl;

	Accum<string> strings("");
	strings += "hello";
	strings += "world";
	cout << strings.GetTotal() << endl;

	Accum<Person> total(0);
	Person p1("Kate", "Gregory", 123);
	Person p2("Someone", "Else", 456);
	total += p1;
	total += p2;
	cout << total.GetTotal() << endl;
}

void PointerReference()
{
	int i = 3;
	const int ci = 3;
	i = 4;

	int j = 10;
	Person Kate("Kate", "Gregory", 123);
	Person *pKate = &Kate;
	(*pKate).SetNum(235);
	cout << Kate.GetNum() << " " << pKate->GetNum() << " " << (*pKate).GetNum() << endl;

	Person& rKate = Kate;
	rKate.SetNum(345);
	cout << Kate.GetNum() << " " << rKate.GetNum() << endl;

	cout << Kate.GetNum() << " " << rKate.GetNum() << endl;

	int *pI = &i;
	const int * pII = &ci;

	const int *pcI = pI;  //pointer to a const
	//*pcI = 6;
	int *pcI2 = pI;
	*pcI2 = 5;
	pcI = &j;

	int * const cpI = pI; //const pointer
	*cpI = 7;
	//cpI = &j;
}

void SmartPointer()
{
	shared_ptr<int> ptrInt(new int[5]);
	shared_ptr<int> ptrInt2 =make_shared<int>(100);  //declare only 1 int

	for (int i = 0; i < 5; i++)
	{
		cout << *(ptrInt+1) << endl;
	}

	{
		Resource localResource("local");
		string localstring = localResource.GetName();
	}
	Person p1("Kate", "Gregory", 123);
	p1.AddResource();
	p1.SetFirstName("Kate2");
	p1.AddResource();
	Person p2 = p1;
	p1 = p2;

	string s1 = p1.GetResourceName();
}

int _tmain(int argc, _TCHAR* argv[])
{
	

	SmartPointer();
	//PointerReference();
	//classtemplate();
	//learnfunctiontemplate();
	//ImmediateIf();
	//LearnInheritance();
	//learnCollections();
	return 0;
}
