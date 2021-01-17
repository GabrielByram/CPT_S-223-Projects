//Gabriel Byram
//Shira Feinberg
//PA 5 Hash Tables

/*
*     (6 pts) How did the serial implementations for the ChainingHash and ProbingHash compare to each other? Did you expect the time results obtained? Explain.

                    The Probing Hash took less time than the Chaining has by about 2 seconds. This is because probing hash does not need to search through lists 
                    in order to rehash, which saves a significant amount of time.

*     (8 pts) Compare the parallel and serial implementations for the ProbingHash. Did the parallel implementations provide you with the expected speedup? Explain.

                    Surprisingly, we found that the seriel implementation for probing hash was actually faster than the parallel implementation. Theoretically, 
                    the parallel implementation of the probing hash should be faster than the serial implementation, because multiple threads are able to
                    process information at a higher speed than just one thread in the serial implementation. However, in most of these functions there are a lot 
                    of critical regions.

*     (8 pts) What could you change in your parallel implementations to improve performance and speedup? Explain. 
        
                    In order to make our parallel implementation faster, we could've changed our insert function around so that there aren't as much things in 
                    the critical region along with having more cores to allow for more threads. 
*/

#include "PerformanceTime.h"

int main() {
    performanceTime(1000001);

    return 0;
}
