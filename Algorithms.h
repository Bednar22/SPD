#pragma once
#include "utility.h"
#include <limits>

vector<rpqcontainer> Schrage(int n, vector <rpqcontainer> data);
vector<rpqcontainer> schrageWithQueue(int n, vector <rpqcontainer> data);
int schragePMTN(int n, vector <rpqcontainer> data);
int schragePMTNWithQueue(int n, vector <rpqcontainer> data);
int cmaxFunc(int n, vector <rpqcontainer> d);

template<typename T> void print_queue(T& queue) {
    rpqcontainer tmp;
    int i = 0;
    while (!queue.empty()) {
        tmp = queue.top();
        cout << "Element nr " << i << ": R: " << tmp.r << " P: " << tmp.p << " Q: " << tmp.q << endl;
        queue.pop();
        i++;
    }
    std::cout << '\n';
}
