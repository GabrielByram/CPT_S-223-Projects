#pragma once
#include<SFML/Graphics.hpp>
#include <iostream>

class Background
{
private: 
	sf::Font font;
	sf::Text text;
	sf::Sprite background1;
    sf::Texture textureBackground1;
	sf::Sprite background2;
    sf::Texture textureBackground2;
	sf::Sprite background3;
    sf::Texture textureBackground3;

public: 
	Background();
	int printBackgroundMenu(sf::RenderWindow& window); //Prints the background menu
	void printOptions(sf::RenderWindow& window); //Prints the background options
    int checkEvent(sf::RenderWindow& window); //Checks if a user clicked on a background
	void printBackground(int choice, sf::RenderWindow& window); //Prints a specific background
	sf::Sprite getBackground(int choice); //Returns a background at the given choice
};