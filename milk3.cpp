/*
ID: aman.ka1
PROG: milk3
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

int acap, bcap, ccap;

bool seen[21][21][21];

void perm(int a, int b, int c, int act, vector<bool>& sol) {
	int d;

	if(act == 1) {
		d = min(a, bcap-b);
		a -= d;
		b += d;
	}
	if(act == 2) {
		d = min(a, ccap-c);
		a -= d;
		c += d;
	}
	if(act == 3) {
		d = min(b, ccap-c);
		b -= d;
		c += d;
	}
	if(act == 4) {
		d = min(b, acap-a);
		b -= d;
		a += d;
	}
	if(act == 5) {
		d = min(c, acap-a);
		c -= d;
		a += d;
	}
	if(act == 6) {
		d = min(c, bcap-b);
		c -= d;
		b += d;
	}

	if(seen[a][b][c]) {
		return;
	} else {
		seen[a][b][c] = true;
	}

	if(a == 0) {
		sol[c] = true;
	}
	FOR(i, 1, 6) {
		perm(a, b, c, i, sol);
	}
}

int main() {
    ifstream fin("milk3.in");
    ofstream fout("milk3.out");
    fin >> acap >> bcap >> ccap;
    vector<bool> sol(ccap+1, false);
    REP(i, acap+1) REP(j, bcap+1) REP(k, ccap+1) seen[i][j][k] = 0;

    perm(0, 0, ccap, 0, sol);

    int last;
    for(last = ccap; last >= 1; --last) if(sol[last]) break;
    FOR(i, 0, last-1) if(sol[i]) fout << i << " ";
    fout << last << endl;

    return 0;
}
