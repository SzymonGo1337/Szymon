#include "object.hpp"

using namespace sg;

Object::Object(std::string txt, sf::Vector2f pos)
{
    position = pos;

    if(!texture.loadFromFile(txt))
    {
        std::cerr << sf::err << "\n";
        exit(EXIT_FAILURE);
    }

    rect.setSize(sf::Vector2f(texture.getSize().x, texture.getSize().y));
    rect.setTexture(&texture);
    rect.setPosition(pos);
}

Object::Object(std::string txt, sf::Vector2f pos, sf::Vector2f size)
{
    position = pos;

    if(!texture.loadFromFile(txt))
    {
        std::cerr << sf::err << "\n";
        exit(EXIT_FAILURE);
    }

    rect.setSize(size);
    rect.setTexture(&texture);
    rect.setPosition(pos);
}

Object::Object(sf::Color color, sf::Vector2f pos, sf::Vector2f size)
{
    position = pos;

    rect.setSize(size);
    rect.setFillColor(color);
    rect.setPosition(pos);
}

void Object::render(sf::RenderTarget &target, bool isLoaded)
{
    if(isLoaded)
        target.draw(rect);
}