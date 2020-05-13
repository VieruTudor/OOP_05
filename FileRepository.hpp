#include "Domain.hpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class FileRepository
{
private:
	string fileName;
	vector<GuardianStatue> statuesList;
public:
	FileRepository();
	FileRepository(string& fileName);
	int searchGuardianStatue(GuardianStatue& guardianStatue);
	void addGuardianStatue(GuardianStatue& guardianStatue);
	void deleteGuardianStatue(const string& powerWord);
	void updateGuardianStatue(GuardianStatue& oldGuardianStatue, GuardianStatue& newGuardianStatue);
	vector<GuardianStatue> getStatues();
	int getSize();
	
	string getFileName();
	void setFileName(string& fileName);
	void clearFile();



};