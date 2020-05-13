#pragma once

#include <string>
#include <sstream>
#include <vector>
#include "SplitFunction.hpp"
using namespace std;

class GuardianStatue
{
private:
	string powerWord;
	string material;
	int age;
	string corporealForm;
public:
	GuardianStatue();
	GuardianStatue(const string& powerWord, const string& material, const int age, const string& corporealForm);
	string getPowerWord() const { return powerWord; }
	string getMaterial() const { return material; }
	int getAge() const { return age; }
	string getCorporealForm() const { return corporealForm; }
	
	bool operator==(const GuardianStatue& other);
	friend istream& operator>>(istream& is, GuardianStatue& statue);
	friend ostream& operator<<(ostream& os, GuardianStatue& statue);



	string toString();
};

