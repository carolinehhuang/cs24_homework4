// listQ.h - queue class for CS 24 lab, list version
//           stores int - no max capacity
//           value semantics note: not safe to copy

#ifndef QUEUE_H
#define QUEUE_H

// specialized exception classes
class EmptyQueue { };
class FullQueue { };

class Queue {

public:
    Queue();             // constructor creates empty queue
    ~Queue();            // destructor necessary to delete nodes

    void enqueue(int n); // adds n to rear;
        // does not get full, so no exception thrown

    int dequeue();       // removes and returns front;
        // throws EmptyQueue if empty

    void clear();        // deletes all nodes
    bool isEmpty() const;
    bool isFull() const { return false; } // done
    int getSize() const; // returns number of items in the queue

private:
    struct node {
        int data;
        node *next;
        node(int n) : data(n), next(0) {} // node constructor
    };
    node *front, *rear;  // pointers to keep track of front and rear
    int size;            // number of items in the queue
};

void reverseQueueFirstKElements(int k, Queue& queue);

#endif

