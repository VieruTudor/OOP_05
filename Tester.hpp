#include "Repo.hpp"
#include "Controller.hpp"
#include "Domain.hpp"

class RepoTester
{
private:
	Repository testRepo;
public:
	void testAll();
	void addGuardianStatue_validObject_addedToList();
	void addGuardianStatue_duplicateObject_exception();
	void updateGuardianStatue_existingObject_updated();
	void updateGuardianStatue_inexistingObject_exception();
	void deleteGuardianStatue_existingObject_deleted();
	void deleteGuardianStatue_inexistingObject_exception();

};

class ControllerTester
{
private:
	Repository controllerTestRepo;
	Controller testController;
	DynamicArray<GuardianStatue> testArray;

public:
	void testAll();
	void addGuardianStatue_validInput_addedToList();
	void addGuardianStatue_duplicateObject_exception();
	void updateGuardianStatue_existingObject_updated();
	void updateGuardianStatue_inexistingObject_exception();
	void deleteGuardianStatue_existingObject_deleted();
	void deleteGuardianStatue_inexistingObject_exception();

};