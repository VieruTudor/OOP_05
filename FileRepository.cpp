#include "FileRepository.hpp"

FileRepository::FileRepository()
{
}

FileRepository::FileRepository(string& fileName)
{
	this->fileName = fileName;
	fstream file;
	file.open(this->fileName, fstream::in | fstream::out | fstream::app);
	file.close();
}

int FileRepository::searchGuardianStatue(GuardianStatue& guardianStatue)
{
	ifstream fin(this->fileName);
	GuardianStatue readStatue;
	int index = 0;
	while (fin >> readStatue)
	{
		if (readStatue == guardianStatue)
		{
			fin.close();
			return index;
		}
		index++;
	}
	fin.close();
	return -1;
}

void FileRepository::addGuardianStatue(GuardianStatue& guardianStatue)
{
	int searchIndex = this->searchGuardianStatue(guardianStatue);
	if (searchIndex != -1)
		throw exception();
	ofstream fout(this->fileName, ios::app);
	fout << guardianStatue;
	fout.close();
}

void FileRepository::deleteGuardianStatue(const string& powerWord)
{
	
	ifstream fin(this->fileName);
	GuardianStatue readStatue;
	vector<GuardianStatue> statues;
	
	GuardianStatue dummyStatue = GuardianStatue(powerWord, "", 0, "");
	int searchIndex = this->searchGuardianStatue(dummyStatue);
	if (searchIndex == -1)
		throw exception();

	while (fin >> readStatue)
	{
		if (readStatue.getPowerWord() != powerWord)
		{
			statues.push_back(readStatue);
		}
	}
	ofstream fout(this->fileName);
	for (auto statue : statues)
	{
		fout << statue;
	}
	fout.close();
}

void FileRepository::updateGuardianStatue(GuardianStatue& oldGuardianStatue, GuardianStatue& newGuardianStatue)
{
	ifstream fin(this->fileName);
	GuardianStatue readStatue;
	vector<GuardianStatue> statues;
	
	int searchIndex = this->searchGuardianStatue(oldGuardianStatue);
	if (searchIndex == -1)
		throw exception();
	while (fin >> readStatue)
	{
		if (readStatue == oldGuardianStatue)
			statues.push_back(newGuardianStatue);
		else
		{
			statues.push_back(readStatue);
		}
	}
	fin.close();
	ofstream fout(this->fileName);
	for (auto statue : statues)
	{
		fout << statue;
	}
	fout.close();
}

vector<GuardianStatue> FileRepository::getStatues()
{
	vector<GuardianStatue> statues;
	ifstream fin(this->fileName);
	GuardianStatue readStatue;
	while (fin >> readStatue)
	{
		statues.push_back(readStatue);
	}
	fin.close();
	return statues;
}

int FileRepository::getSize()
{
	return this->getStatues().size();
}

string FileRepository::getFileName()
{
	return this->fileName;
}

void FileRepository::setFileName(string& fileName)
{
	this->fileName = fileName;
}

void FileRepository::clearFile()
{
	remove(this->fileName.c_str());
}
