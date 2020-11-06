#ifndef SZYMON_OBJECT
#define SZYMON_OBJECT

#include <SFML/Graphics.hpp>
#include <iostream>

namespace sg {
    class Object 
    {
    protected:
        sf::Vector2f position;

        sf::Texture texture;
        sf::RectangleShape rect;

    public:
        Object(std::string txt, sf::Vector2f pos);
        void update();
        void render(sf::RenderTarget &target, bool isLoaded);

    };
};

#endif // SZYMON_OBJECT