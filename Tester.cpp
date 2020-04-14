#include "Tester.hpp"
#include <assert.h>
#include <iostream>
using namespace std;

void RepoTester::testAll()
{
	testRepo = Repository();
	addGuardianStatue_validObject_addedToList();
	addGuardianStatue_duplicateObject_exception();
	deleteGuardianStatue_existingObject_deleted();
	deleteGuardianStatue_inexistingObject_exception();
	updateGuardianStatue_existingObject_updated();
	updateGuardianStatue_inexistingObject_exception();
}


void RepoTester::addGuardianStatue_validObject_addedToList()
{
	GuardianStatue testStatue = GuardianStatue("Piertotum Locomotor", "Stone", 300, "Warrior");
	testRepo.addGuardianStatue(testStatue);
	assert(testRepo.searchGuardianStatue(testStatue) != -1);
}

void RepoTester::addGuardianStatue_duplicateObject_exception()
{
	GuardianStatue duplicateStatue = GuardianStatue("Piertotum Locomotor", "Cyanite", 150, "Mage");
	try
	{
		testRepo.addGuardianStatue(duplicateStatue);
		assert(false);
	}
	catch (exception&)
	{
		assert(true);
	}
		
}

void RepoTester::updateGuardianStatue_existingObject_updated()
{
	GuardianStatue oldGuardianStatue = GuardianStatue("Piertotum Locomotor", "", 0, ""); /// added previously in the repo
	GuardianStatue newGuardianStatue = GuardianStatue("Piertotum Locomotor", "Cyanite", 400, "Knight");
	testRepo.updateGuardianStatue(oldGuardianStatue, newGuardianStatue);
	int index = testRepo.searchGuardianStatue(oldGuardianStatue);
 	assert(testRepo.getAllStatues()[index].getMaterial() == "Cyanite");	
}

void RepoTester::updateGuardianStatue_inexistingObject_exception()
{
	GuardianStatue oldGuardianStatue = GuardianStatue("Theranos aborior", "Stone", 100, "Mage");
	GuardianStatue newGuardianStatue = GuardianStatue("Theranos aborior", "Water", 150, "Trickster");
	try
	{
		testRepo.updateGuardianStatue(oldGuardianStatue, newGuardianStatue);
		assert(false);
	}
	catch (exception&)
	{
		assert(true);
	}
}

void RepoTester::deleteGuardianStatue_existingObject_deleted()
{
	GuardianStatue deletedStatue = GuardianStatue("Piertotum Locomotors", "a", 0, "a");
	testRepo.addGuardianStatue(deletedStatue);
	try
	{
		testRepo.deleteGuardianStatue(deletedStatue.getPowerWord());
		assert(true);
	}
	catch (exception&)
	{
		assert(false);
	}
	
}

void RepoTester::deleteGuardianStatue_inexistingObject_exception()
{
	GuardianStatue deletedStatue = GuardianStatue("Magnum valor", "", 0, "");
	try
	{
		testRepo.deleteGuardianStatue(deletedStatue.getPowerWord());
		assert(false);
	}
	catch (exception&)
	{
		assert(true);
	}
}



void ControllerTester::testAll()
{
	controllerTestRepo = Repository();
	testController = Controller(controllerTestRepo);
	testArray = testController.getAllStatues();

	//addGuardianStatue_duplicateObject_exception();
	addGuardianStatue_validInput_addedToList();
	deleteGuardianStatue_inexistingObject_exception();
	//deleteGuardianStatue_existingObject_deleted();
	updateGuardianStatue_inexistingObject_exception();
	updateGuardianStatue_existingObject_updated();
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
		testController.addGuardianStatue(powerWord, material, age, corporealForm);
		assert(false);
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
		testController.deleteGuardianStatue(powerWord);
		assert(true);
	}
	catch (exception&)
	{
		assert(false);
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
