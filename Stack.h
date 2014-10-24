#pragma once
#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

class Stack
{
	private:
		LinkedList<int> myList;
			
	public:
		Stack();
		~Stack();

		//Part 2--------------------------------------------------------------
		bool push(int car);
		bool pop();
		int top();
		int size();
		
		bool checkDuplicate(int car);
		
};
