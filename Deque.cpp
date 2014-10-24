#include "Deque.h"

Deque::Deque(){}
Deque::~Deque(){}

bool Deque::push(int car, int starting_side){
	if (myList.size() == 0){
		myList.clear();
	}
	
	bool was_pushed = true;
	
	if(starting_side != 0){
		myList.insertTail(car);
	} else {
		myList.insertHead(car);
	}
	
	//cout << car << " was pushed on " << starting_side << " side. Now size is " << size() << ". front is now " << front(starting_side) << endl;
	
	return was_pushed;
}

bool Deque::pop(int starting_side){
	bool was_popped = true;
	
	int front_car = myList.at(starting_side);
	
	myList.remove(front_car);
	//cout << front_car << " was popped off " << starting_side << " side. Now size is " << size() << ". front is now " << front(starting_side) << endl;
	
	return was_popped;
}

int Deque::front(int starting_side){
	int Deque_front = -1;
	
	if(myList.size() > 0){
		if (starting_side == 0){
			Deque_front = myList.at(0);
		} else {
			Deque_front = myList.at(starting_side);
		}
	}
	
	return Deque_front;
}

int Deque::size(){
	//cout << myList.size() << endl;
	return myList.size();
}

bool Deque::checkDuplicate(int car){
	bool is_duplicate = false;
	
	if (myList.checkDuplicates(car) == true){
		is_duplicate = true;
	}
	
	return is_duplicate;
}
