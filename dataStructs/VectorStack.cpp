#include "VectorStack.h";


VectorStack::VectorStack() {
}

VectorStack::VectorStack(vector<int> v) {
	for (int x = 0; x < v.size(); x++) {
		push(v[x]);
	}
}

void VectorStack::push(int& item) {
	container.push_back(item);
}


void VectorStack::pop() {
	container.pop_back();
}

int& VectorStack::top() {
	return container.back();
}


bool VectorStack::empty() {
	return container.empty();
}


int VectorStack::size() {
	return container.size();
}

void VectorStack::printStack() {
	for (int x = size(); x > 0; x--) {
		cout << container[x - 1] << "|";
	}
	cout << endl;
}

float VectorStack::average() {
	float a = 0;
	for (int x = 0; x < size(); x++) {
		a += container[x];
	}
	return a / size();
}