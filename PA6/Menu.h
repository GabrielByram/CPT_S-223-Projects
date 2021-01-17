#pragma once
#include<SFML/Graphics.hpp>
#include <string>

class Menu
{
private: 
	sf::Font font;
	sf::Text text;

public: 
	Menu();
    int displayMenu(sf::RenderWindow& window); //Displays menu to screen
	void printMenu(sf::RenderWindow& window); //Prints menu
	void printOptions(sf::RenderWindow& window); //Prints menu options
	void printInstructions(sf::RenderWindow& window); //Prints game instructions
	int checkInput(); //Checks if user typed A, B, or C
};