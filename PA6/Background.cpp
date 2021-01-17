#include "Background.h"

Background::Background(){
    if(!font.loadFromFile("CourierPrime-Regular.ttf")) std::cout << "Cannot open font";

    if(!textureBackground1.loadFromFile("Pictures/Classroom.jpg")) std::cout << "Cannot open picture";  //Loads the classroom background
    background1.setTexture(textureBackground1);

    if(!textureBackground2.loadFromFile("Pictures/ZoomClassroom.png")) std::cout << "Cannot open picture";  //Loads the zoom classroom background
    background2.setTexture(textureBackground2);

    if(!textureBackground3.loadFromFile("Pictures/Andy.png")) std::cout << "Cannot open picture";  //Loads THE ANDY background
    background3.setTexture(textureBackground3);
}

//Prints the background options
int Background::printBackgroundMenu(sf::RenderWindow &window)
{
    //Prints the background for the menu
    window.clear(sf::Color::Blue);

    //Prints the text for the background menu
    text.setFont(font);
    text.setString("Select a background :)");
    text.setCharacterSize(95);
    text.setFillColor(sf::Color::Magenta);
    text.setStyle(sf::Text::Bold);
    text.setPosition(sf::Vector2f(0, 0));
    window.draw(text);

    printOptions(window); //Prints background options
    window.display();
    
    bool chosenBackground = false;
    int choice = -1;
    
    //Runs until the background is chosen
    while(!chosenBackground){
        choice = checkEvent(window); //Checks if user chose an option
        if(choice != -1) {
            chosenBackground = true;
        }
    }
  
    //returns chosen background
    return choice;
}

//Prints the background options
void Background::printOptions(sf::RenderWindow& window)
{
    //Loads and displays background option 1
    background1.setScale(sf::Vector2f(0.11f, 0.11f));
    background1.setPosition(sf::Vector2f(800, 200));
    window.draw(background1);

    //Loads and displays background option 2
    background2.setScale(sf::Vector2f(0.3f, 0.3f));
    background2.setPosition(sf::Vector2f(200, 200));
    window.draw(background2);

    //Loads and displays background option 3
    background3.setScale(sf::Vector2f(0.1f, 0.1f));
    background3.setPosition(sf::Vector2f(500, 400));
    window.draw(background3);
}

//Checks the input of a user while background menu is open
int Background::checkEvent(sf::RenderWindow& window){
    sf::Event event;
    sf::Mouse mouse;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        if(event.type == sf::Event::MouseButtonPressed){
            //Checks if the user clicked the zoom background
            if(mouse.getPosition(window).x >= 200
            && mouse.getPosition(window).x < 600 
            && mouse.getPosition(window).y >= 200
            && mouse.getPosition(window).y < 400){
                return 2;
            }
            //Checks if the user clicked the background
            else if(mouse.getPosition(window).x >= 800
            && mouse.getPosition(window).x < 1200 
            && mouse.getPosition(window).y >= 200
            && mouse.getPosition(window).y < 400){
                return 1;
            }
            //Checks if the user clicked the Andy background
            else if(mouse.getPosition(window).x >= 500 
            && mouse.getPosition(window).x < 900 
            && mouse.getPosition(window).y >= 400
            && mouse.getPosition(window).y < 600){
                return 3;
            }
        }
    } 
    return -1;
}

//Draws the background
void Background::printBackground(int choice, sf::RenderWindow& window){
    window.draw(getBackground(choice)); 
}

//Returns the background with the chosen background
sf::Sprite Background::getBackground(int choice){
    if(choice == 1){ //If the choice is classroom
        background1.setScale(sf::Vector2f(0.5f, 0.5f));
        background1.setPosition(sf::Vector2f(0, 0));
        return background1;
    }
    else if(choice == 2){ //If the choice is zoom background
        background2.setScale(sf::Vector2f(1.15f, 1.15f));
        background2.setPosition(sf::Vector2f(0, 0));
        return background2;
    }
    else if(choice == 3){ //If the choice is Andy
        background3.setScale(sf::Vector2f(0.35f, 0.35f));
        background3.setPosition(sf::Vector2f(0, 0));
        return background3;
    }
    else{ //Error
        std::cout << "Choice invalid\n";
        return background1;
    }
}
