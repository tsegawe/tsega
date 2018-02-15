#include <iostream>
#include "stack.cpp";
#include "queue.cpp";
using namespace std;
int main(int argc, char* argv[])
{
	cout << "OOP            :  Project Laboratory Report Three" << endl;
	cout << "Name           :  Tsega Weldu Araya" << endl;
	cout << "Student ID.    :  I201721034" << endl;
	cout << "Acadamic Year  :  2017/2018" << endl;
	cout << "************************************" << endl;

	cout << endl;

	char choice = 's';
	while (choice == 's')
	{
		cout << "Please choose from those Options :- " << endl;
		cout << "s:-"" For Stack Operations " << endl;
		cout << "q:-"" For Queue Operations " << endl;

		char menu;
		cin >> menu;
		switch (menu)
		{
		case 's':
		{

			cout << "*****Stack Operation*******" << endl;

			cout << endl;

			cout << "Stack declared" << endl;
			int x; //declare the element variable for the stack
			int size; //declare the size of the stack
			cout << "Enter desired size of stack" << endl;
			cin >> size;  //enter size of the  stack
			STACK s1(size);//create the object s1 with size parameter
			STACK s2(s1);
			cout << "**push values  into the stack**" << endl;
			for (int i = 0; i < size; i++) {
				cin >> x;
				s1.operator <<(x);
				//cout << "the top" << s1.operator int() << endl;

			}

			char choice = 'y';
			while (choice == 'y')
			{
				cout << "Please choose various Options : " << endl;
				cout << "1-Print the Stack" << endl;
				cout << "2-Perform Deep Copy Operations " << endl;
				cout << "3-Pop elements  From the Stack " << endl;
				cout << "4-show the current size of the stack " << endl;
				cout << "5-Print out the top element of the stack" << endl;
				cout << "6-Search Values at Positon e in the Stack" << endl;


				int option;
				cin >> option;
				switch (option)
				{
				case 1:cout << "The print out of the First Stack" << endl;
					s1.print();

					break;
				case 2:cout << "***Copy Operation***" << endl;

					cout << "copy constructor size : " << s2.size() << endl;
					s2 = s1;

					cout << "Printing New Stack" << endl;
					s2.print(); //print copy deep constructor
					break;
				case 3:cout << "Printing the POP: " << endl;
					cout << "**pop an element to e from the stack**" << endl;
					int m;//m is varible get elemnts in stack
					int *z; //z is varible for access value in the elemnt stack
					cout << "top is now " << s1.operator int() << endl;

					for (int i = size; i > 0; --i) {
						m = s1.operator int();

						cout << " element " << s1.operator >> (m) << " pop now" << "   ";
						z = *(int**)&m;      //using type casting for get value from stack

						cout << "  " << "pop value" << "  " << z << endl;
					}

					cout << "the size after pop" << " " << s1.size() << endl;
					//cout << "the top  after pop" << "  " << s1.operator int() << endl;
					s1.print();


					break;
				case 4:cout << "the size of the Stack is : " << size << endl;
					break;
				case 5:cout << "The top of the stack is:" << s1.operator int() << endl;

					break;

				case 6:cout << "Enter Stack Index to return Values :" << endl;

					int ser;//serch  number
					cout << "enter value for search" << endl;
					cin >> ser;
					if (ser <= size - 1) {
						cout << "the searched number is " << s1.operator [](ser) << endl;
					}
					else
						cout << "ERROR, no value at requested index" << endl;

				}

				cout << endl;
				cout << " do you want to Perform another Stack Operation ?" << endl;
				cout << " Y-yes, or N-No, or m for main menu and q for queue" << endl;
				cin >> choice;

			}
			if (choice == 'n')
			{
				menu == 'q';
			}
		}

        case 'q': //Executing queue operation;
		{

			int queueSize;
			cout << "enter Size of Queue" << endl;
			cin >> queueSize;
			int option = 0;
			QUEUE queue1(queueSize);
			int dequeue = 0;
			while (option != 5)

			{
				cout << "******PERFORM QUEUE OPERATIONS*******" << endl;
				cout << "1. ENQUEUE Element Into the Queue \n";
				cout << "2. DEQUEUE Element from the queue  \n";
				cout << "3. Print the Element of the Queue  \n";
				cout << "4. PERFORM COPY FUNCTION \n";
				cout << "5. EXIT  APPLICATION  \n" << endl;

				int option;
				cin >> option;
				switch (option)
				{
				case 1: //enqueue elements into queue
					int y; //initialize new element
					cout << "Enter Element to enqueue: \n";
					cin >> y;
					queue1 << y;
					queue1.print();
					cin.get();
					break;

				case 2://dequeue element from
					queue1 >> dequeue;
					cout << "Dequeueing " << dequeue << endl;
					cout << "Elements  of Queue 1 are now: \n";
					queue1.print();
					cin.get();
					break;
				case 3:
					cout << "Contents of Queue 1 are: \n";
					queue1.print();
					cin.get();
					break;
				case 4:cout << "Performing copy operations :  Queue 1 to Queue 2:\n";
					QUEUE queue2(queue1);   //deep copy a queue
					queue2.print();

					cin.get();
					break;

				}//end switch
				cin.get();

			}
		}
		}

	}


	return 0;
}
