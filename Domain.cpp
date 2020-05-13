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


istream& operator>>(istream& is, GuardianStatue& statue)
{
	// TODO: insert return statement here
	string line; 
	getline(is, line);

	vector<string> tokens = split(line, ',');
	if (tokens.size() != 4)
		return is;
	string powerWord = tokens[0];
	string material = tokens[1];
	int age = stoi(tokens[2]);
	string corporealForm = tokens[3];
	
	statue = GuardianStatue(powerWord, material, age, corporealForm);
	return is;
	
}

ostream& operator<<(ostream& os, GuardianStatue& statue)
{
	// TODO: insert return statement here
	string printString;
	printString = statue.getPowerWord() + "," + statue.getMaterial() + "," + to_string(statue.getAge()) + "," + statue.getCorporealForm();
	os << printString;
	return os;
}
