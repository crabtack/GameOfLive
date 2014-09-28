#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>

class Button
{
private:
    sf::Sprite Sprite;
    sf::Texture TextureDefault;
    sf::Texture TextureActive;
    sf::Vector2f position;
    sf::Vector2f size;

public:
    Button();
    Button(float posX, float posY, std::string FileDefault, std::string FileActive);
    ~Button();
    void Draw(sf::RenderWindow &window);
    static std::vector<Button*> buttons;
    static void DrawAll(sf::RenderWindow &window);
};

#endif // BUTTON_H
