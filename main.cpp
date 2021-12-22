#include <iostream>
#include <fstream>
#include "ListRand.h"

using namespace::std;

ListNode *Head = new  ListNode(),
         *One = new  ListNode(),
         *Two = new  ListNode(),
         *Three = new ListNode(),
         *Four = new  ListNode(),
         *Five = new ListNode(),
         *Six = new  ListNode(),
         *Tail = new  ListNode();
ListRand MainList;
ListRand TestList;
#define NextPrev(x,y) x->Next = y; y->Prev = x;
#define NodeData(x) x->Data = #x;

int main()
{
  NextPrev(Head, One)
  NextPrev(One, Two)
  NextPrev(Two, Three)
  NextPrev(Three, Four)
  NextPrev(Four, Five)
  NextPrev(Five, Six)
  NextPrev(Six, Tail)
  
  NodeData(Head)
  NodeData(One)
  NodeData(Two)
  NodeData(Three)
  NodeData(Four)
  NodeData(Five)
  NodeData(Six)
  NodeData(Tail)

  Head->Rand = Four;
  One->Rand = Tail;
  Three->Rand = Three;
  Four->Rand = Head;

  MainList.Head = Head;
  MainList.Tail = Tail;

  fstream fs;
  fs.open("listFile.txt", ios_base::out | ios_base::binary);
  cout << "Initial List:" << endl;
  PrintListRand(MainList);
  MainList.Serialize(fs);
  fs.close();

  fs.open("listFile.txt", ios_base::in | ios_base::binary);
  TestList.Deserialize(fs);
  cout << "Deserialized List:" << endl;
  PrintListRand(TestList);
  fs.close();
  return 0;
}