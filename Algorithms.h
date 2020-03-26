#pragma once
#include "utility.h"
#include <limits>

vector<rpqcontainer> Schrage(int n, vector <rpqcontainer> data);
vector<rpqcontainer> schrageWithQueue(int n, vector <rpqcontainer> data);
int schragePMTN(int n, vector <rpqcontainer> data);
int schragePMTNWithQueue(int n, vector <rpqcontainer> data);
int cmaxFunc(int n, vector <rpqcontainer> d);
template<typename A> void print_queue(A& pq);