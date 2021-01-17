#include "Menu.h"
#include <iostream>

Menu::Menu() {
    if (!font.loadFromFile("CourierPrime-Regular.ttf")) std::cout << "Cannot open font"; //loads font
}

//Displays the menu to the screen
int Menu::displayMenu(sf::RenderWindow& window){
    bool isMenuOpen = true;
    int count = 0;
    
    printMenu(window); //Prints menu
    window.display();
    
    //Runs while the menu is opened
    while (isMenuOpen) {
        int opt = checkInput();
        if (opt > 0 && opt < 4) {
            if (opt == 1) { //Play Game
                break;
            }
            else if (opt == 2) { //Prints the rules
                printInstructions(window); //Prints the rules
                window.display();
                bool isRulesOpen = true;
                while (isRulesOpen) { //Waits until player presses space to go back to the main page
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                        isRulesOpen = false;
                    }
                }
                printMenu(window);
                window.display();
            }
            else if (opt == 3){
                window.close();//Exits the game
                return -1;
            }
        }
    }  
    return 0;            
}

//Prints the menu
void Menu::printMenu(sf::RenderWindow &window)
{
    //Prints the background for the menu
    sf::Texture menuTexture;
    menuTexture.loadFromFile("Pictures/MenuBackground.png");
    sf::Sprite menuBackground;
    menuBackground.setTexture(menuTexture);
    menuBackground.setScale(3.f, 3.f);
    window.draw(menuBackground);

    //Prints the title
    sf::Text text;
    text.setFont(font);
    text.setString("Welcome to \n THE ANDY\n\n\n");
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::Blue);
    text.setStyle(sf::Text::Bold);
    text.setPosition(sf::Vector2f(400, 10));
    window.draw(text);

    printOptions(window);
}

//Prints the options on the menu
void Menu::printOptions(sf::RenderWindow& window)
{
    //Prints options
    sf::Text text;
    text.setFont(font);
    text.setString("A) Play Game\nB) How To Play\nC) Exit\n");
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::Blue);
    text.setPosition(sf::Vector2f(500, 300));
    window.draw(text);
}

//Prints the rules
void Menu::printInstructions(sf::RenderWindow& window) {
        window.clear(sf::Color::Blue);
        //Prints the game rules
        text.setFont(font);
        text.setString("Objective: Get as many points as possible \nin 30 seconds \n\n1) Click on the positive words (worth 5 points), \nnegative words are negative points (worth -10 points)\n\n\n\nPress Space bar to go back.");
        text.setCharacterSize(30);
        text.setFillColor(sf::Color::Black);
        text.setStyle(sf::Text::Bold);
        text.setPosition(sf::Vector2f(20, 20));
        window.draw(text);
}

//Checks the input of a user while menu is open
int Menu::checkInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) return 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) return 2;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) return 3;
    else return -1;
}
