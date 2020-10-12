#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

sf::RectangleShape rect;

void renderingThread(sf::RenderWindow* window) {
    rect.setSize(sf::Vector2f(100.0f, 100.0f));
    rect.setPosition(sf::Vector2f(20.0f, 20.0f));


    while(window->isOpen()) {
        window->clear();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            rect.move(0.0f, -3.7f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            rect.move(0.0f, 3.7f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            rect.move(-3.7f, 0.0f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            rect.move(3.7f, 0.0f);
        }

        window->draw(rect);

        window->display();
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Retro FPS", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    window.setActive(false);

    sf::Thread thread(&renderingThread, &window);
    thread.launch();

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
        }
    }
}