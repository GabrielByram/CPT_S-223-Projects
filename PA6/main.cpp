// Game made by Shira Feinberg, Ethan Stone Miller, and Gabriel James Byram
#include "Menu.h"
#include "GameObject.h"
#include "TestCases.h"

int main() { 
    srand(time(NULL)); // Allows random numbers

    //testAll();

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Andy Ninja"); //Makes game window

    Menu menu;
    GameObject theGame;

    //While the window is open
    while (window.isOpen()) {
        
        int check = menu.displayMenu(window); //Displays menu to screen
        //Checks if to quit out of the program
        if(check == -1){
            return 0;
        }

        theGame.game(window); //Plays the game
    }

    return 0; // exits successfully

}