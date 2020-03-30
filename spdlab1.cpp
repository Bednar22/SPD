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

// CARLIER : 641 ,1267, 1492, 3070, 6398 dla 10, 20, 50, 100, 200
int main()
{
	vector <rpqcontainer> data;
	int n;
	int parameters;
	tie(n, parameters, data) = getDataFromFile("data10.txt"); 
	
	//// ************* TEST
	vector <rpqcontainer> test2;
	vector <rpqcontainer> test;
	rpqcontainer t1(1,2,5);
	rpqcontainer t2(2,3,4);
	rpqcontainer t3(8,1,6);
	rpqcontainer t4(7,2,3);
	rpqcontainer t5(6,3,7);
	rpqcontainer t6(4,4,1);
	test.push_back(t1);
	test.push_back(t2);
	test.push_back(t3);
	test.push_back(t4);
	test.push_back(t5);
	test.push_back(t6);
	//test2 = Carlier(6, test);
	////test = Schrage(6, test);
	//int Cmaxx = cmaxFunc(6, test2);
	//showVector(test);
	//cout << "CMAX = : " << Cmaxx << endl;
	/*int bmax = findBMax(6, test, Cmaxx);
	int amin = findAMin(6, bmax, test ,Cmaxx);
	int cmaxx = findCMax(6, amin, bmax, test);*/
	//cout << "BMAX = " << bmax << " A MIN: " << amin << " C MAX: " << cmaxx << endl << endl;
	//************************ KONIEC TESTU



	//CARLIER
	vector <rpqcontainer> carlier = Carlier(n, data);
	int carpom = cmaxFunc(n,carlier);
	cout << "CARLIER: " << carpom << endl;

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