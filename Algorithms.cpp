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
	vector <rpqcontainer> orderedColletion;
	int t = 0;
	rpqcontainer l;
	l.q=numeric_limits<int>::max(); // INFINITY
	rpqcontainer tmp; //just to help

	while ((orderedColletion.empty() == false) || (data.empty() == false)) {
		while ((data.empty() == false) && (findMinValueR(data).r <= t)) {
			tmp = findMinValueR(data);
			orderedColletion.push_back(tmp);
			RemoveElement(data, tmp);
			
			 if (tmp.q > l.q) { //block added in PTMN
				l.p = t - tmp.r;
				t = tmp.r;
				if (l.p > 0) {
					orderedColletion.push_back(l);
				}
			} 
		}
		if (orderedColletion.empty() == false) {
			tmp = findMaxValueQ(orderedColletion);
			RemoveElement(orderedColletion, tmp);
			l = tmp;
			t = t + tmp.p;
			Cmax = max(Cmax, t + tmp.q);
		}
		else {
			t = findMinValueR(data).r;
		}
	}
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
			if (tmp.q > l.q) { //block added in PTMN
				l.p = t - tmp.r;
				t = tmp.r;
				if (l.p > 0) {
					queue.push(l);
				}
			}
		}
		if (queue.empty() == false) {
			tmp = queue.top();
			queue.pop();
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

int findBMax(int n, vector <rpqcontainer> pi, int Cmax) {
	
	int bMaxIndex = 0;
	int* S = new int[n];
	int* C = new int[n];

	S[0] = pi[0].r;
	C[0] = S[0] + pi[0].p;

	for (int i = 1; i < n; i++) {
		S[i] = max(pi[i].r, C[i - 1]);
		C[i] = S[i] + pi[i].p;
		
		if (C[i] + pi[i].q == Cmax) {
			bMaxIndex = max(i, bMaxIndex);
		}
	}

	delete[] S, C;
	return bMaxIndex;
}

int findAMin(int n, int b, vector<rpqcontainer> pi, int Cmax) {
	int aMinIndex=10000000;
	int sum;
	for (int i = 0; i < b; i++) {
		sum = 0;
		for (int j = i; j <= b; j++) {
			sum = pi[j].p + sum;
		}
		if (pi[i].r + sum + pi[b].q == Cmax) {
			aMinIndex = min(i,aMinIndex);
		}
	}

	return aMinIndex;
}

int findCMax(int n, int a, int b, vector<rpqcontainer> pi){
	int cMaxIndex=0;
	bool cExist=false;
	for (int i = a; i < b; i++) {
		if (pi[i].q < pi[b].q) {
			cMaxIndex = max(i, cMaxIndex); // maybe sth else here
			cExist = true;
		}
	}
	if (cExist == true) {
		return cMaxIndex;
	}
	else {
		return -1;
	}
}

vector<rpqcontainer> initiateKVec(int n, int b, int c, vector<rpqcontainer> pi) {
	vector <rpqcontainer> K;
	for (int i = c+1; i <= b; i++) {
		K.push_back(pi[i]);
	}

	return K;
}

int sumP(vector <rpqcontainer> K) {
	int sumPValue = 0;
	for (int i = 0; i < K.size(); i++) {
		sumPValue = K[i].p+sumPValue;
	}
	return sumPValue;
}

bool  endOfCarlier = false;
vector<rpqcontainer> piStar;

vector <rpqcontainer> Carlier(int n, vector <rpqcontainer> data) {
	if (endOfCarlier == false) {
		//vector<rpqcontainer> pi = Schrage(n, data);
		
		int upperBand = cmaxFunc(n, data);
		int lowerBand;
		data = Schrage(n, data);
		int Cmax = cmaxFunc(n, data);
		//cout << "Cmax: " << Cmax << endl;
		int U = Cmax;
		if (U < upperBand) {
			upperBand = U;
			piStar = data;
		}
		int b = findBMax(n, data, Cmax);
		//cout << "b = " << b << endl;
		int a = findAMin(n, b, data, Cmax);
		//cout << "a: " << a << endl;
		int c = findCMax(n, a, b, data);
		//cout << "c: " << c << endl;
		if (c == -1) {
			endOfCarlier = true;
			return piStar;
		}
		else {
			vector<rpqcontainer> K;
			K = initiateKVec(n, b, c, data);
			int r_ = findMinValueR(K).r;
			int q_ = findMinValueQ(K).q;
			int p_ = sumP(K);

			int rToRestore = data[c].r;
			data[c].r = max(data[c].r, r_ + p_);
			lowerBand = schragePMTN(n, data);
			if (lowerBand < upperBand) {
				Carlier(n, data);
			}
			data[c].r = rToRestore;

			int qToRestore = data[c].q;
			data[c].q = max(data[c].q, q_ + p_);
			lowerBand = schragePMTN(n, data);
			if (lowerBand < upperBand) {
				Carlier(n, data);
			}
			data[c].q = qToRestore;
		}
	}
	return piStar;
} //end of Cariler
