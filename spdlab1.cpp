#include "utility.h"

using namespace std;

auto timeMeasure(int n, vector <rpqcontainer> d, int(*function)(int, vector <rpqcontainer>)) {
	auto start = std::chrono::high_resolution_clock::now();
	function(n, d);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	cout << "Czas wykonywania sie algorytmu:" << duration.count() << endl;
	return duration;
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

vector<rpqcontainer> Schrage(int n, vector <rpqcontainer> data){
	int k = 0;
	vector <rpqcontainer> orderedColletion;
	int t = findMinValueR(data).r;
	vector <rpqcontainer> PI;

	while ((orderedColletion.empty() == false) || (data.empty() == false)) {
		while ( (data.empty()==false) && (findMinValueR(data).r <= t) ) {
			//showVector(data);
			rpqcontainer tmp = findMinValueR(data);
			orderedColletion.push_back(tmp);
			RemoveElement(data, tmp);
			//showVector(data);
		}
		if (orderedColletion.empty() == false) {
			rpqcontainer tmp2 = findMaxValueQ(orderedColletion);
			RemoveElement(orderedColletion, tmp2);
			PI.push_back(tmp2);
			t = t + tmp2.p;
			k = k + 1;
		}
		else {
			t = findMinValueR(data).r;
		}
	}
	return PI;
}

int main()
{
	vector <rpqcontainer> data;
	int n;
	int parameters;

	tie(n, parameters, data) = getDataFromFile("data10.txt"); 

	// PART BEFORE SORT
	vector <rpqcontainer> pom = Schrage(n, data);
	int schrag = cmaxFunc(n,pom);
	cout << "SCHRAGE: " << schrag << endl;
	timeMeasure(n,data,cmaxFunc);
	int beforeSort = cmaxFunc(n, data);
	//showVector(data);



	// PART AFTER SORT
	sort(data.begin(), data.end(), func);
	timeMeasure(n, data, cmaxFunc);
//	showVector(data);
	int afterSort = cmaxFunc(n, data);

	cout << "Przed: " << beforeSort << endl << "Po: " << afterSort << endl;
	cout << endl << endl;
	
	return 0;
}