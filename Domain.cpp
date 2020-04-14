#include "Domain.hpp"

GuardianStatue::GuardianStatue()
{
	powerWord = "";
	material = "";
	age = 0;
	corporealForm = "";

}

GuardianStatue::GuardianStatue(const string& powerWord, const string& material, const int age, const string& corporealForm)
{
	this->powerWord = powerWord;
	this->material = material;
	this->age = age;
	this->corporealForm = corporealForm;
}

bool GuardianStatue::operator==(const GuardianStatue& other)
{
	return this->powerWord == other.powerWord;
}

string GuardianStatue::toString()
{
	
	string printString = powerWord + ", " + material + ", " + to_string(age) + ", " + corporealForm;
	return printString;
}

