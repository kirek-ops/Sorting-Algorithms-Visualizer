#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include "EventMan.hpp"

class Columns {
    private:
        int NCOL;
        double width;
        std::vector <int> heights;
        std::vector <sf::Color> colors;
        sf::RenderWindow *window;
        EventManager *ev;        

    public:
        Columns ();
        Columns (int NCOL, sf::RenderWindow *window, EventManager *ev);

        void shuffle ();
        void render ();
        void create ();
        std::vector <int> get_hei ();

        int get_n ();
        int height_nth (int n);
        void swap (int posi, int posj);
        void highlight (int pos);
        void highlight (int i, int j);

        void sort (int algo);
        void set_height (int i, int x);
};