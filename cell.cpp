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
    colorDead = sf::Color(20,20,20,255);
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

void Cell::Reset()
{
    for(int i = 0; i <cells.size();i++)
    {
        cells[i].SetAlive(false);
    }
}


void Cell::Update()
{
    int offset = (numY - 1) * numX;
    for(int i = 0; i < (cells.size()); i++)
    {
        int count = 0;
        if(i == 0) //Ecke oben links
        {
            if(cells[i + 1].alive) //Rechts
                count++;
            if(cells[(i + numX )- 1].alive) //Links
                count++;
            if(cells[offset + 1].alive) //Oben Rechts
                count++;
            if(cells[offset].alive) //Oben Mitte
                count++;
            if(cells[(offset + numX) -1].alive) //Oben Links
                count++;
            if(cells[(i + numX) + 1].alive) //Unten Rechts
                count++;
            if(cells[i + numX].alive) //Unten Mitte
                count++;
            if(cells[(i + numX*2) - 1].alive) //Unten Links
                count++;

        }
        else if (i == (numX - 1)) //Ecke oben Rechts
        {
            if(cells[(i-numX)+1].alive) //Rechts
                count++;
            if(cells[i - 1].alive) //Links
                count++;
            if(cells[(i + 1 +offset) - numX].alive) //Oben Rechts
                count++;
            if(cells[i + offset].alive) //Oben Mitte
                count++;
            if(cells[(i + offset)-1].alive) //Oben Links
                count++;
            if(cells[i+1].alive) //Unten Rechts
                count++;
            if(cells[i + numX].alive) //Unten Mitte
                count++;
            if(cells[(i + numX)-1].alive) //Unten Links
                count++;

        }
        else if (i == offset)//Ecke unten Links
        {
            if(cells[i + 1].alive) //Rechts
                count++;
            if(cells[(i + numX) - 1].alive) //Links
                count++;
            if(cells[(i -numX)+ 1].alive) //Oben Rechts
                count++;
            if(cells[i - numX].alive) //Oben Mitte
                count++;
            if(cells[i-1].alive) //Oben Links
                count++;
            if(cells[(i-offset)+1].alive) //Unten Rechts
                count++;
            if(cells[i - offset].alive) //Unten Mitte
                count++;
            if(cells[(i - offset) + (numX - 1)].alive) //Unten Links
                count++;
        }
        else if (i == ((offset + numX) - 1)) //Unten Rechts
        {
            if(cells[(i - numX) + 1].alive) //Rechts
                count++;
            if(cells[i - 1].alive) //Links
                count++;
            if(cells[i-(numX*2)+1].alive) //Oben Rechts
                count++;
            if(cells[i - numX].alive) //Oben Mitte
                count++;
            if(cells[(i-numX) -1].alive) //Oben Links
                count++;
            if(cells[(i- offset)-(numX-1)].alive) //Unten Rechts
                count++;
            if(cells[i - offset].alive) //Unten Mitte
                count++;
            if(cells[(i - offset)-1].alive) //Unten Links
                count++;
            std::cout <<"countUR: "<<count<<std::endl;
        }

        else if (i < numX) //Oben
        {
            if(cells[i + 1].alive) //Rechts
                count++;
            if(cells[i - 1].alive) //Links
                count++;
            if(cells[i + offset+ 1].alive) //Oben Rechts
                count++;
            if(cells[i + offset].alive) //Oben Mitte
                count++;
            if(cells[(i+ offset) -1].alive) //Oben Links
                count++;
            if(cells[(i + numX) + 1].alive) //Unten Rechts
                count++;
            if(cells[i + numX].alive) //Unten Mitte
                count++;
            if(cells[(i + numX)-1].alive) //Unten Links
                count++;
        }
        else if(i > offset)  //Unten
        {
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
            if(cells[(i - offset) + 1].alive) //Unten Rechts
                count++;
            if(cells[i  - offset].alive) //Unten Mitte
                count++;
            if(cells[(i - offset)-1].alive) //Unten Links
                count++;
        }
        else if((i % numX) == 0) //Links
        {
            if(cells[i + 1].alive) //Rechts
                count++;
            if(cells[(i+numX) - 1].alive) //Links
                count++;
            if(cells[(i -numX)+ 1].alive) //Oben Rechts
                count++;
            if(cells[i - numX].alive) //Oben Mitte
                count++;
            if(cells[i -1].alive) //Oben Links
                count++;
            if(cells[(i + numX) + 1].alive) //Unten Rechts
                count++;
            if(cells[i + numX].alive) //Unten Mitte
                count++;
            if(cells[(i + numX * 2)-1].alive) //Unten Links
                count++;
        }
        else if (((i + 1) % numX) == 0)//Rechts
        {
                    if(cells[(i - numX) + 1].alive) //Rechts
                        count++;
                    if(cells[i - 1].alive) //Links
                        count++;
                    if(cells[(i - 2*numX)+ 1].alive) //Oben Rechts
                        count++;
                    if(cells[i - numX].alive) //Oben Mitte
                        count++;
                    if(cells[(i-numX) -1].alive) //Oben Links
                        count++;
                    if(cells[i + 1].alive) //Unten Rechts
                        count++;
                    if(cells[i + numX].alive) //Unten Mitte
                        count++;
                    if(cells[(i + numX)-1].alive) //Unten Links
                        count++;
        }
        else if(i > numX && i < offset) //Mittleres Feld
        {
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
        }

        if((count < 2) || (count >3))  live[i] = 1; //Cell will be killed
        if(count == 2) live[i] = 0; //Cell wont change
        if(count == 3) live[i] = 2;

        //if(count == 0 || count == 2 || count == 4 || count == 6 || count == 8) //Kopierwelt
          //  live[i] = 1;
        //else
          //  live[i] = 2;


    }
    for (int i = 0; i < live.size(); i++)
    {
        if(live[i] == 1) cells[i].SetAlive(false);
        if(live[i] == 2) cells[i].SetAlive(true);
    }

}
