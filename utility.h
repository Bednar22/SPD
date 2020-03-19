#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <string>

using namespace std;

struct rpqcontainer {
	int r;
	int p;
	int q;
};

/*struct inputData {
	int n;
	int parameters;
	vector <rpqcontainer> actualData;
}; */

int findSameVector(rpqcontainer sample, vector <rpqcontainer> data);
bool func(const rpqcontainer& a, const rpqcontainer& b);
bool func2(const rpqcontainer& a, const rpqcontainer& b);
rpqcontainer findMinValueR(vector <rpqcontainer> data);
rpqcontainer findMaxValueQ(vector <rpqcontainer> data);
void showVector(vector <rpqcontainer> data);
void RemoveElement(vector<rpqcontainer>& data, rpqcontainer exampl);
vector <rpqcontainer> getDataFromFile(string fileName);