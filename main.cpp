#include <SFML/Graphics.hpp>
#include "Managers/Column.hpp"
#include "Managers/EventMan.hpp"
#include <iostream>

using namespace std;
using namespace sf;

/*

 * TODO:
 * Stoping Sorting
 * Radix Sort
 * Shell Sort
 * Sounds

*/

/**
 * [B] - Bubble Sort
 * [M] - Merge Sort
 * [Q] - Quick Sort
 * [R] - Radix Sort
 * [F] - Shell Sort

 * [S] - Shuffle
 * [ ] - Stop Sorting
*/

const int NCOL = 400;

int main () {
    sf::RenderWindow app (sf::VideoMode(1600, 900), "Sorting");
    EventManager ev (&app);
    Columns columns (NCOL, &app, &ev);
    
    sf::Event event;

    while (app.isOpen()) {
        while (app.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                app.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::S: 
                        app.setTitle("Shuffled");
                        columns.shuffle();   
                        break;
                    
                    case sf::Keyboard::B:
                        app.setTitle("Bubble Sort");
                        columns.sort(0);
                        break;

                    case sf::Keyboard::M:
                        app.setTitle("Merge Sort");
                        columns.sort(1);
                        break;
                    
                    case sf::Keyboard::Q:
                        app.setTitle("Quick Sort");
                        columns.sort(2);
                        break;

                    case sf::Keyboard::R:
                        app.setTitle("Radix Sort");
                        columns.sort(3);
                        break;
                }
            }
        }
        columns.render();
    }
    return 0;
}