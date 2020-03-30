#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <string>
#include <tuple>
#include <queue>
using namespace std;

struct rpqcontainer {
	int r;
	int p;
	int q;


    rpqcontainer& operator = (const rpqcontainer &rpqcopy) {
        r = rpqcopy.r;
        p = rpqcopy.p;
        q = rpqcopy.q;
        return *this;
    }

    rpqcontainer(int x, int y, int z) { r = x; p = y; q = z; }
    rpqcontainer(){ r = 0; p = 0; q = 0; }
};

struct CompareQ {
    bool operator()(rpqcontainer const& p1, rpqcontainer const& p2)
    {
        return p1.q < p2.q;
    }
};



int findSameVector(rpqcontainer sample, vector <rpqcontainer> data);
bool func(const rpqcontainer& a, const rpqcontainer& b);
bool func2(const rpqcontainer& a, const rpqcontainer& b);
bool func3(const rpqcontainer& a, const rpqcontainer& b);
bool func4(const rpqcontainer& a, const rpqcontainer& b);
bool funcRQ(const rpqcontainer& a, const rpqcontainer& b);
rpqcontainer findMinValueR(vector <rpqcontainer> data);
rpqcontainer findMinValueQ(vector <rpqcontainer> data);
rpqcontainer findMaxValueQ(vector <rpqcontainer> data);
//void RemoveElement(vector<rpqcontainer>& data,const rpqcontainer exampl);
tuple<int, int, vector <rpqcontainer>> getDataFromFile(const string fileName);
void showVector(vector <rpqcontainer> data);
void RemoveElement( vector<rpqcontainer>& data, rpqcontainer exampl);