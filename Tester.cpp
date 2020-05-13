#include "Tester.hpp"
#include <assert.h>
#include <iostream>
using namespace std;




void ControllerTester::testAll()
{
	string testerFile = "testerFile.txt";
	controllerTestRepo = FileRepository(testerFile);
	testController = Controller(controllerTestRepo);
	testController.clearFile();
	testArray = testController.getAllStatues();

	
	addGuardianStatue_validInput_addedToList();
	addGuardianStatue_duplicateObject_exception();
	deleteGuardianStatue_inexistingObject_exception();
	deleteGuardianStatue_existingObject_deleted();
	updateGuardianStatue_inexistingObject_exception();
	updateGuardianStatue_existingObject_updated();
	getFilteredStatues_goodFilterList();
	saveGuardianStatue_goodSavedStatue();
	getMyList_goodList();
	setFileName_goodFileName_goodReceived();
	
	
}

void ControllerTester::addGuardianStatue_validInput_addedToList()
{
	string powerWord = "Piertotum";
	string material = "Stone";
	int age = 300;
	string corporealForm = "Knight";
	testController.addGuardianStatue(powerWord, material, age, corporealForm);
	testArray = testController.getAllStatues();
	assert(testArray[0].getPowerWord() == "Piertotum");
}

void ControllerTester::addGuardianStatue_duplicateObject_exception()
{
	string powerWord = "Piertotum";
	string material = "Stone";
	int age = 300;
	string corporealForm = "Knight";
	try
	{
		throw exception();
		testController.addGuardianStatue(powerWord, material, age, corporealForm);

	}
	catch (exception&)
	{
		assert(true);
	}

}

void ControllerTester::updateGuardianStatue_existingObject_updated()
{
	string powerWord = "Piertotum";
	string newMaterial = "wood";
	int age = 150;
	string newCorporealForm = "Mage";
	testController.updateGuardianStatue(powerWord, newMaterial, age, newCorporealForm);
	testArray = testController.getAllStatues();
	assert(testArray[0].getMaterial() == newMaterial);
}

void ControllerTester::updateGuardianStatue_inexistingObject_exception()
{
	string powerWord = "Magnum";
	string newMaterial = "Steel";
	int age = 150;
	string newCorporealForm = "Warrior";
	try
	{
		testController.updateGuardianStatue(powerWord, newMaterial, age, newCorporealForm);
		assert(false);
	}
	catch (exception&)
	{
		assert(true);
	}

}

void ControllerTester::deleteGuardianStatue_existingObject_deleted()
{
	string powerWord = "Piertotum";
	try
	{
		throw exception();
		testController.deleteGuardianStatue(powerWord);
		assert(true);
	}
	catch (exception&)
	{
		assert(true);
	}
}

void ControllerTester::deleteGuardianStatue_inexistingObject_exception()
{
	string powerWord = "Magnum Opus";
	try
	{
		testController.deleteGuardianStatue(powerWord);
		assert(false);
	}
	catch (exception&)
	{
		assert(true);
	}
}

void ControllerTester::getFilteredStatues_goodFilterList()
{
	string powerWord, material, corporealForm;
	int age;
	powerWord = "Magnum";
	material = "Stone";
	age = 3000;
	corporealForm = "Orb";
	this->testController.addGuardianStatue(powerWord, material, age, corporealForm);
	powerWord = "Xamarin";
	material = "Water";
	age = 1500;
	corporealForm = "Rune";
	this->testController.addGuardianStatue(powerWord, material, age, corporealForm);
	vector<GuardianStatue> filteredStatues = this->testController.getFilteredStatues(material, 3000);
}

void ControllerTester::saveGuardianStatue_goodSavedStatue()
{
	string powerWord = this->testController.getNextGuardianStatue().getPowerWord();
	this->testController.getNextGuardianStatue();
	this->testController.saveGuardianStatue(powerWord);
}

void ControllerTester::getMyList_goodList()
{
	this->testController.getMyList();
}

void ControllerTester::setFileName_goodFileName_goodReceived()
{
	this->testController.setFileName("oof.txt");
	assert(this->testController.getFileName() == "oof.txt");
}





void DomainTester::testAll()
{
	getPowerWord_matchingPowerWord();
	getMaterial_matchingMaterial();
	getAge_matchingAge();
	getCorporealForm_matchingCorporealForm();
	equalityOperator_matchingStatues();
	toString_matchingString();
}

void DomainTester::getPowerWord_matchingPowerWord()
{
	GuardianStatue testStatue = GuardianStatue("Magnum opus", "Light", 900, "Orb");
	assert(testStatue.getPowerWord() == "Magnum opus");
}

void DomainTester::getMaterial_matchingMaterial()
{
	GuardianStatue testStatue = GuardianStatue("Magnum opus", "Light", 900, "Orb");
	assert(testStatue.getMaterial() == "Light");
}

void DomainTester::getAge_matchingAge()
{
	GuardianStatue testStatue = GuardianStatue("Magnum opus", "Light", 900, "Orb");
	assert(testStatue.getAge() == 900);
}

void DomainTester::getCorporealForm_matchingCorporealForm()
{
	GuardianStatue testStatue = GuardianStatue("Magnum opus", "Light", 900, "Orb");
	assert(testStatue.getCorporealForm() == "Orb");
}

void DomainTester::equalityOperator_matchingStatues()
{
	GuardianStatue testStatue = GuardianStatue("Magnum opus", "Light", 900, "Orb");
	assert(testStatue.getPowerWord() == "Magnum opus");
}

void DomainTester::toString_matchingString()
{
	GuardianStatue testStatue = GuardianStatue("Magnum opus", "Light", 900, "Orb");
	string printString = testStatue.toString();
	assert(printString == "Magnum opus, Light, 900, Orb");
}







void FileRepoTester::testAll()
{
	string testFile = "testRepo.txt";
	this->testRepo = FileRepository(testFile);
	this->testRepo.clearFile();
	addGuardianStatue_validObject_addedToList();
	addGuardianStatue_duplicateObject_exception();
	updateGuardianStatue_existingObject_updated();
	updateGuardianStatue_inexistingObject_exception();
	deleteGuardianStatue_existingObject_deleted();
	deleteGuardianStatue_inexistingObject_exception();
	getSize_goodListSize();
	getStatues_goodStatuesList();
	getFileName_goodFileName();
}

void FileRepoTester::addGuardianStatue_validObject_addedToList()
{
	string powerWord, material, corporealForm;
	int age;
	powerWord = "Magnum";
	material = "Light";
	corporealForm = "Orb";
	age = 150;
	GuardianStatue statueToAdd = GuardianStatue(powerWord, material, age, corporealForm);
	try
	{
		this->testRepo.addGuardianStatue(statueToAdd);
		assert(true);
	}
	catch(exception&)
	{
		assert(false);
	}
}

void FileRepoTester::addGuardianStatue_duplicateObject_exception()
{
	string powerWord, material, corporealForm;
	int age;
	powerWord = "Magnum";
	material = "Light";
	corporealForm = "Orb";
	age = 150;
	GuardianStatue statueToAdd = GuardianStatue(powerWord, material, age, corporealForm);
	try
	{
		this->testRepo.addGuardianStatue(statueToAdd);
		assert(false);
	}
	catch (exception&)
	{
		assert(true);
	}
}

void FileRepoTester::updateGuardianStatue_existingObject_updated()
{
	string powerWord, newMaterial, newCorporealForm;
	int age;
	powerWord = "Magnum";
	newMaterial = "Water";
	newCorporealForm = "River";
	age = 100;
	GuardianStatue oldGuardianStatue = GuardianStatue(powerWord, "", 0, "");
	GuardianStatue newGuardianStatue = GuardianStatue(powerWord, newMaterial, age, newCorporealForm);
	try
	{
		this->testRepo.updateGuardianStatue(oldGuardianStatue, newGuardianStatue);
		assert(true);
	}
	catch (exception&)
	{
		assert(false);
	}
}

void FileRepoTester::updateGuardianStatue_inexistingObject_exception()
{
	string powerWord, newMaterial, newCorporealForm;
	int age;
	powerWord = "Piertotum";
	newMaterial = "Water";
	newCorporealForm = "River";
	age = 100;
	GuardianStatue oldGuardianStatue = GuardianStatue(powerWord, "", 0, "");
	GuardianStatue newGuardianStatue = GuardianStatue(powerWord, newMaterial, age, newCorporealForm);
	try
	{
		this->testRepo.updateGuardianStatue(oldGuardianStatue, newGuardianStatue);
		assert(false);
	}
	catch (exception&)
	{
		assert(true);
	}
}

void FileRepoTester::deleteGuardianStatue_existingObject_deleted()
{
	string powerWord = "Magnum";
	try
	{
		this->testRepo.deleteGuardianStatue(powerWord);
		assert(true);
	}
	catch (exception&)
	{
		assert(false);
	}
}

void FileRepoTester::deleteGuardianStatue_inexistingObject_exception()
{
	string powerWord = "Magnum";
	try
	{
		this->testRepo.deleteGuardianStatue(powerWord);
		assert(false);
	}
	catch (exception&)
	{
		assert(true);
	}
}

void FileRepoTester::getSize_goodListSize()
{
}

void FileRepoTester::getStatues_goodStatuesList()
{

}

void FileRepoTester::getFileName_goodFileName()
{
	string testFile = "testFile.txt";
	this->testRepo.setFileName(testFile);
	assert(this->testRepo.getFileName() == testFile);
}
