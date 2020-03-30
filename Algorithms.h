#pragma once
#include "utility.h"
#include <limits>

vector<rpqcontainer> Schrage(int n, vector <rpqcontainer> data);
vector<rpqcontainer> schrageWithQueue(int n, vector <rpqcontainer> data);
int schragePMTN(int n, vector <rpqcontainer> data);
int schragePMTNWithQueue(int n, vector <rpqcontainer> data);
int cmaxFunc(int n, vector <rpqcontainer> d);
vector<rpqcontainer> Carlier(int n, vector <rpqcontainer> &data);

//Carlier
int findBMax(int n, vector <rpqcontainer> pi, int Cmax);
int findCMax(int n, int a, int b, vector<rpqcontainer> pi);
int findAMin(int n, int b, vector<rpqcontainer> pi, int Cmax);
vector<rpqcontainer> initiateKVec(int n, int b, int c, vector<rpqcontainer> pi);

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
