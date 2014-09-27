#include "cell.h"

 std::vector<Cell> Cell::cells;
 std::vector<int>  Cell::live;
 sf::Color         Cell::colorAlive;
 sf::Color         Cell::colorDead;
 sf::Vector2f      Cell::size;

 int Cell::numX;
 int Cell::numY;


Cell::Cell()
{
   shape.setSize(size);
   shape.setFillColor(colorDead);
}
Cell::~Cell()
{

}

void Cell::DeployCells(int countX, int countY)
{
    colorDead = sf::Color(6,6,6,255);
    colorAlive = sf::Color(255,255,255,255);

    size.x = CellSize;
    size.y = CellSize;


    numX = countX;
    numY = countY;

    for(int iY = 0; iY < numY; iY++)
    {
        for(int iX = 0; iX < numX; iX++)
        {
         Cell newCell;
         newCell.alive = false;

         Cell::cells.push_back(newCell);
         cells[(iX + iY * numX)].position.x = iX * (CellSize + CellDistance);
         cells[(iX + iY * numX)].position.y = iY * (CellSize + CellDistance);
         cells[(iX + iY * numX)].shape.setPosition(cells[(iX + iY * numX)].position);
         //std::cout <<"posX: " <<iX * (CellSize + CellDistance) <<"posY: "<< iY * (CellSize + CellDistance) << std::endl;
         live.push_back(0);

        }
    }
}
void Cell::draw(sf::RenderWindow &window)
{
    window.draw(shape);
}

void Cell::DrawAll(sf::RenderWindow &window)
{
    for (int i = 0; i < cells.size(); i++)
    {
        cells[i].draw(window);
    }
}

void Cell::SetAlive(bool live)
{
    alive = live;
    if(live)
        shape.setFillColor(colorAlive);
    else
        shape.setFillColor(colorDead);
}

void Cell::Click(sf::Vector2i Pos)
{
    int CellX = 0, CellY = 0;
    CellX = Pos.x /(size.x + CellDistance);
    CellY = Pos.y /(size.y + CellDistance);
    std::cout <<"X: "<<CellX<<"Y: "<<CellY <<std::endl;

    if(cells[CellX + CellY*numX].alive)
        cells[CellX + CellY*numX].SetAlive(false);
    else
        cells[CellX + CellY*numX].SetAlive(true);

}
void Cell::Update()
{
    for(int i = numX + 1; i< (cells.size() -numX); i++)
    {
        int count = 0;
        if(cells[i + 1].alive) //Rechts
            count++;
        if(cells[i - 1].alive) //Links
            count++;
        if(cells[(i -numX)+ 1].alive) //Oben Rechts
            count++;
        if(cells[i - numX].alive) //Oben Mitte
            count++;
        if(cells[(i-numX) -1].alive) //Oben Links
            count++;
        if(cells[(i + numX) + 1].alive) //Unten Rechts
            count++;
        if(cells[i + numX].alive) //Unten Mitte
            count++;
        if(cells[(i + numX)-1].alive) //Unten Links
            count++;

        if((count < 2) || (count >3))  live[i] = 1; //Cell will be killed
        if(count == 2) live[i] = 0; //Cell wont change
        if(count == 3) live[i] = 2;


    }
    for (int i = 0; i < live.size(); i++)
    {
        if(live[i] == 1) cells[i].SetAlive(false);
        if(live[i] == 2) cells[i].SetAlive(true);
    }

}
void Cell::Reset()
{
    for(int i = 0; i <cells.size();i++)
    {
        cells[i].SetAlive(false);
    }
}
