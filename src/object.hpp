#pragma once
#ifndef SZYMON_OBJECT
#define SZYMON_OBJECT

#include <SFML/Graphics.hpp>
#include <iostream>

#include "types.hpp"

namespace sg {
    class Object 
    {
    protected:
        sf::Vector2f position;

        sf::Texture texture;
        sf::RectangleShape rect;

    public:
        Object(std::string txt, sf::Vector2f pos);
        Object(std::string txt, sf::Vector2f pos, sf::Vector2f size);
        Object(sf::Color color, sf::Vector2f pos, sf::Vector2f size);
        void render(sf::RenderTarget &target, bool isLoaded);

    };
};

#endif // SZYMON_OBJECT