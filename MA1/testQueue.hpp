// define default capacity of the queue
#define SIZE 10

#include <iostream>
#include <cstdlib>
using namespace std;


// Class for queue
class queue
{
private:
	int* arr;		// array to store queue elements
	int capacity;	// maximum capacity of the queue
	int front;		// front points to front element in the queue (if any)
	int rear;		// rear points to last element in the queue
	int count;		// current size of the queue

public:
	queue(int size = SIZE); 	// constructor
	~queue();   				// destructor

	int dequeue();
	int enqueue(int x);
	int peek();
	int size();
	bool isEmpty();
	bool isFull();

    // getters
    int getCount(void) {
        return count;
    }

    // test functions
    void testSize(void);
    void testIsEmpty(void);
    void testIsFull(void);
    void testDequeueEmpty(void);
    void testDequeueNotEmpty(void);
    void testEnqueueFull(void);
    void testEnqueueNotFull(void);
    void testPeekEmpty(void);
    void testPeekNotEmpty(void);
};
