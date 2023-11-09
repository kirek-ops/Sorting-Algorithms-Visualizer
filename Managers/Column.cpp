#include "Column.hpp"
#include <algorithm>
#include <cstdlib>
#include "../SortingAlgorithms/bubble.hpp"
#include "../SortingAlgorithms/merge.hpp"
#include "../SortingAlgorithms/quick.hpp"
#include "../SortingAlgorithms/radix.hpp"
#include "../SortingAlgorithms/shell.hpp"

using namespace std;

/// ASSIGN RANDOM VALUES HEIGHTS OF COLUMNS
void Columns::create () {
    srand(time(0));
    for (int i = 0; i < NCOL; ++i) {
        heights.push_back(rand() % (window->getSize().y - 11) + 10);
        colors.push_back(sf::Color::White);
    }
}

Columns::Columns () {
    this->NCOL = 100;
    create();
}

Columns::Columns (int _NCOL, sf::RenderWindow *window, EventManager *ev) {
    this->NCOL = _NCOL;
    this->window = window;
    this->ev = ev;
    this->width = window->getSize().x / NCOL;
    create();
}

/// RENDERING OF WINDOW
void Columns::render () {
    window->clear(sf::Color::Black);
    for (int i = 0; i < NCOL; ++i) {
        double x = width * i;
        sf::RectangleShape elem (sf::Vector2f(width, heights[i]));
        elem.setPosition(x, window->getSize().y - heights[i]);
        elem.setFillColor(colors[i]);
        window->draw(elem);
        sf::sleep(sf::milliseconds(0.007));
    }
    window->display();
}

void Columns::shuffle () {
    random_shuffle(heights.begin(), heights.end());
}

int Columns::get_n () {
    return NCOL;
}

int Columns::height_nth (int n) {
    return heights[n];
}

void Columns::highlight (int pos) {
    sf::Color temp = colors[pos];
    colors[pos] = sf::Color::Green;
    render();
    ev->update();
    colors[pos] = temp;
}

void Columns::highlight (int i, int j) {
    sf::Color temp = colors[i], tempp = colors[j];
    colors[i] = sf::Color::Green;
    colors[i] = sf::Color::Green;
    render();
    ev->update();
    colors[i] = temp;
    colors[j] = tempp;
}

void Columns::swap (int posi, int posj) {
    std::swap(heights[posi], heights[posj]);
    sf::Color buc = colors[posi];
    colors[posi] = colors[posj];
    colors[posj] = buc;
    render();
    ev->update();
}

std::vector <int> Columns::get_hei () {
    return heights;
}

/// CHOOSING SORT ALGO
void Columns::sort (int algo) {
    if (algo == 0) {
        BubbleSort srt (this);
        srt.sort();
    }
    else if (algo == 1) {
        MergeSort srt (this);
        srt.sort();
    }
    else if (algo == 2) {
        QuickSort srt (this);
        srt.sort();
    }
    else if (algo == 3) {
        RadixSort srt (this);
        srt.sort();
    }
    else if (algo == 4) {
        ShellSort srt (this);
        srt.sort();
    }
}

void Columns::set_height (int i, int x) {
    heights[i] = x;
    render();
}