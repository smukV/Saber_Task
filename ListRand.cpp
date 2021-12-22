#include "ListRand.h"
#include <iostream>

void ListRand::Serialize(fstream& fs)
{
  ListNode* node = Head;
  map<string, int> nodesMap;
  nodesMap["nulltpr"] = -1;
  for (int i = 0; node != nullptr; i++, node = node->Next)
  {
    nodesMap[node->Data] = i;
  }
  node = Head;
  while (node->Next != nullptr)
  {
    fs << node->Data.data() << ' '
       << ((node->Rand) ? (nodesMap[node->Rand->Data]) : -1) << ' ';
    node = node->Next;
  }
  fs << node->Data.data() << ' '
     << ((node->Rand) ? (nodesMap[node->Rand->Data]) : -1);
}

void ListRand::Deserialize(fstream& fs) 
{
  DestroyListRand(this);
  vector<pair<ListNode*, int>> nodesArray;
  string data;
  int randNodeNumber;
  ListNode* currentNode;
  while (!fs.eof())
  {
    fs >> data >> randNodeNumber;
    currentNode = new ListNode();
    currentNode->Data = data;
    nodesArray.push_back(pair<ListNode*, int>(currentNode, randNodeNumber));
  }
  if (nodesArray.size() == 0)
    return;
  Head = nodesArray.at(0).first;
  randNodeNumber = nodesArray.at(0).second;
  Head->Rand = (randNodeNumber == -1)
               ? nullptr : nodesArray.at(randNodeNumber).first;
  Tail = nodesArray.at(nodesArray.size() - 1).first;
  for (size_t i = 1; i < nodesArray.size(); i++)
  {
    currentNode = nodesArray.at(i).first;
    randNodeNumber = nodesArray.at(i).second;
    currentNode->Rand = (randNodeNumber == -1)
                        ? nullptr : nodesArray.at(randNodeNumber).first;
    currentNode->Prev = nodesArray.at(i - 1).first;
    currentNode->Prev->Next = currentNode;
  }
}

void DestroyListRand(ListRand* randList) {
  if (randList->Head == nullptr) return;
  ListNode* currentNode = randList->Head->Next;
  if (currentNode == nullptr) {
    delete randList->Head;
    return;
  }
  while (currentNode->Next != nullptr) {
    delete currentNode->Prev;
    currentNode = currentNode->Next;
  }
  delete currentNode;
}

void PrintListRand(ListRand& randList) {
  if (randList.Head == nullptr) {
    cout << "List is empty";
    return;
  }
  ListNode* cur = randList.Head;
  while (cur != nullptr) {
    cout << cur->Data
         << " -- Rand pointer: " << ((cur->Rand) ? cur->Rand->Data : "no such")
         << endl;
    cur = cur->Next;
  }
}