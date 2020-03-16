#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <chrono>


using namespace std;

struct rpqcontainer {
	int r;
	int p;
	int q;
};

bool func(const rpqcontainer& a, const rpqcontainer& b)
{
	return a.r < b.r;
}

int cmaxFunc(int n, vector <rpqcontainer> d) {
	int* S = new int[n];
	int* C = new int[n];
	int Cmax;

	S[0] = d[0].r;
	C[0] = S[0]+d[0].p;
	Cmax = C[0] + d[0].q;
	for (int i = 1; i < n; i++) {
		S[i] = max(d[i].r,C[i-1]);
		C[i] = S[i] + d[i].p;
		Cmax = max(Cmax, C[i]+d[i].q);
	}

	delete[] S, C;
	return Cmax;
}

void showVector(vector <rpqcontainer> data) {
	for (int i = 0; i < data.size(); i++) {
		cout << "Wartosc r=  " << data[i].r <<" p= " << data[i].p << " q= " << data[i].q << "  "<<endl;
	}
	cout << endl;
}

auto timeMeasure(int n, vector <rpqcontainer> d, int(*function)(int , vector <rpqcontainer>)) {
	auto start = std::chrono::high_resolution_clock::now();
	function(n, d);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	cout << "Czas wykonywania sie algorytmu:" << duration.count() << endl;
	return duration;
}

int main()
{
	ifstream plik; 
	vector <rpqcontainer> data;
	plik.open("data500.txt"); //otwarcie pliku
	int n;
	int parameters;
	plik >> n;
	plik >> parameters;

	for (int i = 0; i < n; i++) {
	//while (!plik.eof()){
	//		int control;
		rpqcontainer tmp;
		plik >> tmp.r;
		plik >> tmp.p;
		plik >> tmp.q;
		
		
	//	cout << "dupa" ;
		data.push_back(tmp);
	} 

	plik.close();

	// CZESC PRZED SORTOWANIEM
	timeMeasure(n,data,cmaxFunc);
	int beforeSort = cmaxFunc(n, data);
	//showVector(data);


	// CZESC PO SORTOWANIU
	sort(data.begin(), data.end(), func);
	timeMeasure(n, data, cmaxFunc);
	//showVector(data);
	int afterSort = cmaxFunc(n, data);

	cout << "Przed: " << beforeSort << endl << "Po: " << afterSort << endl;
	cout << endl << endl;
	
	return 0;
}