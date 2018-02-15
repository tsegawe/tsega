#include <iostream>
#include "stack.h"
using namespace std;

//create a stack which can store at most m elements
STACK::STACK(int max) : elems(new int[max]), max(elems ? max : 0), top(-1) { };

//deep-copy constructor of stack s
STACK::STACK(const STACK&s) : elems(new int[s.max]), max(elems ? s.max : 0)
{
	for (top = 0; top <= s.max; top++)
		elems[top] = s.elems[top];
}

//get maximum number max
int STACK::size() const
{
	return max;
}

 //get top indicator top
STACK::operator int()const
{
	return elems[top];
}

//get element at location x in the stack
int STACK::operator[](int x)const
{
	return elems[x];
}

//deep-copy assignment of stacks
STACK & STACK::operator=(const STACK&s)
{
	delete elems;
	*(int **)&elems = new int[s.max];
	*(int *)&max = elems ? s.max : 0;
	for (top = 0; top<s.max; top++)
		elems[top] = s.elems[top];
	return *this;
}

//push e into the stack
STACK & STACK::operator<<(int e)
{
	if(top<max)
	// initially was elems[top++] = e;
   		elems[++top] = e;
	return *this;
}

//pop an element to e from the stack
STACK & STACK::operator >> (int &e)
{
	// initially was  e = elems[--top];
	if (top>0)
		e = elems[top--];
	return *this;
}

//print out the stack
void STACK::print()const
{
	for (int i = 0; i<max; i++)
		cout << elems[i] << " ";
}

//destroy the stack
STACK::~STACK()
{
	if(elems){
		delete elems;
		*(int **)&elems=0;
		*(int *)&max=top=0;
	}
}


//check if stack is empty
bool STACK::isEmpty()
{
  if(top < 0)
  {
	return true;
  }
  else
  {
	return false;
  }
}

