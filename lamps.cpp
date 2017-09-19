/*
ID: aman.ka1
PROG: lamps
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

int main() {
    ifstream fin("lamps.in");
    ofstream fout("lamps.out");
    int n, c;
    fin >> n >> c;
    int in;
    vector<int> on, off;
    fin >> in;
    while(in != -1) {
    	on.push_back(in-1);
    	fin >> in;
    }
    fin >> in;
    while(in != -1) {
    	off.push_back(in-1);
    	fin >> in;
    }
    vector<vector<bool>> sol;
    vector<int> poss;
    if(c == 0) {
    	poss.push_back(0);
    } else if(c == 1) {
    	poss.push_back(1);
    	poss.push_back(2);
    	poss.push_back(8);
    	poss.push_back(4);
    	poss.push_back(0);
    } else {
    	poss.push_back(1);
    	poss.push_back(11);
    	poss.push_back(2);
    	poss.push_back(8);
    	poss.push_back(9);
    	poss.push_back(3);
    	poss.push_back(10);
    	poss.push_back(0);
    }
    REP(i, poss.size()) {
    	int perm = poss[i];
    	vector<bool> lamps(n, 1);
    	if(perm & 1) {
    		REP(j, n) lamps[j] = !lamps[j];
    	}
    	if(perm & 2) {
    		for(int j = 0; j < n; j += 2) lamps[j] = !lamps[j];
    	}
    	if(perm & 4) {
    		for(int j = 1; j < n; j += 2) lamps[j] = !lamps[j];
    	}
    	if(perm & 8) {
    		for(int j = 0; j < n; j += 3) lamps[j] = !lamps[j];
    	}
    	DEBUG(perm);
    	REP(j, n) cout << lamps[j];
    	cout << endl;
    	bool good = true;
    	REP(j, on.size()) if(!lamps[on[j]]) good = false;
    	REP(j, off.size()) if(lamps[off[j]]) good = false;
    	if(!good) continue;
    	sol.push_back(lamps);
    }
    if(sol.size()) {
    	sort(sol.begin(), sol.end());
    	REP(i, sol.size()) {
	    	REP(j, n) fout << sol[i][j];
	    	fout << endl;
    	}
    } else fout << "IMPOSSIBLE" << endl;

    return 0;
}
