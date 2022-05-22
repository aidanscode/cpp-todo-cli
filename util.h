#ifndef UTIL_H
#define UTIL_H

#include "LinkedNode.h"

LinkedNode* getNodeByIndex(LinkedNode* rootNode, int desiredIndex);

bool isCStrValidInt(const char* str);

int cStrToInt(const char* str);

int lengthOfCStr(const char* str);

#endif
