// testQ.cpp - tests queue implementation(s) for cs24 lab

// include either "arrayQ.h" or "listQ.h" but not both
//#include "arrayQ.h"
#include "listQ.h"

#include <iostream>
using namespace std;

// utility prints queue state to cout
void printState(Queue &q) {
    cout << "    size = " << q.getSize()
         << ", full = " << (q.isFull()? "true" : "false")
         << ", empty = " << (q.isEmpty()? "true" : "false")
         << endl;
}

// main creates and uses a queue
int main() {
    Queue q;
    cout << "beginning state" << endl;
    printState(q);

  try {

    // enqueue until almost full (8 values out of 10 capacity)
    cout << "enqueue first 8 multiples of 7" << endl;
    for (int i=1; i<=8; i++)
        q.enqueue(i * 7);
    printState(q);

    // dequeue two
    cout << "dequeue two items: ";
    cout << q.dequeue() << " ";
    cout << q.dequeue() << endl;
    printState(q);
  
    // enqueue 4 more - should make queue full
    cout << "enqueue next 4 multiples of 7" << endl;
    for (int i=9; i<=12; i++)
        q.enqueue(i * 7);
    printState(q);

    // dequeue and print until empty
    cout << "dequeue all items: ";
    while (!q.isEmpty())
        cout << q.dequeue() << " ";
    cout << endl;
    printState(q);

    // enqueue two more then clear
    cout << "enqueue 5, then 10" << endl;
    q.enqueue(5);
    q.enqueue(10);
    printState(q);
    cout << "clear" << endl;
    q.clear();
    printState(q);

    return 0;
  }
  catch(FullQueue e) {
    cerr << "exception: full queue" << endl;
  }
  catch(EmptyQueue e) {
    cerr << "exception: empty queue" << endl;
  }
    return 1; // because exception thrown
}

