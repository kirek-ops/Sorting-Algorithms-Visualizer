#include "bubble.hpp"
#include <iostream>
using namespace std;

BubbleSort::BubbleSort (Columns *columns) {
    this -> columns = columns;
}

void BubbleSort::sort() {
    _sort();
}

void BubbleSort::_sort () {
    for (int i = 0; i < (columns -> get_n()); ++i) {
        bool swapped = 0;
        for (int j = 0; j + i + 1 < (columns -> get_n()); ++j) {
            columns -> highlight(j, j + 1);
            sf::sleep(sf::milliseconds(1));
            if ((columns -> height_nth(j)) > (columns -> height_nth(j + 1))) {
                columns -> swap(j, j + 1);
                swapped = 1;
                sf::sleep(sf::milliseconds(1));
            }
        }
        if (!swapped) break;
    }
}