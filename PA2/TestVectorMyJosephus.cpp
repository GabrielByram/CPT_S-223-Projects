#include "TestVectorMyJosephus.hpp"

void testVectorMyJosephus(std::ofstream &oFile) {
    // measure time at start
    clock_t start=clock();
    
    // instantiate object
    VectorMyJosephus myJoVect(2,25);

    // select random number to find which line to read in
    srand(time(NULL)); // seed random
    int randNum = rand() % 25;

    // open file
    std::ifstream iFile;
    iFile.open("destinations.csv");

    // go to correct line
    char tempStr[1000000];
    for (int i = 0; i < randNum; i++)
        iFile.getline(tempStr, 1000000);

    // turn into string
    std::string destinations(tempStr);

    // parse into correct cities and load into myVectList
    std::string token1, token2;
    std::string delimiter = ",";
    size_t pos = 0;
    for (int i = 0; i < 25; i++) {
        pos = destinations.find(delimiter);
        token1 = destinations.substr(0, pos);
        destinations.erase(0, pos + delimiter.length());
        pos = destinations.find(delimiter);
        token2 = destinations.substr(0, pos);
        destinations.erase(0, pos + delimiter.length());
        // add the two tokens together to form full name of destination
        Destination newDest(i, token1 + "," + token2);
         // push new destination into vector
        myJoVect.pushBack(newDest);
    }

    iFile.close();

    int count = 1;
    std::string destinationOrder;
    // run a full simulation until a trip destination is found
    while(!myJoVect.isEmpty()) {
        Destination finalDestination = myJoVect.eliminateDestination();
        // reset m value if it is not the last loop through
        if (!myJoVect.isEmpty())
            myJoVect.setM(rand() % (25 - count));
        // print destinations still in the game
        myJoVect.printAllDestinations();
        count++;
        destinationOrder = destinationOrder + " " + finalDestination.getDestinationName();
    }

    // print elimination order
    std::cout << "Elimination order (ending with chosen destination): " << destinationOrder;

    // record ending time
    clock_t end=clock();

    oFile << "Vector CPU elapsed time in seconds: " << (double)(end - start)/CLOCKS_PER_SEC << std::endl;
}