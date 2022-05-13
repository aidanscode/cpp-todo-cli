#include <iostream>
#include <fstream>
#include <string>
#include "LinkedNode.h"

using namespace std;

void printNode(LinkedNode* node) {
	cout << (node->complete ? "(DONE) " : "") << node->value << endl;
}

int main(int argc, char* argv[]) {
	ifstream file("data/todo.csv");

	LinkedNode* rootNode = NULL;
	LinkedNode* previousNode = NULL;

	for (string line ; getline(file, line); ) {
		if (line.length() < 3) {
			continue;
		}

		LinkedNode* curNode = new LinkedNode(line[0] == '1', line.substr(2, line.length() - 2));

		if (!rootNode) {
			rootNode = curNode;
		}
		if (previousNode) {
			previousNode->next = curNode;
		}
		previousNode = curNode;
	}
	file.close();

	cout << "All nodes from root:" << endl;
	cout << "--------------------" << endl;

	LinkedNode* curNode = rootNode;
	while (curNode) {
		printNode(curNode);
		curNode = curNode->next;
	}
}

/*
int main(int argc, char* argv[]) {
	LinkedNode end;
	end.value = "End of line";
	end.complete = 0;

	LinkedNode node;
	node.value = "Some string";
	node.complete = 1;
	node.next = &end;

	cout << "Test node: node" << endl;
	testNode(node);
	cout << "Test node: end" << endl;
	testNode(end);
	cout << "Test node: end (thru node)" << endl;
	testNode(*node.next);
	return 0;
}*/
