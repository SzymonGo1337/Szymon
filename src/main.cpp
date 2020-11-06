#include "window.hpp"

int main() {
    sg::Window window;

    window.update();

    /* sf::Texture txt[7];
    txt[0].loadFromFile("logo.png");
    txt[1].loadFromFile("szymon.png");

    sf::RenderWindow window(sf::VideoMode(txt[1].getSize().x, txt[1].getSize().y), "Szymon", sf::Style::None);
    window.setFramerateLimit(60);
    window.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - txt[1].getSize().x / 2, sf::VideoMode::getDesktopMode().height / 2 - txt[1].getSize().y / 2));

    sf::View view(sf::FloatRect(0.0f, 0.0f, window.getSize().x, window.getSize().y));
    window.setView(view);

    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(txt[1].getSize()));
    rect.setTexture(&txt[1]);
    rect.setPosition(0.0f, 0.0f);

    sf::Clock clock;
    bool isChanged = false;

    sf::RectangleShape logo;
    logo.setSize(sf::Vector2f(txt[0].getSize()));
    logo.setTexture(&txt[0]);
    logo.setPosition(0.0f, 0.0f);

    sf::RectangleShape bar;
    bar.setSize(sf::Vector2f(1280.0f, 20.0f));
    bar.setPosition(sf::Vector2f(0.0f, 0.0f));
    bar.setFillColor(sf::Color::Red);

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            } else if(event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        if(clock.getElapsedTime().asSeconds() > 2 && !isChanged) {
            window.setSize(sf::Vector2u(1280, 720));
            window.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - window.getSize().x / 2, sf::VideoMode::getDesktopMode().height / 2 - window.getSize().y / 2));
            view.reset(sf::FloatRect(0.0f, 0.0f, window.getSize().x, window.getSize().y));
            window.setView(view);
            clock.restart();
            isChanged = true;
        }

        window.clear();

        if(!isChanged) {
            window.draw(rect);
        }

        if(isChanged) {
            window.draw(bar);
            window.draw(logo);
        }

        window.display();
    } */
}