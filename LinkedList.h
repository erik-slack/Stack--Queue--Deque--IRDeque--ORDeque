#pragma once
#include "LinkedListInterface.h"
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

template<class T>
class LinkedList : public LinkedListInterface<T> {
private:
	struct Node {
		// DATA
		T item;
		Node* next;
		Node* prev;
		
		Node(){
			next = NULL;
			prev = NULL;
		}
	};
	
	int count;
	Node* head;
	Node* tail;

public:
// CONSTRUCTORS
	LinkedList()
	{
		count = 0;
		head = NULL;
		tail = NULL;
	}

	~LinkedList()
	{
		clear();
	}
	
// ANALYZERS
	bool checkDuplicates(T value_in){
		for (int i = 0; i < count; i++){
			T this_node_value = at(i);
			if (value_in == this_node_value){
				return true;
			}
		}
		return false;
	}
	
	Node* get_byIndex(int index_query)
	{
		Node* node_search;
		//int query_converted = atoi(index_query.c_str());

		if (index_query < (count / 2))
		{
			int current_index = 0;
			node_search = head;
			while (current_index != index_query)
			{
				node_search = node_search->next;
				if (current_index == index_query)
				{
					break;
				}
				current_index++;
			}
		}
		else
		{
			int current_index = count - 1;
			node_search = tail;
			while (current_index != index_query)
			{
				if (current_index == index_query)
				{
					break;
				}
				node_search = node_search->prev;
				current_index--;
			}
		}
		
		return node_search;
	}
	
	/*
		at

		Returns the value of the node at the given index. The list begins at
		index 0.

		If the given index is out of range of the list, return NULL;
	 */
	T at(int index){
		Node* node_search;
		T value;
		if (index < count){
			int current_index = -1;
			node_search = head;
			while (current_index <= index)
			{
				if (current_index == -1){current_index = 0;}
				if (current_index == index){
					value = node_search->item;
					break;
				}
				node_search = node_search->next;
				current_index++;
			}
		} /*else {
			//cout << "3node_search->item = " << node_search->item << endl;
			int current_index = count - 1;
			node_search = tail;
			while (current_index != index)
			{
				if (current_index == index)
				{
					value = node_search->item;
					//cout << "4node_search->item = " << node_search->item << endl;
					break;
				}
				node_search = node_search->prev;
				current_index--;
			}
		}*/
		
		
		return value;
	}
	
	/*
		size

		Returns the number of nodes in the list.
	 */
	int size(){
		return count;
	}
	
// MUTATORS	
	/*
		insertHead

		A node with the given value should be inserted at the beginning of the list.

		Do not allow duplicate values in the list.
	 */
	void insertHead(T value){
		bool is_duplicate = checkDuplicates(value);
		if (is_duplicate == false){
			int index = 0;
			
			//cout << "value = " << item_value << endl;
			//cout << "count = " << count << endl;
			Node* n = new Node;
			n->item = value;

			if (count == 0) {
				// add premeire item of list
				head = n;
				tail = n;
				n->next = NULL;
				n->prev = NULL;
			} else if (index == 0) {
				// add at beginning of list
				n->next = head;
				n->prev = NULL;
				head->prev = n;
				head = n;
			}
			
			//cout << print();
			
			//cout << print();
			count++;
		}
	}

	/*
		insertTail

		A node with the given value should be inserted at the end of the list.

		Do not allow duplicate values in the list.
	 */
	void insertTail(T value){
		bool is_duplicate = checkDuplicates(value);
		if (is_duplicate == false){
			int index = count;
			
			Node* n = new Node;
			n->item = value;

			if (count == 0) {
				// add premeire item of list
				head = n;
				tail = n;
				n->next = NULL;
				n->prev = NULL;
			} else if (index == count) {
				// append to list
				n->next = NULL;
				n->prev = tail;
				tail->next = n;
				tail = n;
			}
			count++;
		}
	}

	/*
		insertAfter

		A node with the given value should be inserted immediately after the
		node whose value is equal to insertionNode.

		A node should only be added if the node whose value is equal to
		insertionNode is in the list. Do not allow duplicate values in the list.
	 */
	void insertAfter(T value, T insertionNode){
		bool is_duplicate = checkDuplicates(value);
		bool is_validInsertionNode = checkDuplicates(insertionNode);
		
		if (is_validInsertionNode == true){
			if (is_duplicate == false){
				int atResult = 0;
				
				for (int i = 0; i < count; i++){
					if (at(i) == insertionNode){
						atResult = i;
						break;
					}
				}
				
				int index = atResult + 1;
				
				Node* n = new Node;
				n->item = value;
				
				if (index > count) {
					// index is greater than size of list
					// nothing happens
				} else if (count == 0) {
					// add premeire item of list
					head = n;
					tail = n;
					n->next = NULL;
					n->prev = NULL;
				} else if (index == 0) {
					// add at beginning of list
					n->next = head;
					n->prev = NULL;
					head->prev = n;
					head = n;
				} else if (index == count) {
					// append to list
					n->next = NULL;
					n->prev = tail;
					tail->next = n;
					tail = n;
				} else {
					// add to middle of list
					Node* node_search = get_byIndex(index);
					n->next = node_search;
					n->prev = node_search->prev;
					node_search->prev->next = n;
					node_search->prev = n;
				}
				count++;
			}
		}
	}
	
	/*
		remove

		The node with the given value should be removed from the list.

		The list may or may not include a node with the given value.
	 */	 
	void remove(T value){
		bool is_validRemovalValue = checkDuplicates(value);
		
		if (is_validRemovalValue == true){
			T item_out;
			//int index_converted = atoi(index_in.c_str());
			int atResult = 0;
			
			for (int i = 0; i < count; i++){
				if (at(i) == value){
					atResult = i;
					break;
				}
			}
				
			if (atResult < 0 || atResult > count - 1)
			{
				// nothing happens
				throw("Removal out of bounds.  Something is wrong with the logic.");
			} else if (atResult == 0 && head != NULL) {
				// remove first item of list
				Node* temp = head; // makes a second pointer to item already pointed to by head
				
				if (count > 1){
					// this should only happen if there is more than one item in the list
					head = head->next; // sets head to point at second item in list
					head->prev = NULL; // sets the new head's prev to NULL
				} else if (count == 1){
					// remove only item left in list
					head = NULL;
					tail = NULL;
				}
				
				item_out = temp->item; // extracts the item so later we can Return what item was removed
				delete temp; // deletes what used to be the head item from memory
				count--;
			} else if (atResult == count - 1 && count > 1) {
				// remove last item of list
				Node* temp = tail; // makes a second pointer to item already pointed to by list
				tail = temp->prev; // sets tail to point at second to last item in list
				tail->next = NULL; // sets the new tail's next to NULL
				item_out = temp->item; // extracts the item so later we can Return what item was removed
				delete temp; // deletes what used to be the tail item from memory
				count--;
			} else {
				// removed from middle of list
				Node* node_search = get_byIndex(atResult);
				node_search->prev->next = node_search->next;
				node_search->next->prev = node_search->prev;
				node_search->next = NULL;
				node_search->prev = NULL;
				item_out = node_search->item; // extracts the item so later we can Return what item was removed
				delete node_search;
				count--;
			}
		}
	}

	/*
		clear

		Remove all nodes from the list.
	 */
	void clear(){
		//cout << "ERROR CATCHER 10" << endl;
		while (head != NULL)
		{
			Node* temp_node = head;
			head = head->next;
			delete temp_node;
		}
		tail = NULL;
		count = 0;
	}

 // PRINTERS
	string print(){
		//cout << "ERROR CATCHER 11" << endl;
		stringstream ss;
		Node* current_node = head;
		int current_index = 0;

		while (current_node != NULL)
		{
			ss << "node " << current_index << ": " << current_node->item << endl;
			current_index++;
			current_node = current_node->next;
		}

		return ss.str();
	}
};
