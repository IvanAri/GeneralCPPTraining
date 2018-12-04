#pragma once

#include <iostream>

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

	MyTWList<T>(Node<T> * newHead);

	MyTWList<T>();

	void MyTWList<T>::show_list();

	void MyTWList<T>::show_debug();

	void MyTWList<T>::push_back(Node<T> * newNode);

	void MyTWList<T>::pop_tail();

	void MyTWList<T>::pop_head();

	MyTWList<T>::~MyTWList();

private:

	// like first time installation!
	void MyTWList<T>::set_head_node(Node<T> * newHead);

	Node<T> * head;
	Node<T> * tail;
	unsigned int size; // number of elements

};