#ifndef DESTINATION_HPP
#define DESTINATION_HPP

#include <string>
#include <iostream>

class Destination {
    private:
    int position; // position occupied by the desination location in sequence
    std::string name; // name of the destination city

    public:
    // explicit constructor
    Destination(int pos, std::string nam) {
        position = pos;
        name = nam;
    } 
    // destructor 
    ~Destination() {};

    // prints current position of destination in sequence
    void printPosition(void);
    // prints the name of the destination city
    void printDestinationName(void);

    // setters
    // sets the value for the destination's position in sequence
    void setPosition(int pos);
    
    // getters
    // returns the current position of destination in sequence
    int getPosition(void);
    // returns the name of the destination city
    std::string getDestinationName(void);
};

#endif