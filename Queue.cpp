#include "Queue.h"

Queue::Queue(){}
Queue::~Queue(){}

bool Queue::push(int car){
	if (myList.size() == 0){
		myList.clear();
	}
	
	bool was_pushed = true;
	
	myList.insertTail(car);
	//cout << car << " was pushed. Now size is " << size()<< ". front is now " << front() << endl;
	
	return was_pushed;
}

bool Queue::pop(){
	bool was_popped = true;
	
	int front_car = myList.at(0);
	
	myList.remove(front_car);
	//cout << front_car << " was popped. Now size is " << size() << ". front is now " << front() << endl;
	
	return was_popped;
}

int Queue::front(){
	int Queue_front = -1;
	
	if(myList.size() > 0){
		Queue_front = myList.at(0);
	}
	
	return Queue_front;
}

int Queue::size(){
	//cout << myList.size() << endl;
	return myList.size();
}

bool Queue::checkDuplicate(int car){
	bool is_duplicate = false;
	
	if (myList.checkDuplicates(car) == true){
		is_duplicate = true;
	}
	
	return is_duplicate;
}
