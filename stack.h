class STACK{
    int  *const  elems;	//memory allocated to store elements
    const  int   max;	//maximum number of elements the stack can contain
    int   top;				//top indicator or number of elements in current stack
public:
STACK(int m);		//create a stack which can store at most m elements
STACK(const STACK&s); 			//deep-copy constructor of stack s
virtual int size() const;			//get maximum number max
virtual operator int () const;			//get top indicator top
virtual int operator[] (int x) const;	//get element at location x in the stack
virtual STACK& operator<<(int e); 	//push e into the stack
virtual STACK& operator>>(int &e);	//pop an element to e from the stack
virtual STACK& operator=(const STACK&s); //deep-copy assignment of stacks
virtual void print() const;			//print out the stack
virtual ~STACK();					//destroy the stack


//user defined methods
virtual bool isEmpty();			//check if stack is empty
};

