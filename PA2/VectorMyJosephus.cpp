#include "VectorMyJosephus.hpp"

// makes the sequence empty
void VectorMyJosephus::clear(void) {
    this->joVect.clear();
}

// returns the number of destinations still left
int VectorMyJosephus::currentSize(void) {
    return this->joVect.size();
}

// returns true if there are no destinations in the sequence
bool VectorMyJosephus::isEmpty(void) {
    if (this->joVect.size() == 0)
        return true;
    else
        return false;
} 

// eliminates the destination based on the simulation rules and
// returns a copy of the destination object eliminated 
Destination VectorMyJosephus::eliminateDestination(void) {
    // use iterator
    int count = 0;
    std::vector<Destination>::iterator it1 = joVect.begin();
    // iterate until we are the space
    for (; count < this->M; it1++) {
        count++;
    }
    Destination copy = *it1;
    joVect.erase(it1);
    return copy;
}
// prints all of the destination ities left in the sequence
// starting from the destination with the smallest position
void VectorMyJosephus::printAllDestinations(void) {
    // use iterator
    for (std::vector<Destination>::iterator it1 = joVect.begin(); it1 != joVect.end(); it1++) {
        it1->printPosition();
        it1->printDestinationName();
    }
}

// pushes a destination value into the vector through back
void VectorMyJosephus::pushBack(Destination dest) {
    // push into back of vector if first item in vector
    this->joVect.push_back(dest);   
}