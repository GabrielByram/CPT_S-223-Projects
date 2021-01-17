// Gabriel Byram
// PA2
/*
Does the processor of the machine that is running the algorithms matter? Will you receive the same timing statistics on every machine? 
Yes, because a faster processor will be a able to process the information faster,
leading to lower amounts of time needed to process the data.

Which of the two implementations (list vs. vector) performs best and under what conditions? Does it depend on the input?
The list generally performs better than the vector. At low values of M,
the list and vector have very similar times, but that gap between how long
they take increases as M increases.

How does the running time dependency on the parameter N compare with the dependency on the parameter M?
As N increases, the time spent processing all of the information increases as well. This is also true
for the value of M, albeit to a lesser extent
*/

#include "TestListMyJosephus.hpp"
#include "TestVectorMyJosephus.hpp"

int main(void) {
    std::cout << "Test: Success\n";
    
    std::ofstream oFile;
    oFile.open("results.log");

    // call test functions
    testVectorMyJosephus(oFile);
    testListMyJosephus(oFile);

    oFile.close();

    return 0;
}