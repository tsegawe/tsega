/*************QUEUE IMPLEMENTATION FIRST IN FIRST OUT*************************/

//#include "stdafx.h"
#include <iostream>
#include <iomanip>

#include "queue.h"

using namespace std;

/*Constructor*/
QUEUE::QUEUE(int m) : elems(new int[m]), max(elems ? m : 0), front(0), rear(-1) { }

//Lists to initialize fields
QUEUE::QUEUE(const QUEUE &q) : elems(new int[q.max]), max(elems ? q.max : 0),front(-1),	rear(-1)
{
	//constructing a queue by copying the given queue q
	if (elems == 0)
		return;
	for (int j = 0; j<q.max; ++j)
		elems[j] = q.elems[j];
	front = q.front;
	rear = q.rear;

}

//if((rear+1)%max == front ) queue is full
//if(front == 0 && rear == -1) queue is empty

/*Destructor*/
QUEUE::~QUEUE()
{
	//Destroying a queue
	if (elems != 0)
		delete[] elems;
}

/*Get the elements in the queue*/
QUEUE::operator int() const {
	return (rear - front + max) % max;

}

/*Enqueue e into the queue*/
QUEUE& QUEUE::operator<<(int e) {

   	if ((front == 0 && rear == max - 1) || (front>0 && rear == front - 1))
		//if ((rear + 1)% max == front)
		//(rear==max)
	{
		cout << "Overflow! The Queue is too full to push element " << e << endl;

	}
	else {
		if (rear == max - 1 && front > 0) {
			rear = 0;
			elems[rear] = e;
		}

		else {
			if ((front == 0 && rear == -1) || (rear != front - 1))
				elems[++rear] = e;
				//rear = (rear + 1) % max;
				cout<<"Front item is "<<elems[front]<<endl;
				cout<<"Rear item is "<<elems[rear]<<endl;
		}
	}
	return *this;

}

/*Dequeue e into the queue*/
QUEUE& QUEUE::operator >> (int& e) {
	//front == 0 &&
	if (rear == -1)
	{
		cout <<"Underflow: Queue is empty!\n";
		//getchar();
		//exit(0);
	}

	else if (front == rear) {
		e = elems[front];
	   	rear = -1;
		front = 0;
	}
	else
	{
		e = elems[front];
		front = (front + 1) % max;
		cout<<"Front item is "<<elems[front]<<endl;
		cout<<"Rear item is "<<elems[rear]<<endl;

	}
	return *this;

}

/*Function Deep-copy assignment of Queues*/
QUEUE& QUEUE::operator=(const QUEUE&q)
{
	if (&q != this) //avoid self-assignment
	{
		front = q.front;
		rear = q.rear;
		for (front = 0; front < q.max; front++)
		{
			elems[front] = q.elems[front];   //copy the array into object
		}
	}
	return *this;
}

/*Print out the Queue*/
void  QUEUE::print() const {

	if (front == 0 && rear == -1)
	{
		cout<<"Underflow: Queue is empty!\n";
		//getchar();
		//exit(0);
	}

	else
	{
		cout << "~~~~~~\n";
		//for (int i = front; i <= rear; i++){
		for (int i = rear; i >= front; i--) {
			cout << "" << elems[i] << "  ";
		}
	}

	cout << endl;
}

