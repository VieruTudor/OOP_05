#include "Repo.hpp"

Repository::Repository()
{
	statuesList = DynamicArray<GuardianStatue>();
}

void Repository::addGuardianStatue(GuardianStatue& guardianStatue)
{
	if (this->searchGuardianStatue(guardianStatue) != -1)
		throw exception();
	this->statuesList.add(guardianStatue);
}

void Repository::deleteGuardianStatue(const string& powerWord)
{
	GuardianStatue dummyStatue = GuardianStatue(powerWord, "", 0, "");
	int searchIndex = this->searchGuardianStatue(dummyStatue);
	if (searchIndex == -1)
		throw exception();
	else
		this->statuesList.deleteFromPosition(searchIndex);
}

void Repository::updateGuardianStatue(GuardianStatue& oldGuardianStatue, GuardianStatue& newGuardianStatue)
{
	if (this->searchGuardianStatue(oldGuardianStatue) == -1)
		throw exception();
	for (int i = 0; i < this->statuesList.getSize(); i++)
		if (this->statuesList[i] == oldGuardianStatue)
			this->statuesList[i] = newGuardianStatue;
}

DynamicArray<GuardianStatue> Repository::getAllStatues()
{
	return this->statuesList;
}

int Repository::searchGuardianStatue(GuardianStatue& guardianStatue)
{
	for (int index = 0; index < this->statuesList.getSize(); index++)
		if (this->statuesList[index] == guardianStatue)
			return index;
	return -1;

}
