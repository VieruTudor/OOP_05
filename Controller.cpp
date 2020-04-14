#include "Controller.hpp"

Controller::Controller()
{
}

Controller::Controller(Repository& repository)
{
	this->repo = repository;
	currentStatueIndex = 0;
}

void Controller::addGuardianStatue(string& powerWord, string& material, int age, string& corporealForm)
{
	GuardianStatue guardianStatueToAdd = GuardianStatue(powerWord, material, age, corporealForm);
	this->repo.addGuardianStatue(guardianStatueToAdd);
}

void Controller::deleteGuardianStatue(string& powerWord)
{
	this->repo.deleteGuardianStatue(powerWord);
}

void Controller::updateGuardianStatue(string& powerWord, string& newMaterial, int newAge, string& newCorporealForm)
{
	GuardianStatue oldGuardianStatue = GuardianStatue(powerWord, "", 0, "");
	GuardianStatue newGuardianStatue = GuardianStatue(powerWord, newMaterial, newAge, newCorporealForm);
	this->repo.updateGuardianStatue(oldGuardianStatue, newGuardianStatue);
}

DynamicArray<GuardianStatue> Controller::getAllStatues()
{
	return this->repo.getAllStatues();
}

DynamicArray<GuardianStatue> Controller::getFilteredStatues(string& material, int age)
{
	DynamicArray<GuardianStatue> statuesList = this->repo.getAllStatues();
	DynamicArray<GuardianStatue> filteredStatuesList;
	for (int i = 0; i < statuesList.getSize(); i++)
		if (statuesList[i].getMaterial() == material && statuesList[i].getAge() < age)
			filteredStatuesList.add(statuesList[i]);
	return filteredStatuesList;
}
GuardianStatue Controller::getNextGuardianStatue()
{
	GuardianStatue guardianStatueToReturn = this->repo.getAllStatues()[currentStatueIndex];
	this->currentStatueIndex++;
	if (currentStatueIndex == this->repo.getAllStatues().getSize())
		currentStatueIndex = 0;
	return guardianStatueToReturn;
}

void Controller::saveGuardianStatue(string& powerWord)
{
	GuardianStatue guardianStatueToSave = GuardianStatue(powerWord, "", 0, "");
	int index = this->repo.searchGuardianStatue(guardianStatueToSave);
	if (index != -1)
	{
		string savedPowerWord = powerWord;
		string savedMaterial = this->repo.getAllStatues()[index].getMaterial();
		string savedCorporealForm = this->repo.getAllStatues()[index].getCorporealForm();
		int savedAge = this->repo.getAllStatues()[index].getAge();
		GuardianStatue savedStatue = GuardianStatue(savedPowerWord, savedMaterial, savedAge, savedCorporealForm);
		myList.add(savedStatue);
	}
}

DynamicArray<GuardianStatue> Controller::getMyList()
{
	return this->myList;
}




