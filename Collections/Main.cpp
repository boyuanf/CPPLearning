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

void DiffSmartAndRawPointer()
{
	/*going to cause an error because two shared_ptrs from
	different groups share a single raw resource.
	If we use make_shared then can avoid this.
	*/
	//shared_ptr<int> p = make_shared<int>(100);  //declare only 1 int
	//shared_ptr<int> p(new int);  //declare only 1 int
	int* p = new int;
	shared_ptr<int> sptr1(p);
	shared_ptr<int> sptr2(p);
}

void StringLenthAndChar2wChar()
{
	unique_ptr<char[]> myBuffer(new char[1024]);
	cout << strlen(&myBuffer[0]);
	//memset(&myBuffer[0], 0, 1024);
	string s = "Message from thread queue by POST!";  //Write constant string for
	//memcpy(myBuffer, s.c_str(), s.length());
	//strcpy(&myBuffer[0], s.c_str());
	memcpy_s(&myBuffer[0], 1024, s.c_str(), s.length() + 1);
	cout << strlen(&myBuffer[0]);
	cout << &myBuffer[0] << endl;

	char str[3];
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	int len = strlen(str);
	size_t convertedLength = 0;
	size_t newsize = 3;
	wchar_t * wcstring = new wchar_t[newsize];
	mbstowcs_s(&convertedLength, wcstring, newsize, str, _TRUNCATE);
	wcout << wcstring << endl;
	return;
}

enum TRX_TYPE{
	PT_A_Live = 0,
	PT_A_Test
};

struct Server_Info
{
	string serverName;
	string userName;
	string pwd;
};



bool AddServertoList(vector<Server_Info> *trxServerList, TRX_TYPE trx_type, string configFileStr, map<int, string> trxNameMap)
{
	auto serverNum = 0;
	string tmpConfigStr;
	Server_Info tmpSerInfo;
	smatch sernum_match;
	string regexExp;

	regexExp = trxNameMap[trx_type] + ",\\nServerNum,(\\d+),*\\n*";   //create the search string according to trx type

	regex testSearch(regexExp, regex_constants::ECMAScript | regex_constants::icase);
	if (regex_search(configFileStr, sernum_match, testSearch)) {
		cout << "ServerNumber:" << sernum_match[1] << endl;
		tmpConfigStr = sernum_match.suffix();
		serverNum = stoi(sernum_match[1]);
	}
	regex searchDetail("(.*ServerName,)([0-9A-Za-z]{1,50})(,*\\n+UserName,)([0-9A-Za-z]{1,50})(,*\\n+Password,)([0-9A-Za-z]{1,50})(,*\\n+)");  //work line ends with or without ','
	for (auto i = 0; i < serverNum; i++)
	{
		if (regex_search(tmpConfigStr, sernum_match, searchDetail)) {
			cout << "ServerName:" << sernum_match[2] << endl;
			cout << "UserName:" << sernum_match[4] << endl;
			cout << "Password:" << sernum_match[6] << endl;
			tmpSerInfo.serverName = sernum_match[2];
			tmpSerInfo.userName = sernum_match[4];
			tmpSerInfo.pwd = sernum_match[6];
			trxServerList[trx_type].push_back(tmpSerInfo);
			tmpConfigStr = sernum_match.suffix();
		}
	}
	return true;
}

void ReadConfigFile()
{
	//Read Config File
	ifstream in("StlinkConfig.csv");
	stringstream strStream;
	strStream << in.rdbuf();
	string configFileStr(strStream.str());
	string tmpConfigStr;
	/*char p[5000];
	strcpy(p, configFileStr.c_str());*/
	auto serverNum = 0;
	vector<Server_Info> trxServerList[2];  // Server List for all trx
	map<int, string> trxNameMap;

	trxNameMap.emplace(PT_A_Live, "PtAuth_Live");
	trxNameMap.emplace(PT_A_Test, "PtAuth_Test");

	AddServertoList(trxServerList, PT_A_Live, configFileStr, trxNameMap);   //later trxServerList, configFileStr, trxNameMap may be declared as class members, no need to pass as parameter
	AddServertoList(trxServerList, PT_A_Test, configFileStr, trxNameMap);

	//------------------bellow are the trial code we used to create regex string-------------------//

	smatch sernum_match;
	// + means one or more, * means 0 or more
	regex testSearch("PtAuth_Live,\\nServerNum,(\\d+),*\\n*", regex_constants::ECMAScript | regex_constants::icase);
	//regex testSearch("PtAuth_Live,\nServerNum,(.*),\n", std::regex_constants::ECMAScript | std::regex_constants::icase);
	//regex testSearch("PtAuth_Live,\nServerNum,([0-9]{1}),\n", std::regex_constants::ECMAScript | std::regex_constants::icase);
	if (regex_search(configFileStr, sernum_match, testSearch)) {
		cout << "ServerNumber:" << sernum_match[1] << endl;
		/*for(size_t i = 0; i < sernum_match.size(); ++i)
		std::cout << i << ": " << sernum_match[i] << '\n';
		cout << sernum_match.str() << endl;
		cout<<endl << sernum_match.suffix() << endl;*/
		tmpConfigStr = sernum_match.suffix();
		serverNum = stoi(sernum_match[1]);
	}

	/*regex testSearch2("(.*ServerName,)(.*)(,\\n*)(.*UserName,)(.*)(,\\n*)(.*Password,)(.*)(,\\n*)");
	if (std::regex_search(tmpConfigStr, sernum_match, testSearch2)) {
	cout << "ServerName:" << sernum_match[2] << endl;
	cout << "UserName:" << sernum_match[4] << endl;
	cout << "Password:" << sernum_match[8] << endl;
	std::cout << "Suffix: '" << sernum_match.suffix() << "\'\n\n";
	}*/

	regex searchDetail("(.*ServerName,)([0-9A-Za-z]{1,50})(,*\\n+UserName,)([0-9A-Za-z]{1,50})(,*\\n+Password,)([0-9A-Za-z]{1,50})(,*\\n+)");  //work line ends with or without ','
	//regex searchDetail("(.*ServerName,)(.*)(,*\\n+UserName,)(.*)(,*\\n+Password,)(.*)(,*\\n+)");  //don't allow end line with ','
	//regex searchDetail("(.*ServerName,)(.*)(,\\n*)(.*UserName,)(.*)(,\\n*)(.*Password,)(.*)(,\\n*)");  //need to end line with ','
	for (auto i = 0; i < serverNum; i++)
	{
		if (regex_search(tmpConfigStr, sernum_match, searchDetail)) {
			/*for (size_t k = 0; k < sernum_match.size(); ++k)
			std::cout << k << ": " << sernum_match[k]<<endl;*/
			cout << "ServerName:" << sernum_match[2] << endl;
			cout << "UserName:" << sernum_match[4] << endl;
			cout << "Password:" << sernum_match[6] << endl;
			tmpConfigStr = sernum_match.suffix();
		}
	}


	//string configFileStr = "";
	//fstream out;
	//char linebuffer[1024];  // max line
	//out.open("", ios::in);
	//while (!out.eof())
	//{
	//	out.getline(linebuffer, sizeof(linebuffer)-1, '\n');

	//}
	//out.close();
}

int _tmain(int argc, _TCHAR* argv[])
{

	//ReadConfigFile();
	//TestTryCatch();
	//Casting();
	//Polymorphism();
	//DiffSmartAndRawPointer();
	//SmartPointer();
	//PointerReference();
	//classtemplate();
	//learnfunctiontemplate();
	//ImmediateIf();
	//LearnInheritanceandEnum();
	//learnCollections();
	return 0;
}
