// Gabriel Byram
// September 17, 2020
// MA1

#include "testQueue.hpp"

/* 5 Attributes
1. Exits should not have been used in enqueue and dequeue. This makes the functions difficult to test.
2. Variable and function names should be clearer. Capacity is set to the parameter named size passed into the queue
   constructor, while the function size() in queue returns the number of ints currently in the queue. This is confusing.
3. The queue class should be made a class template in order for it to be used more generally with different data types
   other than ints. This is a bad programming practice
4. The comments for each function testQueue.cpp should be more robust. They at the very least should include
   pre and post-conditions
5. The destructor uses delete instead of delete[]. This is bad programming practice when deleting a dynamically
   allocated array, because it can cause heap corruption
*/

// main function
int main()
{
	// call your test functions here!
	queue testQueue;
	testQueue.testSize();
	testQueue.testIsFull();
	testQueue.testIsEmpty();
	testQueue.testDequeueNotEmpty();
	testQueue.testDequeueEmpty();
	testQueue.testEnqueueFull();
	testQueue.testEnqueueNotFull();
	testQueue.testPeekEmpty();
	testQueue.testPeekNotEmpty();

	return 0;
}

