#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "Repo.hpp"
#include "Controller.hpp"
#include "UI.hpp"
#include "Tester.hpp"
using namespace std;

int main()
{
	FileRepoTester repoTester = FileRepoTester();
	repoTester.testAll();
	ControllerTester controllerTester = ControllerTester();
	controllerTester.testAll();
	DomainTester domainTester = DomainTester();
	domainTester.testAll();

	string filename = "test1.txt";
	FileRepository repo = FileRepository(filename);
	Controller controller = Controller(repo);
	UserInterface ui = UserInterface(controller);
	ui.run();
	_CrtDumpMemoryLeaks();
	return 0;
}