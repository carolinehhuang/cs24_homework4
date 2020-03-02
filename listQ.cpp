// listQ.cpp - implements queue as linked list
// NAME(S), DATE

#include "listQ.h"
#include <cstddef>
#include <stack>
#include <queue>

using namespace std;

Queue::Queue() {
	size = 0;
	front = NULL;
	rear = NULL;
}  // IMPLEMENT CONSTRUCTOR

Queue::~Queue() {
	while (front != NULL){
		node* temp = front;
		front = front->next;
		delete temp;
	}
	// IMPLEMENT DESTRUCTOR (delete all the nodes)
}

void Queue::enqueue(int n) {
	node* temp = new node(n);
	if (rear == NULL) {
		front = rear = temp;
		size++;
		return;
	}
	rear->next = temp;
	rear = temp;
	size++;
    // IMPLEMENT (remember to consider special cases)
}

int Queue::dequeue() {
    if (isEmpty())
        throw EmptyQueue();
    node* temp = front;
    int dataNode = front->data;
    front = front->next;
    delete (temp);
    if (front == NULL){
	    rear = NULL;
    }
    size --;
    return dataNode;
    // COMPLETE THIS IMPLEMENTATION (remember to delete node)
    // AND REPLACE THIS RETURN STATEMENT
}

void Queue::clear() {
	if (rear == NULL && front == NULL){
		size = 0;
		return;
	}
	else{
		this->dequeue();
		this->clear();
	}
	// IMPLEMENT (delete all nodes and reset variables)
}

bool Queue::isEmpty() const {
    if((rear == NULL) && (front == NULL)){
	    return true;
    }
    else{
	    return false;
    } // AND REPLACE THIS RETURN STATEMENT
}

int Queue::getSize() const {
    // IMPLEMENT
    return size; // AND REPLACE THIS RETURN STATEMENT
}

void reverseQueueFirstKElements(int k, Queue& queue){
	stack<int> s;
	for( int i = 0; i < k; i++){
		s.push(queue.dequeue());
	}
	while (!s.empty()){
		queue.enqueue(s.top());
		s.pop();
	}
	for (int i = 0; i < queue.getSize()-k; i++) {
		queue.enqueue(queue.dequeue());
	}

}
