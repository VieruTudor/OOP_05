#pragma once

#include "Controller.hpp"
#include <string>

using namespace std;

class UserInterface 
{
private:
	Controller controller;

	
public:
	/*
	User interface constructor that initialises the controller with the given parameter object.
	*/
	UserInterface(Controller& controller);

	/*
	Gets the list of parameters from the user, splits them and validates them before sending them to the controller, for the adding function.
	*/
	void addGuardianStatueUI(char* parameters);
	
	/*
	Gets the parameter from the user, validates it and sends it to controller for the delete function.
	*/
	void deleteGuardianStatueUI(char* parameters);

	/*
	Gets the list of parameters from the user, splits and validates them before sending them to the controller for the update function.
	*/
	void updateGuardianStatueUI(char* parameters);

	/*
	Gets the list of objects from the repo (through service), and prints all the objects in the repository
	*/
	void listGuardianStatuesUI();

	/*
	Gets a list of the filtered items from service, based on given parameters(material, age)
	*/
	void listGuardianStatuesWithParametersUI(char* parameters);

	/*
	Gets the next guardian statue from the list
	*/
	void getNextGuardianStatueUI();

	/*
	Saves a guardian statue in myList from service based on a given powerword.
	*/
	void saveGuardianStatue(char* parameters);

	/*
	Lists the saved guardian statues
	*/
	void listMyList();

	/*
	Runs the application
	*/
	void run();
};