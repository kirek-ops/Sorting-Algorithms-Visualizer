#pragma once

#include "../Managers/Column.hpp"
#include <SFML/Graphics.hpp>

class QuickSort {
    private:
        Columns *columns;
        void _sort (int l, int r);
        int partition (int l, int r);
    public:
        QuickSort (Columns *);
        void sort (); 
};