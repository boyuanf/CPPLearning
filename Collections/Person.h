#include <string>
#include "Resource.h"
#include <memory>
#ifndef _Person_H
#define _Person_H
class Person
{
protected:
	std::string firstname;
	std::string lastname;
	int arbitrarynumber;
	//Resource* pResource;
	std::shared_ptr<Resource> pResource;

public:

	Person(std::string first,
		std::string last,
		int arbitrary);
	Person();
	/*Person(const Person &p);*/
	~Person();
	std::string GetName() {return firstname + " " + lastname;}
	void SetNum(int arbitrary) { arbitrarynumber = arbitrary; }
	int GetNum() {return arbitrarynumber;}
	bool operator<(Person& p);
 	bool operator<(int i);
	friend bool operator<(int i, Person& p);
	void AddResource();
	void SetFirstName(std::string fName);
	std::string GetResourceName() const{ return pResource->GetName();}
	/*Person& operator=(const Person&p);*/
};
bool operator<(int i, Person& p);

#endif