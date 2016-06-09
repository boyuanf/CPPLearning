// Collections.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

#include "Person.h"
#include "functions.h"

using namespace  std;

typedef unsigned long DWORD;

typedef struct tagKPoint
{
	int x, y;
}KPoint;

void print(int i)
{
	cout << i << " ";
}

bool odd(int i)
{
	return i % 2;
}


int learnCollections()
{
	vector<int> v;
	v.push_back(3);
	v.push_back(6);
	v.push_back(9);
	v.push_back(2);
	v.pop_back();
	DWORD i1 = 11L;

	KPoint pK;
	pK.x = 2;
	pK.y = 3;

	int iChange = 2;
	cout << Change(iChange) << endl;

	for (auto i = v.begin(); i != v.end(); i++)
		cout << *i << " ";

	cout << endl;

	for (auto i = v.rbegin(); i != v.rend(); i++)
		cout << *i << " ";

	int j = v[2];

	cout << j << endl;

	Person Kate("Kate", "Gregory", 123);
	Person Someone("Someone", "Else", 456);

	vector<Person> vp;
	vp.push_back(Kate);
	vp.push_back(Someone);

	for (auto ip = vp.begin(); ip != vp.end(); ip++)
	{
		//cout << ip->GetName() << endl;  //Or
		cout << (*ip).GetName() << endl;
	}

	cout << "---------------------------------" << endl;

	map<int, Person> people;
	people[Kate.GetNum()] = Kate;
	people[Someone.GetNum()] = Someone;

	Person thrid("Third", "Fiction", 124);
	pair<int, Person> p(thrid.GetNum(), thrid);
	people.insert(p);

	for (auto ip = people.begin(); ip != people.end(); ip++)
		cout << ip->first << " " << ip->second.GetName() << endl;

	cout << endl;

	auto found = people.find(123);
	cout << found->first << " " << found->second.GetName() << endl;

	string who = people[124].GetName();
	cout << "Person at 124 is " << who << "." << endl;

	cout << "---------------------------------" << endl;
	cout << "contents of v: ";
	for_each(v.begin(), v.end(), print);
	cout << endl;

	cout << "odd element of v: ";
	auto o = find_if(v.begin(), v.end(), odd);
	while (o != v.end())
	{
		cout << *o << " ";
		o = find_if(++o, v.end(), odd);
	}
	cout << endl;

	cout << "ordered contents of v: ";
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), print);
	cout << endl;

	int length = thrid.GetName().size();
	string firstfour = thrid.GetName().substr(0, 4);
	cout << length << " " << firstfour;
	cout << endl;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), [](int n){cout << n << " "; });
	cout << endl;

	//Multiple statements in the lambda
	for_each(v.begin(), v.end(), [](int n)
	         {
		         cout << n;
		         if (n % 2 == 0)
		         {
			         cout << " even " << endl;
		         }
		         else
		         {
			         cout << " odd " << endl;
		         }
	         });
	cout << endl;

	//deducing the return type from the code
	vector<int> v2;
	transform(v.begin(), v.end(), back_inserter(v2), [](int n) {return n*n*n; });
	for_each(v2.begin(), v2.end(), [](int n){cout << n << " "; });
	cout << endl;

	//explicityly specifying the return type
	vector<double> dv;
	transform(v.begin(), v.end(), back_inserter(dv), [](int n)->double {
		          if (n % 2 == 0)
		          {
			          return n*n*n;
		          }
		          else
		          {
			          return n / 2.0;
		          }
	          });
	for_each(dv.begin(), dv.end(), [](double x){cout << x << " "; });
	cout << endl;

	//capturing by value explicityly [x,y]
	int x = 2;
	int y = 7;
	cout << "print elements between" << x << " and " << y << ": " << endl;
	for_each(v.begin(), v.end(), [x, y](int n)
	         {
		         if (n >= x && n <= y)
			         cout << n << " ";
	         });
	cout << endl;
	for_each(v.begin(), v.end(), [](int n){cout << n << " "; });
	cout << endl;

	//capturing by value implicityly [=]
	x = 3;
	y = 5;
	cout << "print elements between" << x << " and " << y << ": " << endl;
	for_each(v.begin(), v.end(), [=](int n)
	         {
		         if (n >= x && n <= y)
			         cout << n << " ";
	         });
	cout << endl;
	for_each(v.begin(), v.end(), [](int n){cout << n << " "; });
	cout << endl;

	//capturing by value and changing locally, change vector using reference
	x = 1;
	y = 1;
	for_each(v.begin(), v.end(), [=](int& r) mutable {
		         const int old = r;
		         r *= 2;
		         x = y;
		         y = old;
	         });
	cout << "doubling" << endl;
	for_each(v.begin(), v.end(), [](int n){cout << n << " "; });
	cout << endl;
	cout << "x,y: " << x << " , " << y << endl;
	cout << endl;

	//capturing by reference [&x, &y] - also changing the param
	v.clear();
	for (int i = 0; i < 10; ++i) { v.push_back(i); }
	for_each(v.begin(), v.end(), [&x, &y](int& r)
	         {
		         const int old = r;
		         r *= 2;
		         x = y;
		         y = old;
	         });
	for_each(v.begin(), v.end(), [](int n){cout << n << " "; });
	cout << endl;
	cout << "x,y: " << x << " , " << y << endl;
	cout << endl;

	//capturing all the var by reference
	v.clear();
	int i = 0;
	generate_n(back_inserter(v), 10, [&]{return i++; });
	for_each(v.begin(), v.end(), [](int n){cout << n << " "; });
	cout << endl;
	cout << "i: " << i << endl;
	cout << endl;

	//capturing by value implicityly [=,&z], and reference
	x = 3;
	y = 5;
	int z = 11;
	cout << "print elements between" << x << " and " << y << ": " << endl;
	for_each(v.begin(), v.end(), [=, &z](int n)
	         {
		         if (n >= x && n <= y)
			         cout << n << " ";
		         z = 12;
	         });
	cout << endl;
	for_each(v.begin(), v.end(), [](int n){cout << n << " "; });
	cout << endl;
	cout << "z: " << z << endl;

	//capturing by value explicityly [x,y,&z]
	x = 2;
	y = 7;
	z = 9;
	cout << "print elements between" << x << " and " << y << ": " << endl;
	for_each(v.begin(), v.end(), [x, y, &z](int n)
	         {
		         if (n >= x && n <= y)
			         cout << n << " ";
		         z = 15;
	         });
	cout << endl;
	for_each(v.begin(), v.end(), [](int n){cout << n << " "; });
	cout << endl;
	cout << "z: " << z << endl;

	try
	{
		v.clear();
		v.push_back(1);
		Person Jone("Jone","Little",0);
		int j = v.at(99);
	}
	catch (out_of_range& e)
	{
		cout << "out of range exception " << e.what();
	}
	catch(exception& e)
	{
		cout << e.what();
	}

	return 0;
}





