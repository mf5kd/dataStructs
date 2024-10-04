#include "DoubleLinkList.h"

DoubleLinkList::DoubleLinkList() {
    headPtr = nullptr;
}

DoubleLinkList::DoubleLinkList(string d) {
    DNode* tempPtr = new DNode;
    tempPtr->data = d;
    tempPtr->nextPtr = nullptr;
    tempPtr->prevPrt = nullptr;
    headPtr = tempPtr;
}

DoubleLinkList::DoubleLinkList(vector<string> d) {
    headPtr = nullptr;
    for (int i = 0; i < d.size(); i++) {
        addNode(d[i]);
    }
}

void DoubleLinkList::printNode(string d) {
    if (headPtr->data == d) {
        cout << "null <- " << headPtr->data << " -> " << headPtr->nextPtr->data << endl;
        return; 
    }
    
    DNode* tempPtr = headPtr;
    while (tempPtr->data != d) {
        tempPtr = tempPtr->nextPtr;
    }
    if (tempPtr->nextPtr == nullptr)
        cout << tempPtr->prevPrt->data << " <- " << tempPtr->data << " -> null\n";
    else
        cout << tempPtr->prevPrt->data << " <- " << tempPtr->data << " -> " << tempPtr->nextPtr->data << endl;
}

void DoubleLinkList::addNode(string d) {
    // create a new node and putting in the data
    DNode* newNode = new DNode;
    newNode->data = d;
    newNode->nextPtr = nullptr;
    newNode->prevPrt = nullptr;

    // if list is empty, the new node is top of list
    if (headPtr == nullptr) {
        headPtr = newNode;
    }

    else {
        DNode* tempPtr = headPtr;
        while (tempPtr != nullptr && tempPtr->nextPtr != nullptr) {
            tempPtr = tempPtr->nextPtr;
        }
        //adjust the pointers
        newNode->nextPtr = tempPtr->nextPtr;
        newNode->prevPrt = tempPtr;
        tempPtr->nextPtr = newNode;
    }

}
/*
void DoubleLinkList::addNodeBefore(string d, string dNew) {
    // if list is empty, the new node is top of list
    if (headPtr == nullptr) {
        cout << "empty list\n";
        return;
    }
    if (headPtr->data == d) {
        DNode* newNode = new DNode;
        newNode->data = dNew;
        newNode->nextPtr = headPtr;
        headPtr = newNode;
        return;
    }

    else {
        DNode* tempPtr = headPtr;
        while (tempPtr->nextPtr->data != d) {
            tempPtr = tempPtr->nextPtr;
            if (tempPtr == nullptr)
                cout << "not in list\n";
            return;
        }

        //adjust the pointers
        DNode* newNode = new DNode;
        newNode->nextPtr = tempPtr->nextPtr;
        newNode->data = dNew;
        tempPtr->nextPtr = newNode;
    }

}

void DoubleLinkList::addNodeAfter(string d, string dNew) {
    // if list is empty, the new node is top of list
    if (headPtr == nullptr) {
        cout << "empty list\n";
        return;
    }

    DNode* tempPtr = headPtr;
    while (tempPtr->data != d) {
        tempPtr = tempPtr->nextPtr;
        if (tempPtr == nullptr) {
            cout << "not in list\n";
            return;
        }
    }

    //adjust the pointers
    DNode* newNode = new DNode;
    newNode->nextPtr = tempPtr->nextPtr;
    newNode->data = dNew;
    tempPtr->nextPtr = newNode;
}


void DoubleLinkList::delNode(string d) {
    if (headPtr == nullptr) {
        cout << "Can not delete from an empty list\n";
        return;
    }

    if (headPtr->data == d) {
        DNode* delNode = headPtr;
        headPtr = headPtr->nextPtr;
        delete delNode;
        delNode = nullptr;
        return;
    }

    DNode* tempPtr = headPtr;
    while (tempPtr != nullptr) {
        if (tempPtr->nextPtr->data == d) {
            DNode* delNode = tempPtr->nextPtr;
            tempPtr->nextPtr = tempPtr->nextPtr->nextPtr;
            delete delNode;
            delNode = nullptr;
            return;
        }
        tempPtr = tempPtr->nextPtr;
    }
    cout << "Item not found\n";
}

void DoubleLinkList::delNodeBefore(string d) {
    if (headPtr == nullptr) {
        cout << "Can not delete from an empty list\n";
        return;
    }

    if (headPtr->nextPtr->data == d) {
        DNode* delNode = headPtr;
        headPtr = headPtr->nextPtr;
        delete delNode;
        delNode = nullptr;
        return;
    }

    DNode* tempPtr = headPtr;
    while (tempPtr->nextPtr != nullptr) {
        if (tempPtr->nextPtr->nextPtr->data == d) {
            DNode* delNode = tempPtr->nextPtr;
            tempPtr->nextPtr = tempPtr->nextPtr->nextPtr;
            delete delNode;
            delNode = nullptr;
            return;
        }
        tempPtr = tempPtr->nextPtr;
    }
    cout << "Item not found\n";
}

void DoubleLinkList::delNodeAfter(string d) {
    if (headPtr == nullptr) {
        cout << "Can not delete from an empty list\n";
        return;
    }

    DNode* tempPtr = headPtr;
    while (tempPtr != nullptr) {0.
        if (tempPtr->data == d) {
            DNode* delNode = tempPtr->nextPtr;
            tempPtr->nextPtr = tempPtr->nextPtr->nextPtr;
            delete delNode;
            delNode = nullptr;
            return;
        }
        tempPtr = tempPtr->nextPtr;
    }
    cout << "Item not found\n";
}
*/ 

void DoubleLinkList::printList() {
    DNode* tempPtr = headPtr;
    DNode* lastPrt = nullptr;

    while (tempPtr != nullptr) {
        cout << tempPtr->data << " -> ";
        if (tempPtr->nextPtr == nullptr) {
            lastPrt = tempPtr;
        }
        tempPtr = tempPtr->nextPtr;
    }
    cout << "null" << endl;
    

    while (lastPrt != nullptr) {
        cout << lastPrt->data << " -> ";
        lastPrt = lastPrt->prevPrt;
    }
    cout << "null" << endl;
   
}