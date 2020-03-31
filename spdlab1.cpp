#include "utility.h"
#include "Algorithms.h"
#include "time.h"
#include <ctime>

using namespace std;

auto timeMeasure1(int n, vector <rpqcontainer> data, int(*function)(int, vector <rpqcontainer>)) {
	auto start = std::chrono::high_resolution_clock::now();
	function(n, data);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	//cout << "Czas wykonywania sie algorytmu:" << duration.count() << endl;
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

// CARLIER : 641 ,1267, 1492, 3070, 6398 dla 10, 20, 50, 100, 200
int main()
{
	vector <rpqcontainer> data;
	int n;
	int parameters;
	tie(n, parameters, data) = getDataFromFile("data100.txt"); 

	//********************CARLIER
	vector <rpqcontainer> carlier = Carlier(n, data);
	int carpom = cmaxFunc(n,carlier);
	cout << "CARLIER: " << carpom << endl;
	auto timeCarlier = timeMeasure2(n, data, Schrage);
	cout << "TIME CARLIER: " << timeCarlier.count() << endl;

	//// ************************* SCHRAGE
	vector <rpqcontainer> pom = Schrage(n, data);
	int schrag = cmaxFunc(n, pom);
	cout << "SCHRAGE: " << schrag << endl;
	auto timeSchrage = timeMeasure2(n, data, Schrage);
	cout << "TIME SCHRAGE ZWYKLE: " << timeSchrage.count() << endl;
	
	// ********************* SCHRAGE WITH QUEUE
	vector <rpqcontainer> pom2 = schrageWithQueue(n, data);
    int schrag2 = cmaxFunc(n, pom2);
	cout << "SCHRAGE WITH QUEUE: " << schrag2 << endl;
	auto timeSchrageWithQueue = timeMeasure2(n, data, schrageWithQueue);
	cout << "TIME SCHRAGE WITH QUEUE: " << timeSchrageWithQueue.count() << endl;
	
	//********************* SCHRAGE PTMN
	int schragPMTN = schragePMTN(n, data);
	cout << "SCHRAGE PMTN: " << schragPMTN << endl;
	auto timeSchragePMTN = timeMeasure1(n, data, schragePMTN);
	cout << "TIME SCHRAGE PMTN: " << timeSchragePMTN.count() << endl;

	// ********************** SCHRAGE PTMN WITH QUEUE
	int schragPMTNWithQueue = schragePMTNWithQueue(n, data);
	cout << "SCHRAGE PMTN WITH QUEUE: " << schragPMTNWithQueue << endl;
	auto timeSchragePMTNWithQueue = timeMeasure1(n, data, schragePMTNWithQueue);
	cout << "TIME SCHRAGE PMTN WITH QUEUE: " << timeSchragePMTNWithQueue.count() << endl;
	// **************** PART BEFORE SORT
	auto timeBeforeSort = timeMeasure1(n, data, cmaxFunc);
	cout << "TIME BEFORE SORT: " << timeBeforeSort.count() << endl;
	int beforeSort = cmaxFunc(n, data);

	//********************8 PART AFTER SORT
	sort(data.begin(), data.end(), func);
	auto timeAfterSort = timeMeasure1(n, data, cmaxFunc);
	cout << "TIME AFTER SORT: " << timeAfterSort.count() << endl;
	
	int afterSort = cmaxFunc(n, data);

	cout << "Przed: " << beforeSort << endl << "Po: " << afterSort << endl;
	cout << endl << endl;

	return 0;
}