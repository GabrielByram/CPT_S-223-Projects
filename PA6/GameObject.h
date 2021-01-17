#pragma once
#include<SFML/Graphics.hpp>
#include <iostream>
#include <fstream> 
#include <sstream>
#include <time.h>
#include <ctime>
#include <unistd.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp> 
#include "Background.h"

struct Word{
    bool rightDirection;
    int clicked;
    int ifPositiveWord;
    std::string word;
    sf::Text text;
};

class GameObject
{
private: 
    int points = 0;
    int count = 0;
	sf::Mouse mouse;
    sf::Font font;
    sf::SoundBuffer goodBuffer;
    sf::Sound goodSound;
    sf::SoundBuffer badBuffer;
    sf::Sound badSound;
    sf::SoundBuffer reallyGoodBuffer;
    sf::Sound reallyGoodSound;

public: 
    std::map<int, Word> allWords; //Map that holds a struct of all the words in the given files
    std::vector<Word> wordsOnScreen; //Vector to hold all words that are currently on screen

    GameObject();
    void readFile(); //Reads from a file and  puts into a map
    void initializeText(); //Initializes text for every word in the map such that printing to the screen is made easier
    void randomWords(); //Chooses three random words to put in a vector of words to the screen
    void game(sf::RenderWindow& window); //Plays the actual game
    void displayTimer(sf::RenderWindow& window, sf::Clock clock, sf::Time elapsed); //Displays timer
    void endGame(sf::RenderWindow& window); //Displays end game screen
    void getEvent(int offset, sf::RenderWindow &window); //Checks for if a word was clicked
    void setPos(int offset); //Sets start x position of word
    void fetchNewWord(int offset); //Adds a new word into words on screen vector
    bool checkIfOffScreen(int offset); //Checks if word is off screen
    void moveRand(int offset); //Moves the word rand
    void displayWords(int offset, sf::RenderWindow &window); //Displays word to screen
    void displayPoints(sf::RenderWindow & window); //Displays points to screen
    void loadSounds(); //Loads the sounds
};

