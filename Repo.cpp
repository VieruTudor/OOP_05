#include "Repo.hpp"

Repository::Repository()
{
	
}
/*
TODO: IMPLEMENT FUNCTIONS FOR STL VECTOR (?) ---
	  IMPLEMENT FUNCTIONS FOR FILES ^ ---
	  I/O OPERATORS
*/
void Repository::addGuardianStatue(GuardianStatue& guardianStatue)
{
	int statueIndex = this->searchGuardianStatue(guardianStatue);
	if (statueIndex != -1)
		throw exception();
	this->statuesList.push_back(guardianStatue);
}

void Repository::deleteGuardianStatue(const string& powerWord)
{
	GuardianStatue dummyStatue = GuardianStatue(powerWord, "", 0, "");
	int statueIndex = this->searchGuardianStatue(dummyStatue);
	if (statueIndex == -1)
		throw exception();
	this->statuesList.erase(this->statuesList.begin() + statueIndex);
}

void Repository::updateGuardianStatue(GuardianStatue& oldGuardianStatue, GuardianStatue& newGuardianStatue)
{
	int updateIndex = this->searchGuardianStatue(oldGuardianStatue);
	if (updateIndex == -1)
		throw exception();
	this->statuesList[updateIndex] = newGuardianStatue;
}

vector<GuardianStatue> Repository::getAllStatues()
{
	return this->statuesList;
}

int Repository::searchGuardianStatue(GuardianStatue& guardianStatue)
{
	int index = 0;
	for (auto statue : this->statuesList)
	{
		if (statue.getPowerWord() == guardianStatue.getPowerWord())
			return index;
		index++;
	}
	return -1;
}

int Repository::getSize()
{
	return this->statuesList.size();
}
