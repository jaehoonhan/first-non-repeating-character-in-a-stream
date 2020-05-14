#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;
// Class for queue using template
template <class X>
class queue 
{
	X *arr; 		// array to store queue elements
	int capacity;   // maximum capacity of the queue
	int front;  	// front points to front element in the queue (if any)
	int rear;   	// rear points to last element in the queue
	int count;  	// current size of the queue

public:
	queue(int size=10);		// constructor

	void dequeue();
	void enqueue(X x);
	X peek();
	int size();
	bool isEmpty();
	bool isFull();
};

template <class X>
queue<X>::queue(int size)
{
    arr = new X[size];
    capacity = 10;
    front = 0;
    rear = -1;
    count = 0;
}

// function to remove front element from the queue
template <class X>
void queue<X>::dequeue()
{
    // check for queue underflow
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    front = (front + 1) % capacity;
    count--;
}

// function to add an item to the queue
template <class X>
void queue<X>::enqueue(X item)
{
    // check for queue overflow
    if (isFull())
    {
        cout << "OverFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    //cout << "Inserting " << item << '\n';

    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}

// function to return front element in the queue
template <class X>
X queue<X>::peek()
{
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}

// function to return the size of the queue
template <class X>
int queue<X>::size()
{
    return count;
}

// function to check if the queue is empty or not
template <class X>
bool queue<X>::isEmpty()
{
    return (size() == 0);
}

// function to check if the queue is full or not
template <class X>
bool queue<X>::isFull()
{
    return (size() == capacity);
}

#endif
