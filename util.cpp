#include "LinkedNode.h"

int cStrToInt(const char* str) {
  return strtol(str, nullptr, 10);
}

int lengthOfCStr(const char* str) {
  int i;
  for (i = 0; str[i] != '\0'; i++);

  return i;
}

LinkedNode* getNodeByIndex(LinkedNode* rootNode, int desiredIndex) {
  LinkedNode* curNode = rootNode;
  int curIndex = 0;

  while (curNode) {
    if (curIndex == desiredIndex) {
      return curNode;
    }

    curNode = curNode->next;
    curIndex++;
  }

  return nullptr;
}

bool isCStrValidInt(const char* str) {
	if (lengthOfCStr(str) == 0) {
		return false;
	}

	char* end;
	strtol(str, &end, 10);

	return *end == 0;
}
