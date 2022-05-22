//#include <iostream>
//#include <fstream>
//#include <string>
#include "LinkedNode.h"
#include "fileio.h"
#include "command-handler.h"

using namespace std;

int main(int argc, char* argv[]) {
	LinkedNode* rootNode = nullptr;
	int success = importTasks(rootNode);

	return handleCommand(argc, argv, rootNode);
}
