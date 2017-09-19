/*
ID: aman.ka1
PROG: msquare
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <unordered_set>
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }

/////////////////////////////////////////////////////////////////////

void doA(vector<int>& v) {
	int temp;
	REP(i, 4) {
		temp = v[i];
		v[i] = v[7-i];
		v[7-i] = temp;
	}
}

void undoA(vector<int>& v) {
	int temp;
	REP(i, 4) {
		temp = v[i];
		v[i] = v[7-i];
		v[7-i] = temp;
	}
}

void doB(vector<int>& v) {
	int temp = v[3];
	REP(i, 3) v[3-i] = v[2-i];
	v[0] = temp;
	temp = v[4];
	REP(i, 3) v[4+i] = v[5+i];
	v[7] = temp;
}

void undoB(vector<int>& v) {
	int temp = v[0];
	REP(i, 3) v[i] = v[i+1];
	v[3] = temp;
	temp = v[7];
	REP(i, 3) v[7-i] = v[6-i];
	v[4] = temp;
}

void doC(vector<int>& v) {
	int temp = v[1];
	v[1] = v[6];
	v[6] = v[5];
	v[5] = v[2];
	v[2] = temp;
}

void undoC(vector<int>& v) {
	int temp = v[2];
	v[2] = v[5];
	v[5] = v[6];
	v[6] = v[1];
	v[1] = temp;
}

int permToNum(const vector<int>& v) {
	int n = 0;
	REP(i, 8) n += v[i]*pow(10, i);
	return n;
}

int main() {
    ifstream fin("msquare.in");
    ofstream fout("msquare.out");
    vector<int> cur(8, 0);
    vector<int> goal(8);
    unordered_set<int> used;
    REP(i, 8) fin >> goal[i];
    REP(i, 8) cur[i] = i+1;
    int goalN = permToNum(goal), pToN;
    queue<string> next;
    next.push("");
    string curS;
    while(pToN != goalN) {
    	REP(i, 8) cur[i] = i+1;
    	curS = next.front();
    	next.pop();
    	REP(i, curS.size()) {
    		if(curS[i] == 'A') doA(cur);
    		if(curS[i] == 'B') doB(cur);
    		if(curS[i] == 'C') doC(cur);
    	}
    	pToN = permToNum(cur);
    	if(used.find(pToN) != used.end()) continue;
    	used.insert(pToN);


    	next.push(curS + "A");
    	next.push(curS + "B");
    	next.push(curS + "C");
    }

    fout << curS.size() << endl << curS << endl;

    return 0;
}
