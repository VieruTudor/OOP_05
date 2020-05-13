#include "Controller.hpp"

Controller::Controller()
{
}

Controller::Controller(FileRepository& repository)
{
	this->repo = repository;
	currentStatueIndex = 0;
}

void Controller::addGuardianStatue(string& powerWord, string& material, int age, string& corporealForm)
{
	GuardianStatue guardianStatueToAdd = GuardianStatue(powerWord, material, age, corporealForm);
	try
	{
		this->repo.addGuardianStatue(guardianStatueToAdd);
	}
	catch (exception&)
	{
		throw exception();
	}
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

vector<GuardianStatue> Controller::getAllStatues()
{
	return this->repo.getStatues();
}

vector<GuardianStatue> Controller::getFilteredStatues(string& material, int age)
{
	vector<GuardianStatue> statuesList = this->repo.getStatues();
	vector<GuardianStatue> filteredStatuesList;
	for (auto statue : statuesList)
		if (statue.getMaterial() == material && statue.getAge() < age)
			filteredStatuesList.push_back(statue);
	return filteredStatuesList;
}
GuardianStatue Controller::getNextGuardianStatue()
{
	GuardianStatue guardianStatueToReturn = this->repo.getStatues()[currentStatueIndex];
	this->currentStatueIndex++;
	if (currentStatueIndex == this->repo.getSize())
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
		string savedMaterial = this->repo.getStatues()[index].getMaterial();
		string savedCorporealForm = this->repo.getStatues()[index].getCorporealForm();
		int savedAge = this->repo.getStatues()[index].getAge();
		GuardianStatue savedStatue = GuardianStatue(savedPowerWord, savedMaterial, savedAge, savedCorporealForm);
		myList.push_back(savedStatue);
	}
}

vector<GuardianStatue> Controller::getMyList()
{
	return this->myList;
}

void Controller::setFileName(string fileName)
{
	this->repo.setFileName(fileName);
}

string Controller::getFileName()
{
	return this->repo.getFileName();
}

void Controller::clearFile()
{
	this->repo.clearFile();
}



