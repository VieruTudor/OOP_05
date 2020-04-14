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
	RepoTester repoTester = RepoTester();
	repoTester.testAll();
	ControllerTester controllerTester = ControllerTester();
	controllerTester.testAll();

	Repository repo = Repository();
	Controller controller = Controller(repo);
	UserInterface ui = UserInterface(controller);
	ui.run();
	_CrtDumpMemoryLeaks();
	return 0;
}