#pragma once
#include <SFML/Graphics.hpp>

class EventManager {
    public:
        EventManager (sf::RenderWindow *window);
        void update ();
    private:
        sf::RenderWindow *window;
};
