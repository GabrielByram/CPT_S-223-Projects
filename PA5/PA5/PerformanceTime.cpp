#include "PerformanceTime.h"

//Records performance time for chaining and linear hash table
void performanceTime(int maxNum) {

    probingPerformance(maxNum);
    chainingPerformance(maxNum);
    parallelProbingPerformance(maxNum);
}

// computes time taken for insert, deletion, and searching in chaining hash
void chainingPerformance(int maxNum) {
    std::ofstream outfile;
    outfile.open("HashingAnalysis.txt", std::ios_base::app); // append instead of overwrite

    clock_t time;
    time = clock();

    outfile << "Chaining Hash Table:" << std::endl;

    ChainingHash<int, int> chainingHashTable(101);

    for (int i = 1; i < maxNum; i++) {
        chainingHashTable.emplace(i, i);

        if (i % 1000 == 0)
            cout << "chaining: " << i << std::endl;
    }

    time = clock() - time;
    outfile << "Inserting 1,000,000 elements took: " << ((float)time / CLOCKS_PER_SEC) << " seconds" << std::endl;

    time = clock();
    chainingHashTable.at(177);

    time = clock() - time;
    outfile << "Searching for element 177 took: " << ((float)time / CLOCKS_PER_SEC) << " seconds" << std::endl;

    // search for 2,000,000
    time = clock();
    chainingHashTable.at(2000000);

    time = clock() - time;
    outfile << "Removing element 2,000,000 took: " << ((float)time / CLOCKS_PER_SEC) << " seconds" << std::endl;

    // erase 177
    time = clock();
    chainingHashTable.erase(177);

    time = clock() - time;
    outfile << "Erasing element 177 took: " << ((float)time / CLOCKS_PER_SEC) << " seconds" << std::endl;


    // write final states
    outfile << "Final size: " << chainingHashTable.size() << "\nBucket count: " <<
        chainingHashTable.bucket_count() << "\nLoad Factor: " << chainingHashTable.load_factor() << std::endl << std::endl;

    // close file
    outfile.close();
}

//Calculates the time needed to perform insert, find, and delete for probing hash
void probingPerformance(int maxNum) {
    std::ofstream outfile;
    outfile.open("HashingAnalysis.txt", std::ios_base::app); // append instead of overwrite

    clock_t time;
    time = clock();

    outfile << "Probing Hash Table:" << std::endl;

    ProbingHash<int, int> probingHashTable(101);

    for (int i = 1; i < maxNum; i++) {
        probingHashTable.emplace(i, i);
        if (i % 1000 == 0)
            cout << "Probing: " << i << std::endl;
    }

    time = clock() - time;
    outfile << "Inserting 1,000,000 elements took: " << ((float)time / CLOCKS_PER_SEC) << " seconds" << std::endl;

    time = clock();
    probingHashTable.at(177);

    time = clock() - time;
    outfile << "Searching for element 177 took: " << ((float)time / CLOCKS_PER_SEC) << " seconds" << std::endl;

    // search for 2,000,000
    time = clock();
    probingHashTable.at(2000000);

    time = clock() - time;
    outfile << "Searching for element 2,000,000 took: " << ((float)time / CLOCKS_PER_SEC) << " seconds" << std::endl;

    // Erase 177
    time = clock();
    probingHashTable.erase(177);

    time = clock() - time;
    outfile << "Erasing element 177 took: " << ((float)time / CLOCKS_PER_SEC) << " seconds" << std::endl;

    // Write final stats
    outfile << "Final size: " << probingHashTable.size() << "\nBucket count: " << probingHashTable.bucket_count()
        << "\nLoad Factor: " << probingHashTable.load_factor() << std::endl << std::endl;

    // close file
    outfile.close();
}

//Calculates the time needed to perform insert, find, and delete for parallel probing hash
void parallelProbingPerformance(int maxNum) {
    std::ofstream outfile;
    outfile.open("HashingAnalysis.txt", std::ios_base::app); // append instead of overwrite

    clock_t time;
    time = clock();

    outfile << "Parallel Probing Hash Table (4 Threads):" << std::endl;

    ParallelProbingHash<int, int> parallelHashTable(101);

    #pragma omp parallel for
        for (int i = 1; i < maxNum; i++) {
            parallelHashTable.emplace(i, i);
            if (i % 1000 == 0)
                cout << "Parallel Probing: " << i << std::endl;
        }   

    time = clock() - time;
    outfile << "Inserting 1,000,000 elements took: " << ((float)time / CLOCKS_PER_SEC) << " seconds" << std::endl;

    time = clock();
    parallelHashTable.at(177);

    time = clock() - time;
    outfile << "Searching for element 177 took: " << ((float)time / CLOCKS_PER_SEC) << " seconds" << std::endl;

    // search for 2,000,000
    time = clock();
    parallelHashTable.at(2000000);

    time = clock() - time;
    outfile << "Searching for element 2,000,000 took: " << ((float)time / CLOCKS_PER_SEC) << " seconds" << std::endl;

    // Erase 177
    time = clock();
    parallelHashTable.erase(177);

    time = clock() - time;
    outfile << "Erasing element 177 took: " << ((float)time / CLOCKS_PER_SEC) << " seconds" << std::endl;

    // Write final stats
    outfile << "Final size: " << parallelHashTable.size() << "\nBucket count: " << parallelHashTable.bucket_count()
        << "\nLoad Factor: " << parallelHashTable.load_factor() << std::endl << std::endl;

    // close file
    outfile.close();
}