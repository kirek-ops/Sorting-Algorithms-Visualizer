#pragma once

#include "../Managers/Column.hpp"
#include <SFML/Graphics.hpp>

class MergeSort {
    private:
        Columns *columns;
        void _sort (int l, int r);
    public:
        MergeSort (Columns *);
        void sort (); 
        void merge ();
};