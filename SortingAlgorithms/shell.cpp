#include "shell.hpp"

using namespace std;

ShellSort::ShellSort (Columns *columns) {
    this->columns = columns;
}

void ShellSort::sort () {
    _sort(0, columns->get_n() - 1);
}

void ShellSort::_sort (int l, int r) {
    for (int gap = (r - l + 1) / 2; gap > 0; gap >>= 1) {
        for (int i = gap; i <= r; ++i) {
            for (int j = i; j - l >= gap && (columns->height_nth(j)) < (columns->height_nth(j - gap)); j -= gap) {
                columns->highlight(j, j - gap);
                columns->swap(j, j - gap);
            }
        }
    }
}
