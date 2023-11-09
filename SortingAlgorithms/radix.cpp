#include "radix.hpp"

/// Radix Sort Implemantation 

using namespace std;

RadixSort::RadixSort (Columns *columns) {
    this->columns = columns;
}

void RadixSort::sort () {
    _sort();
}

void RadixSort::_sort () {
    int mx = get_max();
    for (int i = 1; mx / i > 0; i *= 10) {
        sort_digit(i);
    }
}

int RadixSort::get_max () {
    const int N = columns->get_n();
    int res = columns->height_nth(0);
    for (int i = 1; i < N; ++i) {
        res = std::max(res, columns->height_nth(i));
    }
    return res;
}

void RadixSort::sort_digit (int digit) {
    const int N = columns->get_n();
    std::vector <int> temp (N);
    std::vector <int> cnt (10); 

    for (int i = 0; i < N; ++i) {
        ++cnt[(columns->height_nth(i) / digit) % 10];
    }

    for (int i = 1; i < 10; ++i) {
        cnt[i] += cnt[i - 1];
    }

    for (int i = N - 1; i >= 0; --i) {
        temp[cnt[(columns->height_nth(i) / digit) % 10] - 1] = columns->height_nth(i);
        --cnt[(columns->height_nth(i) / digit) % 10];
    }

    for (int i = 0; i < N; ++i) {
        columns->set_height(i, temp[i]);
        columns->highlight(i);
    }
}   