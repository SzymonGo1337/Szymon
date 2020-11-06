#include "window.hpp"

using namespace sg;

Object obj1("szymon.png", sf::Vector2f(0.0f, 0.0f));

Window::Window()
{
    isLoaded = false;
    window = new sf::RenderWindow(sf::VideoMode(400, 130), "Szymon", sf::Style::None);
    window->setFramerateLimit(60);
    view.reset(sf::FloatRect(0.0f, 0.0f, window->getSize().x, window->getSize().y));
    window->setView(view);

}

void Window::update()
{
    while(window->isOpen()) 
    {
        while(window->pollEvent(event))
        {
            if(event.type == sf::Event::Closed) 
            {
                window->close();
            }

            if(event.type == sf::Event::KeyPressed) 
            {
                switch (event.key.code)
                {
                case sf::Keyboard::Escape:
                    window->close();
                    break;
                }
            }
        }

        render();
    }
}

void Window::render()
{
    window->clear();

    obj1.render(*window, !isLoaded);

    window->display();
}