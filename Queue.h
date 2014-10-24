#pragma once
#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

class Queue
{
	private:
		LinkedList<int> myList;
		
	public:
		Queue();
		~Queue();

		//Part 2--------------------------------------------------------------
		bool push(int car);
		bool pop();
		int front();
		int size();
		
		bool checkDuplicate(int car);
		
};
