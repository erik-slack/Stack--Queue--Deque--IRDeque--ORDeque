#pragma once
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Deque.h"
using namespace std;

class ORDeque : public Deque
{
	private:
		LinkedList<int> myList;
		
	public:
		ORDeque();
		~ORDeque();

		//Part 2--------------------------------------------------------------
		bool push(int car, int starting_side);
		bool pop(int starting_side);
		int front(int starting_side);
		int size();
		
		bool checkDuplicate(int car);
};

