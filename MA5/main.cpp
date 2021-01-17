#include "heap.hpp"
#include <ctime>

int main(void) {
    // seed rand
    srand(time(NULL));

    // create heap
    Heap<int> myHeap;

    // populate heap with 1000 random integers between 1 and 1 million
    int randNum = 0;
    for (int i = 0; i < 1000; i++) {
        randNum = rand() % 1000000;
        myHeap.push(randNum);
    }

    // print data to screen
    myHeap.print_pretty();

    // algorithm to find and print out kth smallest element in heap
    /*
    1. set kth smallest element to be the root of the heap
    2. delete root and replace with last leaf node
    3. percolate down from the root until minHeap properties are satisfied
    4. repeat steps 1-3 for a total of k times
    5. print out the current kth smallest element
    */

    // C++ implementation:
    int k = 5; // this can be set to anything. I'm just using 5 for this example.

    int kthSmallestElement = -1;
    for (int i = 0; i < k; i++) {
        kthSmallestElement = myHeap.top();
        myHeap.pop();
    }

    std::cout << "The " << k << "th smallest element in the heap is " << kthSmallestElement << std::endl;

    return 0;
}