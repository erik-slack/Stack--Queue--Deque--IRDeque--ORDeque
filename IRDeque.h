#pragma once
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Deque.h"
using namespace std;

class IRDeque : public Deque
{
	private:
		LinkedList<int> myList;
		
	public:
		IRDeque();
		~IRDeque();

		bool push(int car, int starting_side);
		bool pop(int starting_side);
		int front(int starting_side);
		int size();
		
		bool checkDuplicate(int car);
};

