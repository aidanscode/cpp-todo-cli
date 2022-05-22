#include <fstream>
#include <string>
#include "LinkedNode.h"
#include "fileio.h"

#define DATA_PATH "data/todo.csv"

using namespace std;

int importTasks(LinkedNode*& rootNode) {
	ifstream file(DATA_PATH);
  LinkedNode* previous;

  for (string line; getline(file, line); ) {
    if (line.length() < 3) {
      continue;
    }

    LinkedNode* curNode = new LinkedNode(
      line[0] == '1',
      line.substr(2, line.length() - 2)
    );

    if (!rootNode) {
      rootNode = curNode;
    }

    if (previous) {
      previous->next = curNode;
    }

    previous = curNode;
  }

  file.close();

	return 0;
}

int exportTasks(LinkedNode* rootNode) {
	ofstream fout(DATA_PATH);

	LinkedNode* curNode = rootNode;
	while (curNode) {
		fout << curNode->complete << "," << curNode->value << endl;
		curNode = curNode->next;
	}

	fout.close();

	return 0;
}
