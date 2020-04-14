#pragma once

#include <string>
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
	string toString();
};

