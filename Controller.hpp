#pragma once
#include "Repo.hpp"
#include "FileRepository.hpp"
class Controller
{
private:
	FileRepository repo;
	int currentStatueIndex;
	vector<GuardianStatue> myList;
public:
	/*
	Default constructor of the controller class
	*/
	Controller();
	/*
	Constructor for the controller class, initialised with a repository object as parameter
	*/
	Controller(FileRepository& repository);

	/*
	Based on the parameters from the UI, creates a Guardian Statue and sends it to repo for further adding.
	*/
	void addGuardianStatue(string& powerWord, string& material, int age, string& corporealForm);

	/*
	Gets as parameter from UI a power word and sends it to the repo for the deleting function
	*/
	void deleteGuardianStatue(string& powerWord);

	/*
	Gets as parameters a power word and new attributes(material, age, corporeal form) for the object having that power word.
	Creates objects and sends them to repo for the update function
	*/
	void updateGuardianStatue(string& powerWord, string& newMaterial, int newAge, string& newCorporealForm);

	/*
	Gets a copy of the statues list from the repo
	*/
	vector<GuardianStatue> getAllStatues();

	/*
	Returns a list of statues, filtered by material and having age less than a given input
	*/
	vector<GuardianStatue> getFilteredStatues(string& material, int age);

	/*
	Gets the next guardian statue in the list.
	*/
	GuardianStatue getNextGuardianStatue();

	/*
	Saves a guardian statue in myList based on a given power word.
	*/
	void saveGuardianStatue(string& powerWord);

	/*
	Gets the list of saved guardian statues.
	*/
	vector<GuardianStatue> getMyList();

	void setFileName(string fileName);

	string getFileName();


	void clearFile();
};