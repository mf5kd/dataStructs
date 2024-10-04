#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct DNode {
	string data;
	DNode* nextPtr;
	DNode* prevPrt;
};

class DoubleLinkList {
private:
	DNode* headPtr;


public:
	DoubleLinkList();
	DoubleLinkList(string d);
	DoubleLinkList(vector<string> d);
	void printNode(string d);
	void addNode(string d);
	// void addNodeBefore(string d, string dNew);
	// void addNodeAfter(string d, string dNew);
	// void delNode(string d);
	// void delNodeBefore(string d);
	// void delNodeAfter(string d);
	void printList();
};
