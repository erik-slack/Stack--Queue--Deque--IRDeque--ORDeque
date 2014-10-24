#pragma once
#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

class Deque
{
	private:
		LinkedList<int> myList;
		
	public:
		Deque();
		~Deque();

		//Part 2--------------------------------------------------------------
		bool push(int car, int starting_side);
		bool pop(int starting_side);
		int front(int starting_side);
		int size();
		
		bool checkDuplicate(int car);
		
};

