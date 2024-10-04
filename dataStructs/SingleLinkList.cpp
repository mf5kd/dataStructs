#include "SingleLinkList.h"

SingleLinkList::SingleLinkList() {
    headPtr = nullptr;
    tailPtr = nullptr;
}
SingleLinkList::SingleLinkList(string d) {
    Node* tempPtr = new Node;
    tempPtr->data = d;
    tempPtr->nextPtr = nullptr;
    tempPtr->ID = NumOfIndexs + 1;
    headPtr = tempPtr;
    tailPtr = tempPtr;
    NumOfIndexs++;
}
SingleLinkList::SingleLinkList(vector<string> d) {
    headPtr = nullptr;
    tailPtr = nullptr;
    for (int i = 0; i < d.size(); i++) {
        addNode(d[i]);
    }
}

void SingleLinkList::printHeadNode() {
    cout << headPtr->data << endl;
}

void SingleLinkList::printTailNode() {
    cout << tailPtr->data << endl;
}

void SingleLinkList::printNode(int id) {
    Node* tempPtr = headPtr;
    while (tempPtr->ID != id) {
        tempPtr = tempPtr->nextPtr;
    }
    cout << tempPtr->data << " -> " << tempPtr->nextPtr->data;
}

void SingleLinkList::addNode(string d) {
    // create a new node and putting in the data
    Node* newNode = new Node;
    newNode->data = d;
    newNode->nextPtr = nullptr;
    newNode->ID = NumOfIndexs + 1;

    // if list is empty, the new node is top of list
    if (headPtr == nullptr) {
        headPtr = newNode;
        tailPtr = newNode;
    }

    else {
        Node* tempPtr = headPtr;
        while (tempPtr != nullptr && tempPtr->nextPtr != nullptr) {
            tempPtr = tempPtr->nextPtr;
        }
        //adjust the pointers
        newNode->nextPtr = tempPtr->nextPtr;
        tempPtr->nextPtr = newNode;
        tailPtr = newNode;
    }
    NumOfIndexs++;
}

void SingleLinkList::addNodeBefore(int id, string dNew) {
    if (id = NumOfIndexs | id > NumOfIndexs) {
        cout << "not in list\n";
        return;
    }

    if (headPtr == nullptr) {
        cout << "empty list\n";
        return;
    }
    if (headPtr->ID == id) {
        Node* newNode = new Node;
        newNode->data = dNew;
        newNode->nextPtr = headPtr;
        newNode->ID = headPtr->ID;
        headPtr = newNode;
        Node* tempPtr = headPtr->nextPtr;
        while (tempPtr != nullptr) {
            tempPtr->ID++;
            tempPtr = tempPtr->nextPtr;
        }
        NumOfIndexs++;
        return;
    }

    else {
        Node* tempPtr = headPtr;
        while (tempPtr->nextPtr->ID != id) {
            tempPtr = tempPtr->nextPtr;

        }


        //adjust the pointers
        Node* newNode = new Node;
        newNode->nextPtr = tempPtr->nextPtr;
        newNode->data = dNew;
        newNode->ID = tempPtr->nextPtr->ID;
        tempPtr->nextPtr = newNode;
        
        tempPtr = tempPtr->nextPtr->nextPtr;
        while (tempPtr != nullptr) {
            tempPtr->ID++;
            tempPtr = tempPtr->nextPtr;
        }
        NumOfIndexs++;
    }

}

void SingleLinkList::addNodeAfter(int id, string dNew) {
    // if list is empty, the new node is top of list
    if (headPtr == nullptr) {
        cout << "empty list\n";
        return;
    }

    Node* tempPtr = headPtr;
    while (tempPtr->ID != id) {
        tempPtr = tempPtr->nextPtr;
        if (tempPtr == nullptr) {
            cout << "not in list\n";
            return;
        }
    }

    //adjust the pointers
    Node* newNode = new Node;
    newNode->nextPtr = tempPtr->nextPtr;
    newNode->data = dNew;
    newNode->ID = id + 1;
    tempPtr->nextPtr = newNode;

    tempPtr = tempPtr->nextPtr->nextPtr;
    while (tempPtr != nullptr) {
        tempPtr->ID++;
        tempPtr = tempPtr->nextPtr;
    }
    NumOfIndexs++;
}


bool SingleLinkList::remove(int id) {
    if (headPtr == nullptr) {
        cout << "Can not delete from an empty list\n";
        return false;
    }

    if (headPtr->ID == id) {
        Node* delNode = headPtr;
        headPtr = headPtr->nextPtr;
        delete delNode;
        delNode = nullptr;
        NumOfIndexs--;
        Node* tempPtr = headPtr;
        while (tempPtr != nullptr) {
            tempPtr->ID--;
            tempPtr = tempPtr->nextPtr;
        }
        return true;
    }

    Node* tempPtr = headPtr;
    while (tempPtr != nullptr) {
        if (tempPtr->nextPtr->ID == id) {
            Node* delNode = tempPtr->nextPtr;
            tempPtr->nextPtr = tempPtr->nextPtr->nextPtr;
            delete delNode;
            delNode = nullptr;
            NumOfIndexs--;
            tempPtr = tempPtr->nextPtr;
            while (tempPtr != nullptr) {
                tempPtr->ID--;
                tempPtr = tempPtr->nextPtr;
            }
            return;
        }
        tempPtr = tempPtr->nextPtr;
    }
    cout << "Item not found\n";
}

void SingleLinkList::delNodeBefore(int id) {
    if (headPtr == nullptr) {
        cout << "Can not delete from an empty list\n";
        return;
    }

    if (headPtr->nextPtr->ID == id) {
        Node* delNode = headPtr;
        headPtr = headPtr->nextPtr;
        delete delNode;
        delNode = nullptr;
        return;
    }

    Node* tempPtr = headPtr;
    while (tempPtr->nextPtr != nullptr) {
        if (tempPtr->nextPtr->nextPtr->ID == id) {
            Node* delNode = tempPtr->nextPtr;
            tempPtr->nextPtr = tempPtr->nextPtr->nextPtr;
            delete delNode;
            delNode = nullptr;
            return;
        }
        tempPtr = tempPtr->nextPtr;
    }
    cout << "Item not found\n";
}

void SingleLinkList::delNodeAfter(int id) {
    if (headPtr == nullptr) {
        cout << "Can not delete from an empty list\n";
        return;
    }

    Node* tempPtr = headPtr;
    while (tempPtr != nullptr) {
        if (tempPtr->ID == id) {
            Node* delNode = tempPtr->nextPtr;
            tempPtr->nextPtr = tempPtr->nextPtr->nextPtr;
            delete delNode;
            delNode = nullptr;
            return;
        }
        tempPtr = tempPtr->nextPtr;
    }
    cout << "Item not found\n";
}

void SingleLinkList::printList() {
    Node* tempPtr = headPtr;
    while (tempPtr != nullptr) {
        cout << "(" + tempPtr->data + ", " << tempPtr->ID << ") -> ";
        tempPtr = tempPtr->nextPtr;
    }
    cout << "null" << endl;
}