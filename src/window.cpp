#include "window.hpp"

using namespace sg;

Object loadScreen("szymon.png", sf::Vector2f(0.0f, 0.0f));
Object bar(sf::Color::Red, sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1280.0f, 20.0f));
Object icon("logo.png", sf::Vector2f(0.0f, 0.0f));

Window::Window()
{
    isLoaded = false;
    focus = true;
    window = new sf::RenderWindow(sf::VideoMode(400, 130), "Szymon", sf::Style::None);
    window->setFramerateLimit(60);
    view.reset(sf::FloatRect(0.0f, 0.0f, window->getSize().x, window->getSize().y));
    window->setView(view);
    clock.restart();


    font.loadFromFile("arial.ttf");
    text.setFont(font);
    text.setPosition(0.0f, 0.0f);
    text.setFillColor(sf::Color::Cyan);
    text.setCharacterSize(24);
    line = 0;
    lines = 99;

    for(int i = 0; i < lines; ++i)
    {
        textEntered[i] = "";
    }
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

            if(event.type == sf::Event::KeyPressed && focus) 
            {
                switch (event.key.code)
                {
                case sf::Keyboard::Escape:
                    window->close();
                    break;
                
                case sf::Keyboard::Up:
                    if(line > 0)
                        line--;
                    break;

                case sf::Keyboard::Enter:
                    if(line < lines - 1)
                        line++;
                    break;

                case sf::Keyboard::Down:
                    if(line < lines - 1)
                        line++;
                    break;

                case sf::Keyboard::Numpad0:
                    std::cout << "numpad0" << "\n";
                    break;

                case sf::Keyboard::BackSpace:
                    if(textEntered[line].getSize() > 0)
                        textEntered[line].erase(textEntered[line].getSize() - 1, 1);
                    break;
                }
            }

            if(event.type == sf::Event::GainedFocus)
            {
                focus = true;
            }

            if(event.type == sf::Event::LostFocus)
            {
                focus = false;
            }

            if(event.type == sf::Event::TextEntered && focus && isLoaded && !sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0))
            {
                textEntered[line] += event.text.unicode;
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

    for(int j = 0; j < lines; ++j)
    {
        text.setString(textEntered[j]);
        text.setPosition(text.getPosition().x, text.getPosition().y + 24);
        window->draw(text);
    }
    text.setPosition(0.0f, 0.0f);

    window->display();
}