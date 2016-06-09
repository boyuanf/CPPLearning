#pragma once
#include "Person.h"

template <class T>
class Accum
{
private:
	T total;
public:
	Accum(T start) : total(start){}
	T operator+=(const T&t){ return total = total + t; }
	T GetTotal(){ return total; }
	~Accum();
};

template <class T>
Accum<T>::~Accum()
{
}


template <>
class Accum<Person>
{
private:
	int total;
public:
	Accum(int start) : total(start){}
	int operator+=(Person& t){ return total = total + t.GetNum(); }
	int GetTotal(){ return total; }
};
