#include "stdafx.h"
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <regex>
#include <sstream>

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
	cout << "after innermost block" << endl;
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

//class A
//{
//public:
//	A()
//	{
//		cout << 1;
//	}
//
//};
//
//class B:A
//{
//public:
//	B()
//	{
//		cout << 3;
//	}
//
//};
//
//void Foo(int x)
//{
//	cout << "1";
//}
//void Foo(int* x)
//{
//	cout << "2";
//}
//void Foo(int** x)
//{
//	cout << "3";
//}
//void Bar(int& x)
//{
//	Foo(&x);
//	int *y = (int*)&x;
//	Foo(y);
//	Foo(*y);
//	Foo(&y);
//}

//class A {}
//class B
//{
//public:
//	virtual float eat();
//	virtual void Sleep();
//	/*public static void Foo()
//	{
//		object a = new A();
//		B b = null;
//		try
//		{
//			b = (B)a;
//			Console.Write("1");
//		}
//		catch (Exception) {}
//		try
//		{
//			b = a as B;
//
//		}
//
//	}*/
//	
//};

class TPA
{
public:
	TPA()
	{
		cout << "constructor of TPA!" << endl;
	}

	void virtual testVirtualA()
	{
		printf("Test virtual in A\n");
	}

	void testHideA()
	{
		printf("Test hide in A\n");
	}

	int test1 = 1;

	virtual ~TPA()
	{
		cout << "deconstructor of TPA!" << endl;
	}
};

class TPB : public TPA
{
public:
	TPB()
	{
		cout << "constructor of TPB!" << endl;
	}
	void testTPB()
	{
		return;
	}

	void testVirtualA()
	{
		printf("Test virtual in B\n");
	}

	void testHideA()
	{
		printf("Test hide in B\n");
	}

	int test1 = 2;

	~TPB()
	{
		cout << "deconstructor of TPB!" << endl;
	}
};

void Testpolymorphism()
{
	TPA pp = TPB();

	//// constructor and deconstructor
	//TPB bConstrutor;

	//// test the way to create class object
	//TPA aaq = TPA();  
	//TPA aap;
	//aaq.test1 = 6;
	//aap.test1 = 7;

	//

	//// Test slicing
	//printf("Test slicing\n");
	//TPA aa = TPB();
	////aa.testTPB();  //don't have the member function.
	//aa.testVirtualA();
	//aa.testHideA();
	//cout << aa.test1;  //will print the value of TPA


	////TPB bb = TPA();  // compile error

	//printf("-----------------------\n");

	//// Test virtual and hide
	//printf("Test virtual and hide\n");
	//TPA *a = new TPA();
	//TPB *b = new TPB();
	//TPA *c = b;
	//c->testVirtualA();
	//c->testHideA();
	////c.testTPB();  //can't find the method
	////TPB *d = a;   //compile error
}



int _tmain(int argc, _TCHAR* argv[])
{
	Testpolymorphism();
	

	SmartPointer();
	//PointerReference();
	//classtemplate();
	//learnfunctiontemplate();
	//ImmediateIf();
	//LearnInheritanceandEnum();
	//learnCollections();
	return 0;
}
