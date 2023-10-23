#pragma once

#include "../Managers/Column.hpp"
#include <SFML/Graphics.hpp>

class RadixSort {
    private:
        Columns *columns;
        int get_max ();
        void sort_digit (int digit);
        void _sort();
    public:
        RadixSort (Columns *);
        void sort (); 
};