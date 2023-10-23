#pragma once

#include "../Managers/Column.hpp"
#include <SFML/Graphics.hpp>

class BubbleSort {
    private:
        Columns *columns;
        void _sort ();
    public:
        BubbleSort (Columns *);
        void sort (); 
};