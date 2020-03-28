#include "Algorithms.h"

int cmaxFunc(int n, vector <rpqcontainer> d) {
	int* S = new int[n];
	int* C = new int[n];
	int Cmax;

	S[0] = d[0].r;
	C[0] = S[0] + d[0].p;
	Cmax = C[0] + d[0].q;
	for (int i = 1; i < n; i++) {
		S[i] = max(d[i].r, C[i - 1]);
		C[i] = S[i] + d[i].p;
		Cmax = max(Cmax, C[i] + d[i].q);
	}

	delete[] S, C;
	return Cmax;
}

vector<rpqcontainer> Schrage(int n, vector <rpqcontainer> data) {
	int k = 0;
	vector <rpqcontainer> orderedColletion;
	int t = findMinValueR(data).r;
	vector <rpqcontainer> PI;
	rpqcontainer tmp;
	while ((orderedColletion.empty() == false) || (data.empty() == false)) {
		while ((data.empty() == false) && (findMinValueR(data).r <= t)) {
			//showVector(data);
			tmp = findMinValueR(data);
			orderedColletion.push_back(tmp);
			RemoveElement(data, tmp);
			//showVector(data);
		}
		if (orderedColletion.empty() == false) {
			tmp = findMaxValueQ(orderedColletion);
			RemoveElement(orderedColletion, tmp);
			PI.push_back(tmp);
			t = t + tmp.p;
			k = k + 1;
		}
		else {
			t = findMinValueR(data).r;
		}
	}
	return PI;
}

vector<rpqcontainer> schrageWithQueue(int n, vector <rpqcontainer> data) {
	int k = 0;
	priority_queue<rpqcontainer, vector<rpqcontainer>, CompareQ> queue;
	sort(data.begin(), data.end(), func3);
	int t = data.back().r;
	vector <rpqcontainer> PI;
	rpqcontainer tmp;
	while ((queue.empty() == false) || (data.empty() == false)) {
		while ((data.empty() == false) && (data.back().r <= t)) {

			tmp = data.back();
			queue.push(tmp);
			data.pop_back();
		}
		if (queue.empty() == false) {
			tmp = queue.top();
			queue.pop();
			PI.push_back(tmp);
			t = t + tmp.p;
			k = k + 1;
		}
		else {
			t = data.back().r;
		}
	}
	return PI;
}



// SCHRAGE PMTN

int schragePMTN(int n, vector <rpqcontainer> data) {
	
	int k = 0;
	int Cmax = 0;
	vector <rpqcontainer> orderedColletion;
	int t = 0; 
	vector <rpqcontainer> PI;
	rpqcontainer l;
	l.q=numeric_limits<int>::max(); // INFINITY
	rpqcontainer tmp, tmp2; //just to help
	// cout << "TMP 1 "<< "R: " << tmp.r << " P: " << tmp.p << " Q: " << tmp.q << endl;

	while ((orderedColletion.empty() == false) || (data.empty() == false)) {
		while ((data.empty() == false) && (findMinValueR(data).r <= t)) {
			
			//cout << "WEKTOR N_N" << endl;
			//showVector(data);
			//cout << "KONIEC N_N" << endl;
			
			tmp = findMinValueR(data);
			//cout << "TMP 1 " << "R: " << tmp.r << " P: " << tmp.p << " Q: " << tmp.q << endl;
			orderedColletion.push_back(tmp);
			RemoveElement(data, tmp);
			 /*cout << "TMP 2 "<< "R: " << tmp.r << " P: " << tmp.p << " Q: " << tmp.q << endl;*/
			
			 if (tmp.q > l.q) { //block added in PTMN
				l.p = t - tmp.r;
				t = tmp.r;
				if (l.p > 0) {
					// cout << "TMP 2 "<< "R: " << tmp.r << " P: " << tmp.p << " Q: " << tmp.q << endl;
					orderedColletion.push_back(tmp);
				}
			} 
		}
		if (orderedColletion.empty() == false) {
			/*cout << "WEKTOR N_G" << endl;
			showVector(orderedColletion);
			cout << "KONIEC N_G" << endl;*/

			tmp2 = findMaxValueQ(orderedColletion);
			/*cout << "TMP 1 " << "R: " << tmp2.r << " P: " << tmp2.p << " Q: " << tmp2.q << endl;*/
			
			RemoveElement(orderedColletion, tmp2);
			/*cout << "TMP 2 R: " << tmp2.r << " P: " << tmp2.p << " Q: " << tmp2.q << endl;*/
			
			/*cout << "WEKTOR N_G 2" << endl;
			showVector(orderedColletion);
			cout << "KONIEC N_G 2" << endl << endl;*/

			PI.push_back(tmp2);
			l = tmp2;
			t = t + tmp2.p;
			Cmax = max(Cmax, t + tmp2.q);
			k = k + 1;
		}
		else {
			t = findMinValueR(data).r;
		}
	}
	int pies = cmaxFunc(n, PI);
	cout << "PIES: " << pies << endl;
	return Cmax;
}

// SCHRAGE PMTN WITH QUEUE 

int schragePMTNWithQueue(int n, vector <rpqcontainer> data) {

	//special structures to use in schrage algorithm:
	priority_queue<rpqcontainer, vector<rpqcontainer>, CompareQ> queue;
	sort(data.begin(), data.end(), func3);	
	// used variables
	int Cmax = 0;
	int t = 0;
	rpqcontainer l;
	l.q = numeric_limits<int>::max(); // INFINITY
	rpqcontainer tmp;

	while ((queue.empty() == false) || (data.empty() == false)) {
		while ((data.empty() == false) && (data.back().r <= t)) {
			tmp = data.back();
			queue.push(tmp);
			data.pop_back();
			//cout << "QUEUE TMP 1 R: " << tmp.r << " P: " << tmp.p << " Q: " << tmp.q << endl;
			if (tmp.q > l.q) { //block added in PTMN
				l.p = t - tmp.r;
				t = tmp.r;
				if (l.p > 0) {
					queue.push(tmp);
				}
			}
		}
		if (queue.empty() == false) {
			tmp = queue.top();
			queue.pop();
			//cout << "QUEUE TMP2: R: " << tmp.r << " P: " << tmp.p << " Q: " << tmp.q << endl;
			
			l = tmp;
			t = t + tmp.p;
			Cmax = max(Cmax, t + tmp.q);
		}
		else {
			t = data.back().r;
		}
	}
	return Cmax;
}

