#include "bubble.hpp"

/// Bubble Sort Implementation

using namespace std;

BubbleSort::BubbleSort (Columns *columns) {
    this->columns = columns;
}

void BubbleSort::sort() {
    _sort();
}

void BubbleSort::_sort () {
    const int N = columns->get_n();
    for (int i = 0; i < N; ++i) {
        bool swapped = 0;
        for (int j = 0; j + i + 1 < N; ++j) {
            columns->highlight(j, j + 1);
            if ((columns->height_nth(j)) > (columns->height_nth(j + 1))) {
                columns->swap(j, j + 1);
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}