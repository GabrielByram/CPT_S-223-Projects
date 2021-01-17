#ifndef LISTMYJOSEPHUS_HPP
#define LISTMYJOSEPHUS_HPP

#include "Destination.hpp"
#include <list>

class ListMyJosephus {
    private:
    int M; // interval of elimination
    int N; // number of destination cities at the start of the simulation
    std::list<Destination> joList;

    public:
    // explicit constructor
    ListMyJosephus(int tempM, int tempN) {
        M = tempM;
        N = tempN;
    }
    // destructor
    ~ListMyJosephus() {};

    void clear(void); // makes the sequence empty
    // returns the number of destinations still left
    int currentSize(void);
    // returns true if there are no destinations in the sequence
    bool isEmpty(void);   
    // eliminates the destination bases on the simulation rules and
    // returns a copy of the destination object eliminated 
    Destination eliminateDestination(void);
    // prints all of the destination ities left in the sequence
    // starting from the destination with the smallest position
    void printAllDestinations(void);
     // pushes a destination value into the list through back
    void pushBack(Destination dest);

    // set value for M
    void setM(int tempM) {
        this->M = tempM;
    }
};

#endif