#pragma once
#include <string>

class Resource
{
private:
	std::string name;
public:
	Resource(std::string n);
	~Resource();
	virtual std::string GetName() const { return name; }
};

