#include "button.h"

std::vector <Button*> Button::buttons;

Button::Button()
{
}
Button::~Button()
{
}
Button::Button(float posX, float posY, std::string FileDefault, std::string FileActive)
{
    if(!TextureDefault.loadFromFile(FileDefault)) //Texturen laden
        std::cout <<"Could not open: " <<FileDefault<<std::endl;
    if(!TextureActive.loadFromFile(FileActive))
        std::cout<<"Could not open: "<<FileActive<<std::endl;

    Sprite.setPosition(posX,posY);
    Sprite.setTexture(TextureDefault);
    buttons.push_back(this);

}

void Button::Draw(sf::RenderWindow &window)
{
    window.draw(Sprite);
}

void Button::DrawAll(sf::RenderWindow &window)
{
    std::cout<<"buttons.size: "<<buttons.size()<<std::endl;
    for(int i = 0; i < buttons.size();i++)
    {
        buttons[i]->Draw(window);
    }
}
