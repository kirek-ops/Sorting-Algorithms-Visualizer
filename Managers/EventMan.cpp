#include "EventMan.hpp"

EventManager::EventManager (sf::RenderWindow *window) {
    this -> window = window;
}

void EventManager::update () {
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            std::exit(0);
        }
    }
}