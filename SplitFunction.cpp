#include "SplitFunction.hpp"

vector<string> split(string& stringToBeSplit, char delimiter)
{
	vector<string> result;
	stringstream ss(stringToBeSplit);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}