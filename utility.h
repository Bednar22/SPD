#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <string>
#include <tuple>

using namespace std;

struct rpqcontainer {
	int r;
	int p;
	int q;
};

int findSameVector(rpqcontainer sample, vector <rpqcontainer> data);
bool func(const rpqcontainer& a, const rpqcontainer& b);
bool func2(const rpqcontainer& a, const rpqcontainer& b);
rpqcontainer findMinValueR(vector <rpqcontainer> &data);
rpqcontainer findMaxValueQ(vector <rpqcontainer> &data);
void showVector(vector <rpqcontainer>& data);
void RemoveElement(vector<rpqcontainer>& data,const rpqcontainer exampl);
tuple<int, int, vector <rpqcontainer>> getDataFromFile(const string fileName);
