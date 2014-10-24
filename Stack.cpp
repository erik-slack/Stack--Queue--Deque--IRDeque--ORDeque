#include "Stack.h"

Stack::Stack(){}
Stack::~Stack(){}

bool Stack::push(int car){
	if (myList.size() == 0){
		myList.clear();
	}
	
	bool was_pushed = true;
	
	myList.insertTail(car);
	//cout << car << " was pushed. Now size is " << size()<< ". Top is now " << top() << endl;
	
	return was_pushed;
}

bool Stack::pop(){
	bool was_popped = true;
	
	int top_car = myList.at(size() - 1);
	
	myList.remove(top_car);
	//cout << top_car << " was popped. Now size is " << size()<< ". Top is now " << top() << endl;
	
	return was_popped;
}

int Stack::top(){
	int stack_top = -1;
	
	if(myList.size() > 0){
		stack_top = myList.at(size() - 1);
	}
	
	return stack_top;
}

int Stack::size(){
	//cout << myList.size() << endl;
	return myList.size();
}

bool Stack::checkDuplicate(int car){
	bool is_duplicate = false;
	
	if (myList.checkDuplicates(car) == true){
		is_duplicate = true;
	}
	
	return is_duplicate;
}
