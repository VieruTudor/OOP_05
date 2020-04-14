#define _CRT_SECURE_NO_WARNINGS
#include "UI.hpp"
#include <iostream>
#include <cstring>


using namespace std;


UserInterface::UserInterface(Controller& controller)
{
	this->controller = controller;
}

void UserInterface::addGuardianStatueUI(char* parameters)
{
	string powerWord, material, corporealForm;
	int age;

	parameters = strtok(NULL, ",");
	powerWord = parameters;
	if (powerWord == " ")
	{
		cout << "NO\n";
		return;
	}

	parameters = strtok(NULL, " ,");
	material = parameters;
	if (material == " ")
	{
		cout << "NO\n";
		return;
	}

	parameters = strtok(NULL, " ,");
	age = atoi(parameters);
	if (age == 0)
	{
		cout << "NO\n";
		return;
	}

	parameters = strtok(NULL, " ,");
	corporealForm = parameters;
	if (corporealForm == " ")
	{
		cout << "NO\n";
		return;
	}

	try
	{
		this->controller.addGuardianStatue(powerWord, material, age, corporealForm);
	}
	catch (exception& exception)
	{
		cout << "NO\n";
	}

}

void UserInterface::deleteGuardianStatueUI(char* parameters)
{
	string powerWord;

	parameters = strtok(NULL, ",");
	powerWord = parameters;
	if (powerWord == " ")
	{
		cout << "NO\n";
		return;
	}
	powerWord.erase(powerWord.length() - 1);
	try
	{
		this->controller.deleteGuardianStatue(powerWord);
	}
	catch (exception& exception)
	{
		cout << "NO\n";
	}
}

void UserInterface::updateGuardianStatueUI(char* parameters)
{
	string powerWord, newMaterial, newCorporealForm;
	int newAge;

	parameters = strtok(NULL, ",");
	powerWord = parameters;
	if (powerWord == " ")
	{
		cout << "NO\n";
		return;
	}

	parameters = strtok(NULL, " ,");
	newMaterial = parameters;
	if (newMaterial == " ")
	{
		cout << "NO\n";
		return;
	}

	parameters = strtok(NULL, " ,");
	newAge = atoi(parameters);
	if (newAge == 0)
	{
		cout << "NO\n";
		return;
	}

	parameters = strtok(NULL, " ,");
	newCorporealForm = parameters;
	if (newCorporealForm == " ")
	{
		cout << "NO\n";
		return;
	}

	try
	{
		this->controller.updateGuardianStatue(powerWord, newMaterial, newAge, newCorporealForm);
	}
	catch (exception& exception)
	{
		cout << "NO\n";
	}
}

void UserInterface::listGuardianStatuesUI()
{
	DynamicArray<GuardianStatue> guardianStatues = this->controller.getAllStatues();
	for (int i = 0; i < guardianStatues.getSize(); i++)
	{
		cout << guardianStatues[i].toString();
	}

}

void UserInterface::listGuardianStatuesWithParametersUI(char* parameters)
{
	string material;
	int age;
	parameters = strtok(NULL, ",");
	material = parameters;
	if (material == "")
	{
		cout << "NO\n";
		return;
	}
	parameters = strtok(NULL, " ,");
	age = atoi(parameters);
	if (age == 0)
	{
		cout << "NO\n";
		return;
	}
	DynamicArray<GuardianStatue> filteredGuardianStatues = this->controller.getFilteredStatues(material, age);
	if (filteredGuardianStatues.getSize() == 0)
		listGuardianStatuesUI();
	for (int i = 0; i < filteredGuardianStatues.getSize(); i++)
		cout << filteredGuardianStatues[i].toString();
}

void UserInterface::getNextGuardianStatueUI()
{
	GuardianStatue nextStatue = this->controller.getNextGuardianStatue();
	cout << nextStatue.toString();

}

void UserInterface::saveGuardianStatue(char* parameters)
{
	string powerWord;
	powerWord = strtok(NULL, "\n");
	
	if (powerWord == "")
	{
		cout << "NO\n";
		return;
	}
	this->controller.saveGuardianStatue(powerWord);
}

void UserInterface::listMyList()
{
	DynamicArray<GuardianStatue> myList = this->controller.getMyList();
	for (int i = 0; i < myList.getSize(); i++)
		cout << myList[i].toString();
}

void UserInterface::run()
{
	while (true)
	{
		string userCommand;
		char userInput[1005];
		char command[1005];
		string mode;

		getline(cin, userCommand);
		if (userCommand == "exit")
			return;
		else if (userCommand == "mode A")
		{
			while (true)
			{
				fgets(userInput, sizeof(userInput), stdin);
				strcpy(command, strtok(userInput, " "));
				if (strcmp(command, "add") == 0)
				{
					addGuardianStatueUI(userInput);
				}
				else if (strcmp(command, "delete") == 0)
				{
					deleteGuardianStatueUI(userInput);
				}
				else if (strcmp(command, "update") == 0)
				{
					updateGuardianStatueUI(userInput);
				}
				else if (strcmp(command, "list\n") == 0)
				{
					listGuardianStatuesUI();
				}
				else if (strcmp(command, "exit\n") == 0)
					return;
				else if (strcmp(userInput, "mode") == 0)
				{
					mode = strtok(NULL, " ");
					if (mode == "B\n")
						break;
					else
						cout << "Not a mode!\n";
				}
				else if (strcmp(userInput, "save") == 0)
				{
					saveGuardianStatue(userInput);
				}
				else
					cout << "Bad incantation\n";

			}
			userCommand = "mode B";
		}
		if (userCommand == "mode B")
		{
			while (true)
			{
				fgets(userInput, sizeof(userInput), stdin);
				strcpy(command, strtok(userInput, " "));
				if (strcmp(command, "exit\n") == 0)
					return;
				else if (strcmp(command, "list") == 0)
				{
					listGuardianStatuesWithParametersUI(userInput);
				}
				else if (strcmp(userInput, "next\n") == 0)
				{
					getNextGuardianStatueUI();
				}
				else if (strcmp(userInput, "mode") == 0)
				{
					mode = strtok(NULL, " ");
					if (mode == "A\n")
						break;
					else
						cout << "Not a mode!\n";
				}
				else if (strcmp(userInput, "save") == 0)
				{
					saveGuardianStatue(userInput);
				}
				else if (strcmp(userInput, "mylist\n") == 0)
				{
					listMyList();
				}
				else
				{
					cout << "Bad incantation\n";
				}

			}
		}
		else
			cout << "Not a mode!\n";
	}


}
