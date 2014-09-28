#include <SFML/Graphics.hpp>
#include <cell.h>
#include <menu.h>


int main()
{
    sf::Vector2i MousePos;
    sf::Vector2f WorldPos;
    sf::Vector2i IntPos;

    bool Autorun = false;

    sf::RenderWindow window(sf::VideoMode(WindowWidth,WindowHeight,32), "Game of Live");
    Cell::DeployCells(CellNumX,CellNumY);
    Menu::Init(WindowWidth*0.25f,WindowHeight);

    sf::View view1; //Game
    sf::View view2; //Menu

    view1.setViewport(sf::FloatRect(0.25f,0,1.0f,1.0f));
    view1.setSize(WindowWidth , WindowHeight);

    view2.setViewport(sf::FloatRect(0,0,0.25f,1.0f));
    view2.setSize(WindowWidth * 0.25f,WindowHeight);
    view2.move(-400,-200);

    sf::RectangleShape testShape;
    testShape.setFillColor(sf::Color::Red);
    testShape.setSize({50,50});
    testShape.setPosition(0,0);



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
                    if(MousePos.x > WindowWidth * 0.25f) //Click at Grid
                    {

                    WorldPos = window.mapPixelToCoords(MousePos, view1);
                    IntPos.x = round(WorldPos.x);
                    IntPos.y = round(WorldPos.y);
                    Cell::Click(IntPos);
                    }
                    else //Click at Menu
                    {
                        std::cout<<"Menu Click!\n";
                        WorldPos = window.mapPixelToCoords(MousePos,view2);
                        IntPos.x = round(WorldPos.x);
                        IntPos.y = round(WorldPos.y);
                        std::cout<<"X: "<<IntPos.x<<"Y:"<<IntPos.y<<std::endl;

                    }

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
                sf::Mouse::setPosition(sf::Vector2i(WindowWidth/2 + WindowWidth * 0.25f,WindowHeight/2),window);
            }
        }
        if(Autorun)
            Cell::Update();
        window.clear();
        window.setView(view2);
        Menu::Draw(window);
        window.setView(view1);
        Cell::DrawAll(window);

        window.display();
    }
    return 0;

}
