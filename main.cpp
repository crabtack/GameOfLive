#include <SFML/Graphics.hpp>
#include <cell.h>


int main()
{
    sf::Vector2i MousePos;
    sf::Vector2f WorldPos;
    sf::Vector2i IntPos;

    bool Autorun = false;

    sf::RenderWindow window(sf::VideoMode(WindowWidth,WindowHeight,32), "Game of Live");
    Cell::DeployCells(CellNumX,CellNumY);

    sf::View view1(sf::FloatRect(WindowWidth/2,WindowHeight/2,WindowWidth,WindowHeight));



    while(window.isOpen())
    {
        sf::Event event;

        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonReleased)
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    MousePos = sf::Mouse::getPosition(window);
                    WorldPos = window.mapPixelToCoords(MousePos);
                    IntPos.x = round(WorldPos.x);
                    IntPos.y = round(WorldPos.y);
                    Cell::Click(IntPos);

                }
                if(event.mouseButton.button == sf::Mouse::Right)
                    Cell::Update();
            }
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Right)
                {
                    view1.move(10.0f,0);
                }
                if(event.key.code == sf::Keyboard::Left)
                {
                    view1.move(-10.0f,0);
                }
                if(event.key.code == sf::Keyboard::Down)
                {
                    view1.move(0,10.f);
                }
                if(event.key.code == sf::Keyboard::Up)
                {
                    view1.move(0,-10.f);
                }
                if(event.key.code == sf::Keyboard::Space)
                {
                    if(Autorun)
                        Autorun = false;
                    else
                        Autorun = true;
                }
                if(event.key.code == sf::Keyboard::R)
                {
                    Cell::Reset();
                }

            }
            if(event.type == sf::Event::MouseWheelMoved)
            {
                view1.zoom(1+ 0.1f* event.mouseWheel.delta);
                view1.setCenter(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
                sf::Mouse::setPosition(sf::Vector2i(WindowWidth/2,WindowHeight/2),window);
            }
        }
        if(Autorun)
            Cell::Update();
        window.clear();
        window.setView(view1);
        Cell::DrawAll(window);
        window.display();
    }
    return 0;

}
