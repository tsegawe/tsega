class QUEUE{
    int  *const  elems;	//memory allocated to store elements
    const  int   max;	//maximum number of elements that the queue can contain
    int   front, rear;		//front and rear of the queue
public:
QUEUE(int m);		//create a queue which can store at most m elements
QUEUE(const QUEUE&q); 			//deep-copy constructor of queue q
virtual operator int ( ) const;			//get number of elements in queue
virtual QUEUE& operator<<(int e); 	//enqueue e into queue
virtual QUEUE& operator>>(int &e);	//dequeue e from queue
virtual QUEUE& operator=(const QUEUE&s); //deep-copy assignment of queue
virtual void print( ) const;			//print the queue
virtual ~QUEUE( );					//destroy the queue
};

