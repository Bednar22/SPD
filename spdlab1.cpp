#include "utility.h"
#include "Algorithms.h"

using namespace std;

auto timeMeasure(int n, vector <rpqcontainer> data, int(*function)(int, vector <rpqcontainer>)) {
	auto start = std::chrono::high_resolution_clock::now();
	function(n, data);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	cout << "Czas wykonywania sie algorytmu: " << duration.count() << endl;
	return duration;
}

auto timeMeasure2(int n, vector <rpqcontainer> data, vector<rpqcontainer>(*function)(int, vector <rpqcontainer>)) {
	auto start = std::chrono::high_resolution_clock::now();
	function(n, data);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	//cout << "Czas wykonywania sie algorytmu:" << duration.count() << endl;
	return duration;
}


int main()
{
	vector <rpqcontainer> data;
	int n;
	int parameters;
	tie(n, parameters, data) = getDataFromFile("data10.txt"); 

	// SCHRAGE PTMN
	int schragPMTN = schragePMTN(n, data);
	cout << "SCHRAGE PMTN: " << schragPMTN << endl;

	//// SCHRAGE
	vector <rpqcontainer> pom = Schrage(n, data);
	int schrag = cmaxFunc(n, pom);
	cout << "SCHRAGE: " << schrag << endl;

	//auto timeSchrage = timeMeasure2(n, data, Schrage);
	//cout << "SCHRAGE ZWYKLE: " << timeSchrage.count() << endl;

	vector <rpqcontainer> pom2 = schrageWithQueue(n, data);
    int schrag2 = cmaxFunc(n, pom2);
	cout << "SCHRAGE WITH QUEUE: " << schrag2 << endl;

	//auto timeSchrageWithQueue = timeMeasure2(n, data, schrageWithQueue);
	//cout << "SCHRAGE WITH QUEUE: " << timeSchrageWithQueue.count() << endl;
	
	// SCHRAGE PTMN WITH QUEUE
	int schragPMTNWithQueue = schragePMTNWithQueue(n, data);
	cout << "SCHRAGE PMTN WITH QUEUE: " << schragPMTNWithQueue << endl;

	// PART BEFORE SORT

	int beforeSort = cmaxFunc(n, data);
	//timeMeasure(n,data,cmaxFunc);


	// PART AFTER SORT
	sort(data.begin(), data.end(), func);
	//timeMeasure(n, data, cmaxFunc);
	int afterSort = cmaxFunc(n, data);

	cout << "Przed: " << beforeSort << endl << "Po: " << afterSort << endl;
	cout << endl << endl;

	return 0;
}