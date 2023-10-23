#pragma once

#include "../Managers/Column.hpp"
#include <SFML/Graphics.hpp>

class ShellSort {
    private:
        Columns *columns;
        void _sort(int l, int r);
    public:
        ShellSort (Columns *);
        void sort (); 
};