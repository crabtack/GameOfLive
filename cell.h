#ifndef CELL_H
#define CELL_H

#define WindowWidth     800
#define WindowHeight    600

#define CellNumX        100
#define CellNumY        100
#define CellSize        10
#define CellDistance    1

#define AnimTime 500

#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

class Cell
{
private:
    bool                    alive;
    static int              numX;
    static int              numY;

    sf::RectangleShape      shape;
    static sf::Color        colorAlive;
    static sf::Color        colorDead;

    static sf::Vector2f     size;
    sf::Vector2f            position;

    static std::vector<int> live;

public:
    Cell();
    ~Cell();

    bool            GetAlive();
    void            SetAlive(bool live);
    static          std::vector<Cell> cells;
    static void     DeployCells(int countX, int countY);
    void            draw(sf::RenderWindow &window);
    static void     DrawAll(sf::RenderWindow &window);
    static void     Reset();
    static void     Click(sf::Vector2i Pos);
    static void     Update();

};

#endif // CELL_H
