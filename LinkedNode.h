#ifndef LINKEDNODE_H
#define LINKEDNODE_H

#include <string>

class LinkedNode {
public:
	std::string value;
	int complete = 0;
	LinkedNode* next = NULL;
	LinkedNode(int nodeIsComplete, std::string nodeValue) {
		value = nodeValue;
		complete = nodeIsComplete;
	}
};

#endif
