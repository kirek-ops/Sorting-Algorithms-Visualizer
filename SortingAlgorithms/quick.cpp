#include "quick.hpp"
#include <iostream>
using namespace std;

QuickSort::QuickSort (Columns *columns) {
    this -> columns = columns;
}

void QuickSort::sort() {
    _sort(0, columns -> get_n() - 1);
}

void QuickSort::_sort (int l, int r) {
    if (l < r) {
        int i = partition(l, r);
        _sort(l, i - 1);
        _sort(i + 1, r);
    }
}

int QuickSort::partition (int l, int r) {
    int el = columns -> height_nth(r);
    int i = l - 1;
    for (int j = l; j < r; ++j) {
        int x = columns -> height_nth(j);
        if (x < el) {
            ++i;
            columns -> swap(i, j);
        }
    }
    columns -> swap(i + 1, r);
    return i + 1;
}