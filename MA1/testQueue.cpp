#include "testQueue.hpp"

// Constructor to initialize queue
queue::queue(int size)
{
	arr = new int[size];
	capacity = size;
	front = 0;
	rear = -1;
	count = 0;
}

// Destructor to free memory allocated to the queue
queue::~queue()
{
	delete arr; // you are not required to test this function;
	            // however, are there issues with it?
}

// Utility function to remove front element from the queue
int queue::dequeue()
{
	// check for queue underflow
	if (isEmpty())
	{
		cout << "UnderFlow\nProcess Stopped\n";
		return 0;
	}

	cout << "Removing " << arr[front] << '\n';

	front = (front + 1) % capacity;
	count--;
    return 1;
}

// Utility function to add an item to the queue
int queue::enqueue(int item)
{
	// check for queue overflow
	if (isFull())
	{
		cout << "OverFlow\nProcess Stopped\n";
		return 0;
	}

	cout << "Inserting " << item << "\n";

	rear = (rear + 1);
	arr[rear] = item;
	count++;
    return 1;
}

// Utility function to return front element in the queue
int queue::peek()
{
	if (isEmpty())
	{
		cout << "UnderFlow\nProcess Stopped\n";
		// this is a windows specific command
        //system("pause");
		return 0;
	}
	return arr[front];
}

// Utility function to return the size of the queue
int queue::size()
{
	return count;
}

// Utility function to check if the queue is empty or not
bool queue::isEmpty()
{
	return (size() == 0);
}

// Utility function to check if the queue is full or not
bool queue::isFull()
{
	return (size() == capacity);
}

/*  Test ID: queue size check - QSC
    Unit: queue::size ()
    Description: test to determine if queue::size () returns the size of the queue
    Test steps:
        1. Construct an empty queue object
        2. Invoke queue::size ()
        3. Conditionally evaluate the value returned by queue::size ()
    Test data: size = 0
    Precondition: queue object has size of 0
    Postcondition: queue object still has size of 0
    Expected result: queue has size of 0; 0 is returned
    Actual result: queue has size of 0; 0 is returned
    Status: passed
*/
void queue::testSize(void) {
    // construct empty queue
    queue testQueue(0);
    if (testQueue.size() == 0)
        cout << "size() status: Passed\n";
    else
        cout << "size() status: Failed\n";
    
}

/*  Test ID: Empty queue check - EQC
    Unit: queue::isEmpty ()
    Description: test to determine if queue::isEmpty () returns 1 if a queue object is empty
    Test steps:
        1. Construct an empty queue object
        2. Invoke queue::isEmpty ()
        3. Conditionally evaluate the value returned by queue::isEmpty ()
    Test data: size = 0
    Precondition: queue object is empty
    Postcondition: queue object is still empty
    Expected result: queue is empty; 1 is returned
    Actual result: queue is empty; 1 is returned
    Status: passed
*/
void queue::testIsEmpty(void) {
    // construct empty queue
    queue testQueue(0);
    if (testQueue.isEmpty()) // invoke isEmpty and conditionally evaluate
        cout << "isEmpty() Status: Passed\n";
    else
        cout << "isEmpty() Status: Failed\n";
}

/*  Test ID: Full queue check - FQC
    Unit: queue::isFull ()
    Description: test to determine if queue::isFull () returns 1 if a queue object is full
    Test steps:
        1. Construct an empty queue object with size of 1
        2. Add an integer to the queue object
        2. Invoke queue::isFull ()
        3. Conditionally evaluate the value returned by queue::isFull ()
    Test data: size = 1, value enqueued = 1
    Precondition: queue object is full
    Postcondition: queue object is still full
    Expected result: queue is full; 1 is returned
    Actual result: queue is full; 1 is returned
    Status: passed
*/
void queue::testIsFull(void) {
    queue testQueue(1); // construct empty queue object with size of 1
    testQueue.enqueue(1); // enqueue an integer to the queue object

    if (testQueue.isFull())
        cout << "isFull() Status: Passed\n";
    else
        cout << "isFull() Status: Failed\n";
} 

/*  Test ID: Dequeue empty queue check - DEQC
    Unit: queue::dequeue ()
    Description: test to determine if queue::dequeue () exits without decrementing count if a queue object is empty
    Test steps:
        1. Construct an empty queue object
        2. Invoke queue::dequeue ()
        3. Conditionally evaluate the value of count after queue::dequeue ()
    Test data: size = 1
    Precondition: queue object is empty; count = 0
    Postcondition: queue object is still empty; count = 0 still
    Expected result: dequeue() exits; count = 0
    Actual result: dequeue() exits; count = 0
    Status: passed
*/
void queue::testDequeueEmpty(void) {
    queue testQueue(1); // construct empty queue
    testQueue.dequeue(); // invoke dequeue()
    
    if (testQueue.getCount() == 0)
        cout << "Empty dequeue() Status: Passed\n";
    else
        cout << "Empty dequeue() Status: Failed\n";
}


/*  Test ID: Dequeue non-empty queue check - DNEQC
    Unit: queue::dequeue ()
    Description: test to determine if queue::dequeue () decrements count if a queue object is not empty
    Test steps:
        1. Construct an empty queue object
        2. Enqueue an item into the queue object
        3. Invoke queue::dequeue ()
        4. Conditionally evaluate the value of count after queue::dequeue ()
    Test data: size = 1; item enqueued = 1
    Precondition: queue object has one item; count = 1
    Postcondition: queue object no items; count = 0
    Expected result: dequeue() dequeues item; count = 0
    Actual result: dequeue() dequeues item; count = 0
    Status: passed
*/
void queue::testDequeueNotEmpty(void) {
    queue testQueue(1); // construct an empty queue object
    testQueue.enqueue(1); // enqueue

    testQueue.dequeue(); // invoke dequeue
    // conditionally evaluate the value of count after queue::dequeue ()
    if (testQueue.getCount() == 0)
        cout << "Non-empty dequeue() Status: Passed\n";
    else  
        cout << "Non-empty dequeue() Status: Failed\n";
}

/*  Test ID: Enqueue full queue check - EFQC
    Unit: queue::enqueue ()
    Description: test to determine if queue::enqueue () exits without incrementing count if a queue object is full
    Test steps:
        1. Construct an empty queue object of capacity 1
        2. Enqueue an item into the queue object
        3. Invoke queue::enqueue () once more now that the queue is full
        4. Conditionally evaluate the value of count after the second invocation of queue::enqueue ()
    Test data: size = 1; count = 1; value enqueued = 1
    Precondition: queue object is full; count = 1
    Postcondition: count = 1 still
    Expected result: enqueue() exits; count = 1
    Actual result: enqueue() exits; count = 1
    Status: passed
*/
void queue::testEnqueueFull(void) {
    // 1. Construct an empty queue object of capacity 1
    queue testQueue(1);
    // 2. Enqueue an item into the queue object
    testQueue.enqueue(1);
    // 3. Invoke queue::enqueue () once more now that the queue is full
    testQueue.enqueue(1);
    // 4. Conditionally evaluate the value of count after the second invocation of queue::enqueue ()
    if (testQueue.getCount() == 1)
        cout << "Full enqueue() Status: Passed\n";
    else
    {
        cout << "Full enqueue() Status: Failed\n";
    }
}

/*  Test ID: Enqueue non-full queue check - ENFQC
    Unit: queue::enqueue ()
    Description: test to determine if queue::enqueue () increments count if a queue object is not full
    Test steps:
        1. Construct an empty queue object
        2. Invoke queue::enqueue ()
        3. Conditionally evaluate the value of count after queue::enqueue ()
    Test data: size = 1; item enqueued = 1
    Precondition: queue object is not full; count = 0
    Postcondition: queue object has count = 1
    Expected result: enqueue() enqueues item; count = 1
    Actual result: enqueue() enqueues item; count = 1
    Status: passed
*/
void queue::testEnqueueNotFull(void) {
//        1. Construct an empty queue object
    queue testQueue;
//        2. Invoke queue::enqueue ()
    testQueue.enqueue(1);
//        3. Conditionally evaluate the value of count after queue::enqueue ()
    if (testQueue.getCount() == 1)
        cout << "Non-full enqueue() Status: Passed\n";
    else 
        cout << "Non-full enqueue() Status: Failed\n";
}

/*  Test ID: Peek empty queue check - PEQC
    Unit: queue::peek ()
    Description: test to determine if queue::peek () exits without returning arr[front] if a queue object is empty
    Test steps:
        1. Construct an empty queue object
        2. Invoke queue:peek ()
        4. Conditionally evaluate value of peek()
    Test data: size = 1;
    Precondition: queue object is empty
    Postcondition: queue object is still empty
    Expected result: peek() returns 0
    Actual result: peek() returns
    Status: passed
*/
void queue::testPeekEmpty(void) {
    // construct an empty queue object
    queue testQueue(1);
    // invoke peek() and conditionally evaluate value returned
    if (!testQueue.peek())
        cout << "Empty queue peek() Status: Passed\n";
    else   
        cout << "Empty queue peek() Status: Failed\n";
}

/*  Test ID: Peek empty queue check - PEQC
    Unit: queue::peek ()
    Description: test to determine if queue::peek () exits without returning arr[front] if a queue object is empty
    Test steps:
        1. Construct an empty queue object
        2. Enqueue an integer (in this case 5)
        2. Invoke queue:peek ()
        4. Conditionally evaluate value of peek()
    Test data: size = 3, item enqueued = 5;
    Precondition: queue object is empty
    Postcondition: queue object has one item
    Expected result: peek() returns 5
    Actual result: peek() returns 5
    Status: passed
*/
void queue::testPeekNotEmpty(void) {
    queue testQueue(3);
    testQueue.enqueue(5);
    if (testQueue.peek() == 5)
        cout << "Non-empty queue peek() Status: Passed\n";
    else
        cout << "Non-empty queue peek() Status: Failed\n";
}