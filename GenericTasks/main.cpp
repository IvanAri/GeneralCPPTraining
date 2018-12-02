#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct Node {
	T value;
	Node<T> * next;
	Node<T> * prev;
};

/*	Two-way list
*
*	The main idea:
*	Practice basic programming skills and templates
*	Learn something new about modern template usage
*	Try to implement all of the class parts in standard style
*
*
*
*
*/

template <typename T>
class MyTWList {


public:

	MyTWList<T>(Node<T> * newHead) : head(newHead), tail(newHead), size(1){
		head->next = tail;
		head->prev = tail;
	}
	MyTWList<T>() : size(0) {}

	void MyTWList<T>::show_list() {
		Node<T> * lookingAtNode = head;
		unsigned int counter = 0; 
		while (counter != this->size) {
			cout << counter << " : " << lookingAtNode->value << endl;
			lookingAtNode = lookingAtNode->next;
			counter++;
		}
	}

	void MyTWList<T>::show_debug() {
		cout << "====== DEBUG SECTION ======" << endl;
		cout << "head: " << this->head << endl;
		cout << "tail: " << this->tail << endl;
		cout << "size: " << this->size << endl;
		this->show_list();
		cout << "====== END OF DEBUG ======" << endl;
	}

	void MyTWList<T>::push_back(Node<T> * newNode) {
		if (this->size == 0) {
			this->set_head_node(newNode);
			return;
		}

		Node<T> * tempNode = tail;
		newNode->prev = tempNode;
		newNode->next = this->head;
		tempNode->next = newNode;
		this->tail = newNode;
		this->size++;
	} 

	void MyTWList<T>::pop_tail() {
		if (this->size == 0) {
			return;
		}

		if (this->size == 1) {
			this->head->next = NULL;
			this->head->prev = NULL;
			this->tail->next = NULL;
			this->tail->prev = NULL;
			this->size--;
			return;
		}

		Node<T> * preTail = tail->prev;
		// Deleting our own references
		tail->next = NULL;
		tail->prev = NULL;
		tail = preTail;
		tail->next = head;
		head->prev = tail;
		this->size--;
	}

	MyTWList<T>::~MyTWList() {
		while (this->size != 0) {
			this->pop_tail();
			cout << "Destroyed value!" << endl;
		}
		cout << "I've destroyed them all!!!" << endl;
	}

private:

	// like first time installation!
	void MyTWList<T>::set_head_node(Node<T> * newHead) {
		this->size++;
		this->head = newHead;
		this->tail = newHead;
		this->tail->next = head;
		this->head->prev = tail;
	}

	Node<T> * head = NULL;
	Node<T> * tail = NULL;

	unsigned int size = 0; // number of elements

};

int main() {

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

	testList.pop_tail();

	testList.show_debug();

	int i = 0;
	cin >> i;
	return 0;
}