#include "menu.h"

sf::RectangleShape Menu::background;
sf::Color          Menu::backgroundColor;

Menu::Menu()
{
}
Menu::~Menu()
{
}
void Menu::Init(int MenuWidth, int MenuHeight)
{
    background.setPosition(0,0);
    background.setFillColor(sf::Color(25,25,112));
    background.setSize({MenuWidth,MenuHeight});


}

void Menu::Draw(sf::RenderWindow &window)
{
    Button test1(0,0,"Buttons/birth.png","Buttons/birth.png");
    Button test2(0,24,"Buttons/Start.png","Buttons/birth.png");
    Button test3(10,50,"Buttons/Start.png","Buttons/birth.png");

    window.draw(background);
    Button::DrawAll(window);
}
