#pragma once
#ifndef SZYMON_WINDOW
#define SZYMON_WINDOW

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>

#include "types.hpp"
#include "object.hpp"

namespace sg {
    class Window 
    {
    protected:
        sf::RenderWindow* window;
        sf::View view;
        sf::Event event;

        sf::Clock clock;

        bool isLoaded;
        bool focus;

        sf::Font font;
        int line, lines;
        sf::String textEntered[99];
        sf::Text text;

    public:
        Window();
        void update();
        void render();

    };
};

#endif // SZYMON_WINDOW