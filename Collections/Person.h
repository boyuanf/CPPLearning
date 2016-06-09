#include <string>
#ifndef _Person_H
#define _Person_H
class Person
{
protected:
	std::string firstname;
	std::string lastname;
	int arbitrarynumber;

public:

	Person(std::string first,
		std::string last,
		int arbitrary);
	Person();
	~Person();
	std::string GetName() {return firstname + " " + lastname;}
	void SetNum(int arbitrary) { arbitrarynumber = arbitrary; };
	int GetNum() {return arbitrarynumber;}
	bool operator<(Person& p);
 	bool operator<(int i);
	friend bool operator<(int i, Person& p);
};
bool operator<(int i, Person& p);

#endif