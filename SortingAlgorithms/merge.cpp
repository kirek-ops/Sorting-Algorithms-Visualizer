#include "merge.hpp"

/// Merge Sort Implementation

using namespace std;

MergeSort::MergeSort (Columns *columns) {
    this->columns = columns;
}

void MergeSort::sort() {
    _sort(0, columns->get_n() - 1);
}

void MergeSort::_sort (int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    _sort(l, mid); _sort(mid + 1, r); 
    int i = l;
    int j = mid + 1;
    vector <int> tmp (r - l + 1);
    for (int q = 0; q < r - l + 1; q++) {
        if ((j > r) || ((i <= mid) && ((columns->height_nth(i)) <= (columns->height_nth(j))))) {
            tmp[q] = (columns->height_nth(i++));
        }
        else {
            tmp[q] = (columns->height_nth(j++));
        }
    }
    for (int q = 0; q < r - l + 1; q++) {
        columns->set_height(l + q, tmp[q]);
        columns->highlight(l + q);
    }
}