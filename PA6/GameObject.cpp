#include "GameObject.h"

GameObject::GameObject(){
    if(!font.loadFromFile("CourierPrime-Regular.ttf")) std::cout << "Cannot open font\n"; // loads in the font we are using for the words on screen
    readFile(); //Reads from file and puts into a map
    initializeText(); //initalizes text to each word, making it easier to print to the screen
}

//Reads from a file into a map
void GameObject::readFile(){
    std::string tempWord, ifPositive;
    std::ifstream wordFile("Words.txt");
    int count = 0;
    //Goes through each line of the file
    while(wordFile.good()){
        getline(wordFile, tempWord, ',');
        getline(wordFile, ifPositive, '\n');
        Word newWord;
        newWord.ifPositiveWord = std::stoi(ifPositive);
        newWord.word = tempWord;
        allWords.insert(std::pair<int,Word>(count, newWord));
        count++;
    }  
}

//Initiallizes text to each word, making it easier to print to screen
void GameObject::initializeText(){
    //Goes through the map and loads in the texts for each word
    while(count != allWords.size()){
        allWords.at(count).text.setFont(font);
        allWords.at(count).text.setCharacterSize(32);
        allWords.at(count).text.setStyle(sf::Text::Bold);
        allWords.at(count).text.setString(allWords.at(count).word);
        //Makes a random color for the words
        int randomR = rand() % 255;
        int randomG = rand() % 255;
        int randomB = rand() % 255;
        allWords.at(count).text.setFillColor(sf::Color(randomR,randomG,randomB));
        //Randomizes if the word will go in the right direction
        if (rand() % 2 == 1)
            allWords.at(count).rightDirection = true;
        else
            allWords.at(count).rightDirection = false;
        count++;
   }
}

//Picks three random words from the allWords map to display on the screen
void GameObject::randomWords(){
    for(int i = 0; i < 3; i++){
       int randNum = rand() % (allWords.size());
       wordsOnScreen.push_back(allWords.at(randNum));
    }
}

//The game
void GameObject::game(sf::RenderWindow& window){
    loadSounds(); //loads the sound

    Background background;

    int offset = 0;
    int backgroundChoice = background.printBackgroundMenu(window); //Prints the background menu
    
    window.display();
    randomWords();

    sf::Clock clock;
    sf::Time time;
    
    //Goes through each word that needs to be printed to the screen
    for (int i = 0; i < wordsOnScreen.size() / wordsOnScreen.size(); i++)
    {   
        offset = i * (wordsOnScreen.size());
        for(int i = 0; i < wordsOnScreen.size(); i++){
            setPos(offset + i); // places words onto the screen
        }
        
        while (checkIfOffScreen(offset) && window.isOpen()) { // Checks if at least one word is on the screen
            window.clear();
            background.printBackground(backgroundChoice, window);  //Prints the background
            displayTimer(window, clock, time); //Displays timer
            usleep(100000);
            getEvent(offset, window); // checks to see if any word has been clicked
            moveRand(offset); // lets words move in randomly set directions
            displayWords(offset, window); // displays words that have not been clicked
            displayPoints(window); // displays the user's current points
            window.display();
        } 
    }
}
//Displays timer on screen
void GameObject::displayTimer(sf::RenderWindow& window, sf::Clock clock, sf::Time timeLeft){
    sf::Time endTime = sf::seconds(30.0f);

    //Creates the background of the timer
    sf::RectangleShape clockBackground(sf::Vector2f(70, 20));
    clockBackground.setFillColor(sf::Color::Red);
    clockBackground.setPosition(0, 0);
    window.draw(clockBackground);
    
    //Changes from float to string
    std::ostringstream ss;
    timeLeft = endTime - clock.getElapsedTime();
    //Checks if time is up
    if(timeLeft <= sf::seconds(0.0f)){
        endGame(window);
        return;
    }
    ss << timeLeft.asSeconds();
    std::string timer(ss.str());
    timer = timer.substr(0, 5);

    sf::Font font;
    if (!font.loadFromFile("CourierPrime-Regular.ttf")) return; //Error

    //Prints time
    sf::Text text;
    text.setFont(font);
    text.setString(timer + "s");
    text.setCharacterSize(15);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setPosition(sf::Vector2f(0, 0));
    window.draw(text);
}

//Displays end game screen
void GameObject::endGame(sf::RenderWindow& window){
    sf::Text text;
    text.setFont(font);
    text.setString("Andy O'Fallon is: ");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setPosition(sf::Vector2f(0, 0));


    for (int i = 0; i < allWords.size(); i++) {
        if(allWords.at(i).clicked == 1 && allWords.at(i).ifPositiveWord == 1){ //Prints all positive clicked words
            allWords.at(i).text.setPosition(550, 0);
            for(int j = 0; j < 50; j++){
                window.clear(sf::Color::Black);
                window.draw(text);
                allWords.at(i).text.move(0, j);
                usleep(100000);
                window.draw(allWords.at(i).text);
                displayPoints(window); //Displays points to screen 
                window.display();
            }
        } 
    }

    window.clear(sf::Color::Black);
    displayPoints(window); //Displays points to screen 
    window.display();
    usleep(2000000);
    window.close();
}

//Checks if a word was clicked
void GameObject::getEvent(int offset, sf::RenderWindow &window){
    int letterWidth = 19;
    int letterHeight = 25;
    sf::Event event;
    sf::Mouse mouse;
    while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::MouseButtonPressed){
                for (std::vector<Word>::iterator it = wordsOnScreen.begin(); it != wordsOnScreen.end(); it++) {
                    if(mouse.getPosition(window).x >= (it->text.getPosition().x) 
                    && mouse.getPosition(window).x  <= (it->text.getPosition().x + it->word.size() * letterWidth) 
                    && mouse.getPosition(window).y >= it->text.getPosition().y 
                    && mouse.getPosition(window).y <= (it->text.getPosition().y + letterHeight)){
                        it->clicked = 1;
                        for(int i = 0; i < allWords.size(); i++){
                            if(it->word == allWords.at(i).word){
                                allWords.at(i).clicked = 1;
                            }
                        }
                    }
                }
            }
        } 
}

// adds words to screen in a random spot on the top of the screen
void GameObject::setPos(int offset){
    int randStartPos = rand() % 1100;
    wordsOnScreen[offset].text.setPosition(randStartPos, 0);
}

//Put a new word into the words on screen vector
void GameObject::fetchNewWord(int offset){

    int randNum = rand() % (allWords.size());

    bool rDirection;
    if(randNum % 2 == 1){
         rDirection = true;
    }
    else{ 
        rDirection = false;
    }
    allWords.at(randNum).rightDirection = rDirection;

    wordsOnScreen[offset] = allWords.at(randNum);
    setPos(offset);
}

// replaces words that have falled off the screen with new words at the top of the screen
bool GameObject::checkIfOffScreen(int offset){
    for(int i = 0; i < wordsOnScreen.size(); i++){
        if(wordsOnScreen[offset + i].text.getPosition().y <= 800) return true;
        else{
            fetchNewWord(offset + i);
        }
    }
    return true;
}
// move the words in a random direction
void GameObject::moveRand(int offset){ 
    for(int i = 0; i < wordsOnScreen.size(); i++){ //goes through each word
        int randSign = rand() % 2;
        double randPosX;
        if (wordsOnScreen[i].rightDirection == true)
            randPosX = rand() % 10 + 10;
        else
            randPosX = -1 * (rand() % 10 + 10);
        double randPosY = rand() % 10 + 10;
        wordsOnScreen[offset + i].text.move(randPosX, randPosY);
    }
}

//Display words onto screen
void GameObject::displayWords(int offset, sf::RenderWindow &window){
    for (int i = 0; i < wordsOnScreen.size(); i++) { //Traverse through words on screen
        if(wordsOnScreen[offset + i].clicked == 0){ //If word has not been clicked yet
            window.draw(wordsOnScreen[offset + i].text);
        } 
        else
        { //If word has been clicked, then play appropriate sound
            if(wordsOnScreen[offset + i].ifPositiveWord == 1) {
                points += 5;
                if (rand() % 3 == 0)
                    reallyGoodSound.play();
                else
                    goodSound.play();
            }
            else {
                points -= 10; 
                badSound.play();
            }
            fetchNewWord(offset + i); //Put a new word into the words on screen vector
        }
    }
}

// displays the players points in the bottom left hand corner of the screen
void GameObject::displayPoints(sf::RenderWindow &window){ 
    sf::Font font;
    font.loadFromFile("CourierPrime-Regular.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString("Points: " + std::to_string(points));
    text.setCharacterSize(32);
    text.setColor(sf::Color::Red);
    text.setPosition(0,680);
    window.draw(text);
}

// loads Andy sounds into the correct files
void GameObject::loadSounds(void) {
if(!goodBuffer.loadFromFile("Audio/andyVeryGood.wav"))
    std::cout << "Could not open file!\n";
goodSound.setBuffer(goodBuffer);

if(!badBuffer.loadFromFile("Audio/notGoodEnough.wav"))
    std::cout << "Could not open file!\n";
badSound.setBuffer(badBuffer);

if(!reallyGoodBuffer.loadFromFile("Audio/thatsreallygood.wav"))
    std::cout << "Could not open file!\n";
reallyGoodSound.setBuffer(reallyGoodBuffer);
}
