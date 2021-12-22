#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace ::std;

class ListNode {
 public:
  ListNode* Prev;
  ListNode* Next;
  ListNode* Rand;  // произвольный элемент внутри списка
  string Data;
};

class ListRand {
 public:
  ListNode* Head;
  ListNode* Tail;
  int Count;

  void Serialize(fstream& fs);
  void Deserialize(fstream& fs);
};
void DestroyListRand(ListRand* randList);
void PrintListRand(ListRand& randList);