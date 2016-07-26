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
#include "Collections.h"

using namespace  std;

void LearnInheritanceandEnum()
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

	shared_ptr<int> ptrInt2 = make_shared<int>(100);  //declare only 1 int
	
	unique_ptr<int []> ptrInt(new int[5]);  //use unique pointers point to array
	ptrInt.get()[0] = 5;
	*(ptrInt.get() + 1) = 6;
	ptrInt[2] = 7;
	for (auto pInt = ptrInt.get(); pInt < ptrInt.get() + 3; pInt++) cout << *pInt << endl;

	//use shared pointers point to array
	shared_ptr<string> sp(new string[4], [](string *p) { delete[] p; });
	sp.get()[0] = "string 1";
	sp.get()[1] = "string 2";
	sp.get()[2] = "string 3";
	*(sp.get() + 3) = "string 4";
	for (auto q = sp.get(); q < sp.get() + 4; q++) cout << *q << endl;

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

void Polymorphism()
{
	Person *Kate=new Person("Kate", "Gregory", 123);
	Tweeter *KateTw = new Tweeter("Kate", "Gregory", 456,"@KG");

	Person *pKate = KateTw;

	cout << Kate->GetName() << endl;
	cout << KateTw->GetName() << endl;
	cout << pKate->GetName() << endl;

	delete pKate;

	auto spKate = make_shared<Person>("Kate", "Gregory", 567);
	cout << spKate->GetName() << endl;

	shared_ptr<Person> spKateTw = make_shared<Tweeter>("Kate", "Gregory", 789,"@SPKate");
	cout << spKateTw->GetName() << endl;

	Person localP("Local", "Person", 333);
	//Tweeter localT = localP;

	//-----------------Slicing-----------------//
	Tweeter localT2("Local", "Tweeter", 444, "@local");
	Person localP2 = localT2;
	cout << localP2.GetName() << endl;

	//----------Use reference to avoid slicing-----------//
	Tweeter localT3("Local", "Tweeter", 444, "@local");
	Person& localP3 = localT3;
	cout << localP3.GetName() << endl;

}

void Casting()
{
	Tweeter t("Kate", "Gregory", 123, "@gregcons");
	Person* p = &t;
	Tweeter* pt = static_cast<Tweeter*>(p);  //works fine
	cout << pt->GetName() << endl;
	Tweeter* pdt = dynamic_cast<Tweeter*>(p);  //works fine
	cout << pdt->GetName() << endl;


	Person *Kate = new Person("Kate", "Gregory", 123);
	Tweeter* ptt = static_cast<Tweeter*>(Kate);  //works but unsafe
	cout << ptt->GetName() << endl;
	//cout << ptt->twitterhandle << endl;   //will cause crash


	Resource f("local");
	Tweeter* pi = dynamic_cast<Tweeter*>(&f);
	if (pi)
	{
		cout << pi->GetName() << endl;
	}
	else
	{
		cout << "Resource can't be cast to Tweeter!" << endl;
	}
}

class Base
{
public:
	virtual ~Base(){}
};

class Derived : public Base
{
};

void f()
{
	try
	{
		throw Derived();
	}
	catch (Derived& ex)
	{
		cout << "Caught in f\n";
		throw;
	}

}


void TestTryCatch()
{
	try{

		try {
			throw Derived();
		}
		catch (const Derived &d) {
			throw;
		}
		catch (const Base &b) {
			cout << "caught Base 1!" << endl;
		}

	}
	catch (const Base &b) {
		cout << "caught Base 2!" << endl;
	}
	catch (const Derived &d) {
		cout << "caught Derived 2!" << endl;
	}
	/*try
	{
	f();
	}
	catch (Base& b)
	{
	cout << "Caught in main\n";
	}*/
}

int _tmain(int argc, _TCHAR* argv[])
{
	//TestTryCatch();
	//Casting();
	//Polymorphism();
	//SmartPointer();
	//PointerReference();
	//classtemplate();
	//learnfunctiontemplate();
	//ImmediateIf();
	//LearnInheritanceandEnum();
	//learnCollections();
	return 0;
}
