#include "TestCases.h"

//Tests display menu
void testDisplayMenu(){
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Andy Ninja");
    Menu menu;
    menu.displayMenu(window);
    std::cout << "Test menu success\n";
}

//Tests read file and if map is not empty
void testReadFile(){
    GameObject game;
    std::ifstream wordFile("Words.txt");
    if(wordFile.bad()){
        std::cout << "Test failed, file is bad\n";
        return;
    }

    game.readFile();
    if(game.allWords.size() == 0){
        std::cout << "Test failed, nothing is in all words map\n";
        return;
    }
    std::cout << "Test read file success\n";
}

//Test random words
void testRandomWords(){
    GameObject game;
    game.randomWords();
    std::cout << "Random Words success\n";
}

// tests loadSounds() and notifies the user that it runs successfully
void testLoadSounds() {
    GameObject testGame;
    testGame.loadSounds();
    std::cout << "Load Sounds succesfully executed!\n";
}

// tests the initialize text function of the game object
void testInitializeText(){
    GameObject testGame;
    testGame.initializeText();
    std::cout << "Initialize text success\n";
}

//Calls all the test functions
void testAll(){
    testDisplayMenu();
    testInitializeText();
    testLoadSounds();
    testReadFile();
    testRandomWords(); 
}