#include <iostream>
#include <algorithm>
#include <string>

#include "fileio.h"
#include "command-handler.h"
#include "LinkedNode.h"
#include "util.h"

using namespace std;

void printUnrecognizedCommand(int argc, char* argv[]);

int list(LinkedNode* rootNode, const char* runnable);
int add(LinkedNode*& rootNode, int argc, char* argv[]);
int done(LinkedNode* rootNode, int argc, char* argv[]);
int rm(LinkedNode*& rootNode, int argc, char* argv[]);
int clear();
int help();

int handleCommand(int argc, char* argv[], LinkedNode*& rootNode) {
	string command = (argc < 2) ? "list" : argv[1];
	transform(command.begin(), command.end(), command.begin(), ::tolower);

	if (command == "list") {
		return list(rootNode, argv[0]);
	} else if (command == "add") {
		return add(rootNode, argc, argv);
	} else if (command == "help") {
		return help();
	} else if (command == "done") {
		return done(rootNode, argc, argv);
	} else if (command == "rm") {
		return rm(rootNode, argc, argv);
	} else if (command == "clear") {
		return clear();
	} else {
		printUnrecognizedCommand(argc, argv);

		return 1;
	}
}

void printUnrecognizedCommand(int argc, char* argv[]) {
	string command = (argc >= 1) ? argv[0] : "todo";
	cout << "Unrecognized command! Use: " << command << " help" << endl;
}

int add(LinkedNode*& rootNode, int argc, char* argv[]) {
	//Find final node in list
	LinkedNode* finalNode = rootNode;
	while (finalNode && finalNode->next) {
		finalNode = finalNode->next;
	}

	//Add each new task to the end of the list
	for (int i = 2; i < argc; i++) {
		string task = argv[i];
		LinkedNode* newNode = new LinkedNode(0, task);

		if (!rootNode) {
			rootNode = newNode;
			finalNode = newNode;
		} else {
			finalNode->next = newNode;
			finalNode = newNode;
		}
	}

	exportTasks(rootNode);

	return 0;
}

int done(LinkedNode* rootNode, int argc, char* argv[]) {
	if (argc < 3) {
		cout << "Please supply the index of at least one task." << endl;
		return 1;
	}

	if (isCStrValidInt(argv[2]) == false) {
		cout << "Given index is not a valid int." << endl;
		return 1;
	}

	int index = cStrToInt(argv[2]);
	LinkedNode* node = getNodeByIndex(rootNode, index);
	if (node == nullptr) {
		cout << "No task found with the given index" << endl;
		return 1;
	}

	node->complete = 1;
	exportTasks(rootNode);

	return 0;
}

int rm(LinkedNode*& rootNode, int argc, char* argv[]) {
	if (argc < 3) {
    cout << "Please supply the index of at least one task." << endl;
    return 1;
  }

  if (isCStrValidInt(argv[2]) == false) {
    cout << "Given index is not a valid int." << endl;
    return 1;
  }

	int desiredIndex = cStrToInt(argv[2]);
	if (desiredIndex == 0) {

		if (rootNode) {
			rootNode = rootNode->next;
		} else {
			cout << "No task found with the given index" << endl;
			return 1;
		}

	} else {

		LinkedNode* priorNode = getNodeByIndex(rootNode, desiredIndex - 1);
		if (priorNode && priorNode->next) {
			priorNode->next = priorNode->next->next;
		} else {
			cout << "No task found with the given index" << endl;
			return 1;
		}

	}

	exportTasks(rootNode);
	return 0;
}

int help() {
	cout << "Todo help" << endl;
	cout << "  add [TASK(s)] - Add one or more tasks" << endl;
	cout << "  list - List all tasks" << endl;
	cout << "  done [INDEX] - Mark one or more tasks as done" << endl;
	cout << "  rm [INDEX] - Remove one or more tasks from the list" << endl;
  cout << "  sort - Move all incomplete tasks to the front" << endl;
	cout << "  clear - Delete all saved tasks" << endl;

	return 0;
}

int list(LinkedNode* rootNode, const char* runnable) {
	if (!rootNode) {
		cout << "There are no saved tasks! Use \"" << runnable << " help\" to see available commands." << endl;
	} else {
		LinkedNode* curNode = rootNode;
		int curIndex = 0;
		while (curNode) {
			cout << curIndex << ": " << (curNode->complete ? "(DONE) " : "") << curNode->value << endl;

			curNode = curNode->next;
			curIndex++;
		}
	}

	return 0;
}

int clear() {
	exportTasks(nullptr);

	return 0;
}
