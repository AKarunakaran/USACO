/*
ID: aman.ka1
PROG: milk2
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
    ifstream fin("milk2.in");
    ofstream fout("milk2.out");
    int n, a, b, minT = 1000000, maxT = 0;
    vector<bool> time(1000000, 0);
    fin >> n;
    REP(i, n) {
    	fin >> a >> b;
    	minT = min(minT, a);
    	maxT = max(maxT, b-1);
    	FOR(j, a, b-1) time[j] = 1;
    }
    int maxr = 0, start = minT;
    cout << maxT << " " << minT << endl;
    bool onRun = true;
    FOR(i, minT, maxT) {
    	if(onRun && !time[i]) {
    		//cout << i << " " << start << endl;
    		maxr = max(maxr, i-start);
    		onRun = false;
    	}
    	if(!onRun && time[i]) {
    		start = i;
    		onRun = true;
    	}
    }
    if(onRun) {
    	maxr = max(maxr, maxT+1-start);
    }
    fout << maxr << " ";
    maxr = 0, start = minT;
    onRun = false;
    FOR(i, minT, maxT) {
    	if(onRun && time[i]) {
    		//cout << i << " " << start << endl;
    		maxr = max(maxr, i-start);
    		onRun = false;
    	}
    	if(!onRun && !time[i]) {
    		start = i;
    		onRun = true;
    	}
    }
    fout << maxr << endl;

    return 0;
}