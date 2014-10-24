#include "IRDeque.h"

IRDeque::IRDeque(){}
IRDeque::~IRDeque(){}


bool IRDeque::push(int car, int starting_side){
		if (myList.size() == 0){
			myList.clear();
		}
		
		bool was_pushed = true;
		
		if (starting_side == 0){
			myList.insertHead(car);
		} 
		
		//cout << car << " was pushed on " << starting_side << " side. Now size is " << size() << ". front is now " << front(starting_side) << endl;
		
		//cout << myList.print();
		return was_pushed;
}

int IRDeque::size(){
	//cout << myList.size() << endl;
	return myList.size();
}

bool IRDeque::pop(int starting_side){
	bool was_popped = true;
	
	int front_car = myList.at(starting_side);
	
	myList.remove(front_car);
	//cout << front_car << " was popped off " << starting_side << " side. Now size is " << size() << ". front is now " << front(starting_side) << endl;
	
	//cout << myList.print();
	
	return was_popped;
}

int IRDeque::front(int starting_side){
	int Deque_front = -1;
	
	if(myList.size() > 0){
		if (starting_side == 0){
			Deque_front = myList.at(0);
		} else {
			Deque_front = myList.at(size() - 1);
		}
	}
	
	return Deque_front;
}


bool IRDeque::checkDuplicate(int car){
	bool is_duplicate = false;
	
	if (myList.checkDuplicates(car) == true){
		is_duplicate = true;
	}
	
	return is_duplicate;
}
