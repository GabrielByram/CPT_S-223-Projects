#include "Destination.hpp"

// prints current position of destination in sequence
void Destination::printPosition(void) {
    std::cout << this->position << ". ";
}

// prints the name of the destination city
void Destination::printDestinationName(void) {
        std::cout << this->name << "\n";
}

// setters
// sets the value for the destination's position in sequence
void Destination::setPosition(int pos) {
    this->position = pos;
}

// getters
// returns the current position of destination in sequence
int Destination::getPosition(void) {
    return this->position;
}
// returns the name of the destination city
std::string Destination::getDestinationName(void) {
    return this->name;
}