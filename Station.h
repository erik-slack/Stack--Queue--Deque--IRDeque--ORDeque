#pragma once
#include <iostream>
#include <string>
#include "StationInterfaceExtra.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"
#include "IRDeque.h"
#include "ORDeque.h"
using namespace std;

class Station : public StationInterfaceExtra
{
	private:
		Stack myStack;
		Queue myQueue;
		Deque myDeque;
		IRDeque myIRDeque;
		ORDeque myORDeque;
		
		int current_car = -1;
		
	
	public:
		Station();
		~Station();

		//Part 1--------------------------------------------------------------
		bool addToStation(int car);
		int showCurrentCar();
		bool removeFromStation();

		//Part 2--------------------------------------------------------------
		bool addToStack();
		bool removeFromStack();
		int showTopOfStack();
		int showSizeOfStack();

		//Part 3--------------------------------------------------------------
		bool addToQueue();
		bool removeFromQueue();
		int showTopOfQueue();
		int showSizeOfQueue();

		//Part 4--------------------------------------------------------------
		bool addToDequeLeft();
		bool addToDequeRight();
		bool removeFromDequeLeft();
		bool removeFromDequeRight();
		int showTopOfDequeLeft();
		int showTopOfDequeRight();
		int showSizeOfDeque();
		
		//Extra Credit
		//Input-Restricted Deque----------------------------------------------
		bool addToIRDequeLeft();
		bool removeFromIRDequeLeft();
		bool removeFromIRDequeRight();
		int showTopOfIRDequeLeft();
		int showTopOfIRDequeRight();
		int showSizeOfIRDeque();

		//Output-Restricted Deque---------------------------------------------
		bool addToORDequeLeft();
		bool addToORDequeRight();
		bool removeFromORDequeLeft();
		int showTopOfORDequeLeft();
		int showSizeOfORDeque();
};
