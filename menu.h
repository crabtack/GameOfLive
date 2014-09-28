#ifndef MENU_H
#define MENU_H

#include <button.h>

class Menu
{
private:
    static sf::RectangleShape background;
    static sf::Color backgroundColor;

public:
    Menu();
    ~Menu();
    static void Draw(sf::RenderWindow &window);
    static void Init(int MenuWidth, int MenuHeight);

};

#endif // MENU_H
