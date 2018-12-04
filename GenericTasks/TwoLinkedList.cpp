#include "TwoLinkedList.h"

#include <iostream>

using namespace std;

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
	MyTWList<T>::MyTWList(Node<T> * newHead) : head(newHead), tail(newHead), size(1) {
		head->next = tail;
		head->prev = tail;
	}

	template MyTWList<int>::MyTWList(Node<int> * newHead);

	template <typename T>
	MyTWList<T>::MyTWList() : size(0) {}

	template MyTWList<int>::MyTWList();

	template <typename T>
	void MyTWList<T>::show_list() {
		Node<T> * lookingAtNode = head;
		unsigned int counter = 0;
		while (counter != this->size) {
			cout << counter << " : " << lookingAtNode->value << endl;
			lookingAtNode = lookingAtNode->next;
			counter++;
		}
	}

	template void MyTWList<int>::show_list();

	template <typename T>
	void MyTWList<T>::show_debug() {
		cout << "====== DEBUG SECTION ======" << endl;
		cout << "head: " << this->head << endl;
		cout << "tail: " << this->tail << endl;
		cout << "size: " << this->size << endl;
		this->show_list();
		cout << "====== END OF DEBUG ======" << endl;
	}

	template void MyTWList<int>::show_debug();

	template <typename T>
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

	template void MyTWList<int>::push_back(Node<int> * newNode);

	template <typename T>
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

	template void MyTWList<int>::pop_tail();

	template <typename T>
	void MyTWList<T>::pop_head() {
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

		Node<T> * afterHead = head->next;
		// Deleting our own references
		head->next = NULL;
		head->prev = NULL;
		head = afterHead;
		tail->next = head;
		head->prev = tail;
		this->size--;
	}

	template void MyTWList<int>::pop_head();

	template <typename T>
	MyTWList<T>::~MyTWList() {
		while (this->size != 0) {
			this->pop_tail();
			cout << "Destroyed value!" << endl;
		}
		cout << "I've destroyed them all!!!" << endl;
	}

	template MyTWList<int>::~MyTWList();

	/*
	*
	*	Here goes private functions section
	*
	*/


	// like first time installation!
	template <typename T>
	void MyTWList<T>::set_head_node(Node<T> * newHead) {
		this->size++;
		this->head = newHead;
		this->tail = newHead;
		this->tail->next = head;
		this->head->prev = tail;
	}

	template void MyTWList<int>::set_head_node(Node<int> * newHead);
