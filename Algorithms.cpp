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
	int Cmax = 0;
	int k = 0;
	vector <rpqcontainer> orderedColletion;
	int t = 0; //findMinValueR(data).r
	vector <rpqcontainer> PI;
	rpqcontainer l;
	l.q=numeric_limits<int>::max();
	rpqcontainer tmp;
	while ((orderedColletion.empty() == false) || (data.empty() == false)) {
		while ((data.empty() == false) && (findMinValueR(data).r <= t)) {
			tmp = findMinValueR(data);
			orderedColletion.push_back(tmp);
			RemoveElement(data, tmp);
	
			if (tmp.q>l.q) { //block added in PTMN
				l.p = t - tmp.r;
				t = tmp.r;
				if (l.p > 0) {
					orderedColletion.push_back(tmp);
				}
			} 

		}
		if (orderedColletion.empty() == false) {
			tmp = findMaxValueQ(orderedColletion);
			RemoveElement(orderedColletion, tmp);
			PI.push_back(tmp);
			l = tmp;
			t = t + tmp.p;
			k = k + 1;
			Cmax = max(Cmax, t+tmp.q);
		}
		else {
			t = findMinValueR(data).r;
		}
	}
	return Cmax;
}

