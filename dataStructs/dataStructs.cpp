// dataStructs.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "SingleLinkList.h"
#include "DoubleLinkList.h"
#include "VectorStack.h"


using namespace std;

void PrintVector(vector<string> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ", ";
    }
    cout << endl;
}

int main(){
    int c = 0;
    vector<string> fileData;
    vector<int> data;
    // Open input file and check if there is an error 
    ifstream fin("input.txt");
    if (!fin.is_open()) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }
    // Read data from file into the array
    while (fin.good()) {
        fileData.resize(c + 1);
        fin >> fileData[c];
        c++;
    }
    fin.close();

    for (int x = 1; x <= 26; x++) {
        data.push_back(x);
    }



    SingleLinkList SList(fileData);
    DoubleLinkList DList(fileData);
    VectorStack VStack(data);
    
    cout << "Single Link List\n"; 
    SList.printList();
    cout << "\nDouble Link List\n";
    DList.printList();
    cout << "\nVector Based Stack\n";
    VStack.printStack();



;

