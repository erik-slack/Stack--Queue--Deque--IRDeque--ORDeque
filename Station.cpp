#include "Station.h"

using namespace std;

	Station::Station(){}
	Station::~Station(){}

	//Part 1--------------------------------------------------------------
	/**
	 * Let another car arrive at the station and become the current car.
	 * Do not allow a new car to arrive if any of the following conditions apply:
	 * 1.	There is already a current car
	 * 2.	The new car's ID already exists in any structure
	 * 3.	The new car's ID is negative
	 *
	 * @param car the ID of the car arriving at the station
	 * @return true if the car successfully arrived; false otherwise
	 */
	bool Station::addToStation(int car){
		bool car_added = true;
		//cout << "car in = " << car << endl;
		//cout << "current car = " << current_car << endl;
		
		if (current_car != -1){
			car_added = false;
		}
		
		if (car < 0){
			
			car_added = false;
		}
		
		if (myStack.checkDuplicate(car) == true || myQueue.checkDuplicate(car) == true || myDeque.checkDuplicate(car) == true || myIRDeque.checkDuplicate(car) == true || myORDeque.checkDuplicate(car) == true){
			car_added = false;
		}
		
		if (car_added == true){
			
			current_car = car;
			
		}
		
		return car_added;
	}

	/**
	 * Returns the ID of the current car.
	 * Return -1 if there is no current car.
	 *
	 * @return the ID of the current car; -1 if there is no current car
	 */
	int Station::showCurrentCar(){
		return current_car;
	}

	/**
	 * Removes the current car from the station.
	 * Does nothing if there is no current car.
	 *
	 * @return true if the current car successfully left; false otherwise
	 */
	bool Station::removeFromStation(){
		bool car_removed = true;
		
		if (current_car != -1){
			current_car = -1;
		} else {
			car_removed = false;
		}
		
		return car_removed;
	}

	//Part 2--------------------------------------------------------------
	/**
	 * Adds the current car to the stack.  After this operation, there should be no current car.
	 * Does nothing if there is no current car or if the stack is already full.
	 *
	 * @return true if the car is successfully added to the stack; false otherwise
	 */
	bool Station::addToStack(){
		bool added_toStack = false;
		
		if(current_car > -1){
			myStack.push(current_car);
			current_car = -1;
			added_toStack = true;
		}
		
		return added_toStack;
	}

	/**
	 * Removes the first car in the stack and makes it the current car.
	 * Does nothing if there is already a current car or if the stack already empty.
	 *
	 * @return true if the car is successfully removed from the stack; false otherwise
	 */
	bool Station::removeFromStack(){
		bool removed_fromStack = false;
		
		if(current_car == -1){
			current_car = myStack.top();
			myStack.pop();
			removed_fromStack = true;
		}
		
		return removed_fromStack;
	}

	/**
	 * Returns the ID of the first car in the stack.
	 *
	 * @return the ID of the first car in the stack; -1 if the stack is empty
	 */
	int Station::showTopOfStack(){
		int stack_top = -1;
		
		if(myStack.size() > 0){
			//cout << myStack.top() << endl;
			stack_top = myStack.top();
		}
		
		//cout << "stack_top = " << stack_top << ". Size = " << showSizeOfStack() << endl;
		return stack_top;
	}

	/**
	 * Returns the number of cars in the stack.
	 *
	 * @return the number of cars in the stack
	 */
	int Station::showSizeOfStack(){
		return myStack.size();
	}

	//Part 3--------------------------------------------------------------
	/**
	 * Adds the current car to the queue.  After this operation, there should be no current car.
	 * Does nothing if there is no current car or if the queue is already full.
	 *
	 * @return true if the car is successfully added to the queue; false otherwise
	 */
	bool Station::addToQueue(){
		bool added_toQueue = false;
		
		if(current_car > -1){
			myQueue.push(current_car);
			current_car = -1;
			added_toQueue = true;
		}
		
		return added_toQueue;
	}

	/**
	 * Removes the first car in the queue and makes it the current car.
	 * Does nothing if there is already a current car or if the queue already empty.
	 *
	 * @return true if the car is successfully removed from the queue; false otherwise
	 */
	bool Station::removeFromQueue(){
		bool removed_fromQueue = false;
		
		if(current_car == -1){
			current_car = myQueue.front();
			myQueue.pop();
			removed_fromQueue = true;
		}
		
		return removed_fromQueue;
	}

	/**
	 * Returns the ID of the first car in the queue.
	 *
	 * @return the ID of the first car in the queue; -1 if the queue is empty
	 */
	int Station::showTopOfQueue(){
		int queue_front = -1;
		
		if(myQueue.size() > 0){
			queue_front = myQueue.front();
		}
		
		//cout << "queue_front = " << queue_front << ". Size = " << showSizeOfQueue() << endl;
		return queue_front;
	}

	/**
	 * Returns the number of cars in the queue.
	 *
	 * @return the number of cars in the queue
	 */
	int Station::showSizeOfQueue(){
		return myQueue.size();
	}

	//Part 4--------------------------------------------------------------
	/**
	 * Adds the current car to the deque on the left side.  After this operation, there should be no current car.
	 * Does nothing if there is no current car or if the deque is already full.
	 *
	 * @return true if the car is successfully added to the deque; false otherwise
	 */
	bool Station::addToDequeLeft(){
		bool added_toDeqLeft = false;
		
		if(current_car > -1){
			myDeque.push(current_car, 0);
			current_car = -1;
			added_toDeqLeft = true;
		}
		
		return added_toDeqLeft;
	}

	/**
	 * Adds the current car to the deque on the right side.  After this operation, there should be no current car.
	 * Does nothing if there is no current car or if the deque is already full.
	 *
	 * @return true if the car is successfully added to the deque; false otherwise
	 */
	bool Station::addToDequeRight(){
		bool added_toDeqRight = false;
		
		if(current_car > -1){
			myDeque.push(current_car, showSizeOfDeque());
			current_car = -1;
			added_toDeqRight = true;
		}
		
		return added_toDeqRight;
	}

	/**
	 * Removes the leftmost car in the deque and makes it the current car.
	 * Does nothing if there is already a current car or if the deque already empty.
	 *
	 * @return true if the car is successfully removed from the deque; false otherwise
	 */
	bool Station::removeFromDequeLeft(){
		bool removed_fromDeqLeft = false;
		
		if(current_car == -1){
			current_car = myDeque.front(0);
			myDeque.pop(0);
			removed_fromDeqLeft = true;
		}
		
		return removed_fromDeqLeft;
	}

	/**
	 * Removes the rightmost car in the deque and makes it the current car.
	 * Does nothing if there is already a current car or if the deque already empty.
	 *
	 * @return true if the car is successfully removed from the deque; false otherwise
	 */
	bool Station::removeFromDequeRight(){
		bool removed_fromDeqRight = false;
		
		if(current_car == -1){
			current_car = myDeque.front(showSizeOfDeque() - 1);
			myDeque.pop(showSizeOfDeque() - 1);
			removed_fromDeqRight = true;
		}
		
		return removed_fromDeqRight;
	}

	/**
	 * Returns the ID of the leftmost car in the deque.
	 *
	 * @return the ID of the leftmost car in the deque; -1 if the deque is empty
	 */
	int Station::showTopOfDequeLeft(){
		return myDeque.front(0);
	}

	/**
	 * Returns the ID of the rightmost car in the deque.
	 *
	 * @return the ID of the rightmost car in the deque; -1 if the deque is empty
	 */
	int Station::showTopOfDequeRight(){
		return myDeque.front(showSizeOfDeque() - 1);
	}

	/**
	 * Returns the number of cars in the deque.
	 *
	 * @return the number of cars in the deque
	 */
	int Station::showSizeOfDeque(){
		return myDeque.size();
	}

	//EXTRA CREDIT
	//Input-Restricted Deque----------------------------------------------
	/**
	 * Adds the current car to the IRDeque on the left side.  After this operation, there should be no current car.
	 * Does nothing if there is no current car or if the IRDeque is already full.
	 *
	 * @return true if the car is successfully added to the IRDeque; false otherwise
	 */
	bool Station::addToIRDequeLeft(){
		bool added_toDeqLeft = false;
		
		if(current_car > -1){
			myIRDeque.push(current_car, 0);
			current_car = -1;
			added_toDeqLeft = true;
		}
		
		return added_toDeqLeft;
	}

	/**
	 * Removes the leftmost car in the IRDeque and makes it the current car.
	 * Does nothing if there is already a current car or if the IRDeque already empty.
	 *
	 * @return true if the car is successfully removed from the IRDeque; false otherwise
	 */
	bool Station::removeFromIRDequeLeft(){
		bool removed_fromDeqLeft = false;
		
		if(current_car == -1){
			current_car = myIRDeque.front(0);
			myIRDeque.pop(0);
			removed_fromDeqLeft = true;
		}
		
		return removed_fromDeqLeft;
	}

	/**
	 * Removes the rightmost car in the IRDeque and makes it the current car.
	 * Does nothing if there is already a current car or if the IRDeque already empty.
	 *
	 * @return true if the car is successfully removed from the IRDeque; false otherwise
	 */
	bool Station::removeFromIRDequeRight(){
		bool removed_fromDeqRight = false;
		
		if(current_car == -1){
			current_car = myIRDeque.front(showSizeOfIRDeque() - 1);
			myIRDeque.pop(showSizeOfIRDeque() - 1);
			removed_fromDeqRight = true;
		}
		
		return removed_fromDeqRight;
	}

	/**
	 * Returns the ID of the leftmost car in the IRDeque.
	 *
	 * @return the ID of the leftmost car in the IRDeque; -1 if the IRDeque is empty
	 */
	int Station::showTopOfIRDequeLeft(){
		return myIRDeque.front(0);
	}

	/**
	 * Returns the ID of the rightmost car in the IRDeque.
	 *
	 * @return the ID of the rightmost car in the IRDeque; -1 if the IRDeque is empty
	 */
	int Station::showTopOfIRDequeRight(){
		return myIRDeque.front(showSizeOfIRDeque() - 1);
	}

	/**
	 * Returns the number of cars in the IRDeque.
	 *
	 * @return the number of cars in the IRDeque
	 */
	int Station::showSizeOfIRDeque(){
		return myIRDeque.size();
	}

	//Output-Restricted Deque---------------------------------------------
	/**
	 * Adds the current car to the ORDeque on the left side.  After this operation, there should be no current car.
	 * Does nothing if there is no current car or if the ORDeque is already full.
	 *
	 * @return true if the car is successfully added to the ORDeque; false otherwise
	 */
	bool Station::addToORDequeLeft(){
		bool added_toDeqLeft = false;
		
		if(current_car > -1){
			myORDeque.push(current_car, 0);
			current_car = -1;
			added_toDeqLeft = true;
		}
		
		return added_toDeqLeft;
	}

	/**
	 * Adds the current car to the ORDeque on the right side.  After this operation, there should be no current car.
	 * Does nothing if there is no current car or if the ORDeque is already full.
	 *
	 * @return true if the car is successfully added to the ORDeque; false otherwise
	 */
	bool Station::addToORDequeRight(){
		bool added_toDeqRight = false;
		
		if(current_car > -1){
			myORDeque.push(current_car, showSizeOfORDeque());
			current_car = -1;
			added_toDeqRight = true;
		}
		
		return added_toDeqRight;
	}

	/**
	 * Removes the leftmost car in the ORDeque and makes it the current car.
	 * Does nothing if there is already a current car or if the ORDeque already empty.
	 *
	 * @return true if the car is successfully removed from the ORDeque; false otherwise
	 */
	bool Station::removeFromORDequeLeft(){
		bool removed_fromDeqLeft = false;
		
		if(current_car == -1){
			current_car = myORDeque.front(0);
			myORDeque.pop(0);
			removed_fromDeqLeft = true;
		}
		
		return removed_fromDeqLeft;
	}

	/**
	 * Returns the ID of the leftmost car in the ORDeque.
	 *
	 * @return the ID of the leftmost car in the ORDeque; -1 if the ORDeque is empty
	 */
	int Station::showTopOfORDequeLeft(){
		return myORDeque.front(0);
	}

	/**
	 * Returns the number of cars in the ORDeque.
	 *
	 * @return the number of cars in the ORDeque
	 */
	int Station::showSizeOfORDeque(){
		return myORDeque.size();
	}
