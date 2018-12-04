#include <iostream>
#include <vector>
#include "TwoLinkedList.h"

using namespace std;

int main() {

	Node<int> firstNode;
	firstNode.value = 10;

	MyTWList<int> testList(&firstNode);

	/*
	vector<int> v;
	cout << "Hello, world!" << endl;

	Node<int> firstNode;
	firstNode.value = 10;
	
	MyTWList<int> testList(&firstNode);

	testList.show_debug();

	Node<int> secondNode;
	secondNode.value = 15;
	testList.push_back(&secondNode);
	Node<int> thirdNode;
	thirdNode.value = 20;
	testList.push_back(&thirdNode);

	testList.show_debug();

	testList.pop_head();

	testList.show_debug();
	*/

	int i = 0;
	cin >> i;
	return 0;
}