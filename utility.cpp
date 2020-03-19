#include "utility.h"

/* inputData getDataFromFile(string fileName) {
	inputData myData;
	ifstream file;
	file.open(fileName); 
	file >> myData.n;
	file >> myData.parameters;
	rpqcontainer tmp;
	for (int i = 0; i < n; i++) {
		file >> tmp.r;
		file >> tmp.p;
		file >> tmp.q;

		myData.actualData.push_back(tmp);
	}

	file.close();
	return myData;
} */

// Finding element of vector data with the same parameters as sample
int findSameVector(rpqcontainer sample, vector <rpqcontainer> data) {
	
	int index=0;

	for (int i = 0; i < data.size(); i++) {
		if ((data[i].r == sample.r) && (data[i].p == sample.p) && (data[i].q == sample.q)) {
			index = i;
		}
	}
	return index;
}

// To findMinValueR
bool func(const rpqcontainer& a, const rpqcontainer& b)
{
	return a.r < b.r;
}

// To find maxValueQ
bool func2(const rpqcontainer& a, const rpqcontainer& b)
{
	return a.q > b.q;
}

// Finding element of vector data with min r value
rpqcontainer findMinValueR(vector <rpqcontainer> data) {
	sort(data.begin(), data.end(), func);
	return data[0];
}

// Finding element of vector data with max q value
rpqcontainer findMaxValueQ(vector <rpqcontainer> data) {
	sort(data.begin(), data.end(), func2);
	return data[0];
}

// Printing vector on screen, just for tests
void showVector(vector <rpqcontainer> data) {
	for (int i = 0; i < data.size(); i++) {
		cout << "Wartosc r=  " << data[i].r << " p= " << data[i].p << " q= " << data[i].q << "  " << endl;
	}
	cout << endl;
}

// Removing element from vector data (finding the same element as exampl)
void RemoveElement(vector<rpqcontainer>& data, rpqcontainer exampl) {
	data.erase(
		std::remove_if(data.begin(), data.end(), [&](rpqcontainer const& d) {
			return (d.r == exampl.r) && (d.p == exampl.p) && (d.q == exampl.q);
			}),
		data.end());
}
