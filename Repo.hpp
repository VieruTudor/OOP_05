#pragma once
#include "Domain.hpp"
#include "DynamicArray.hpp"
#include <vector>
#include <algorithm>
class Repository
{
private:
	vector<GuardianStatue> statuesList;

public:
	/*
	Repository constructor
	*/
	Repository();

	/*
	Receives a GuardianStatue object as parameter and adds it to the statues list, throws exception if it is a duplicate
	*/
	void addGuardianStatue(GuardianStatue& guardianStatue);
	
	/*
	Deletes a GuardianStatue object with the given power word, throws exception if it is not in the list
	*/
	void deleteGuardianStatue(const string& powerWord);
	
	/*
	Updates a given old object with a new one, based on a common power word
	*/
	void updateGuardianStatue(GuardianStatue& oldGuardianStatue, GuardianStatue& newGuardianStatue);
	
	/*
	Returns a copy of a list of statues in the repo 
	*/
	vector<GuardianStatue> getAllStatues();

	/*
	Searches for a certain GuardianStatue object in the repo list
	Returns an index representing the position of the object in the list.
	*/
	int searchGuardianStatue(GuardianStatue& guardianStatue);

	int getSize();
};