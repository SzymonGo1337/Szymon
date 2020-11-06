#include "window.hpp"

using namespace sg;

Object loadScreen("szymon.png", sf::Vector2f(0.0f, 0.0f));
Object bar(sf::Color::Red, sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1280.0f, 20.0f));
Object icon("logo.png", sf::Vector2f(0.0f, 0.0f));

Window::Window()
{
    isLoaded = false;
    window = new sf::RenderWindow(sf::VideoMode(400, 130), "Szymon", sf::Style::None);
    window->setFramerateLimit(60);
    view.reset(sf::FloatRect(0.0f, 0.0f, window->getSize().x, window->getSize().y));
    window->setView(view);
    clock.restart();
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

        if(clock.getElapsedTime().asSeconds() > 2 && !isLoaded)
        {
            window->setSize(sf::Vector2u(1280, 720));
            window->setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - window->getSize().x / 2, sf::VideoMode::getDesktopMode().height / 2 - window->getSize().y / 2));
            view.reset(sf::FloatRect(0.0f, 0.0f, window->getSize().x, window->getSize().y));
            window->setView(view);
            clock.restart();
            isLoaded = true;
        }

        render();
    }
}

void Window::render()
{
    window->clear();

    loadScreen.render(*window, !isLoaded);
    
    bar.render(*window, isLoaded);
    icon.render(*window, isLoaded);

    window->display();
}