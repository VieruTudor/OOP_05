#include "Repo.hpp"
#include "Controller.hpp"
#include "Domain.hpp"

class FileRepoTester
{
private:
	FileRepository testRepo;
public:
	void testAll();
	void addGuardianStatue_validObject_addedToList();
	void addGuardianStatue_duplicateObject_exception();
	void updateGuardianStatue_existingObject_updated();
	void updateGuardianStatue_inexistingObject_exception();
	void deleteGuardianStatue_existingObject_deleted();
	void deleteGuardianStatue_inexistingObject_exception();
	void getSize_goodListSize();
	void getStatues_goodStatuesList();
	void getFileName_goodFileName();
};

class ControllerTester
{
private:
	FileRepository controllerTestRepo;
	Controller testController;
	vector<GuardianStatue> testArray;

public:
	void testAll();
	void addGuardianStatue_validInput_addedToList();
	void addGuardianStatue_duplicateObject_exception();
	void updateGuardianStatue_existingObject_updated();
	void updateGuardianStatue_inexistingObject_exception();
	void deleteGuardianStatue_existingObject_deleted();
	void deleteGuardianStatue_inexistingObject_exception();
	void getFilteredStatues_goodFilterList();
	void saveGuardianStatue_goodSavedStatue();
	void getMyList_goodList();
	void setFileName_goodFileName_goodReceived();
	

};

class DomainTester
{
public:
	void testAll();
	void getPowerWord_matchingPowerWord();
	void getMaterial_matchingMaterial();
	void getAge_matchingAge();
	void getCorporealForm_matchingCorporealForm();
	void equalityOperator_matchingStatues();
	void toString_matchingString();
};