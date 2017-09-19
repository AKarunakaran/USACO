/*
ID: aman.ka1
PROG: transform
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

int n;

void print(const vector< vector<bool> >& p) {
	REP(i, n) {
		REP(j, n) cout << ((p[i][j]) ? '@' : '-');
		cout << endl;
	}
}

bool equal(const vector< vector<bool> >& p1, const vector< vector<bool> >& p2) {
	bool eq = true;
	REP(i, n) {
		REP(j, n) {
			if(p1[i][j] != p2[i][j]) {
				eq = false;
				break;
			}
		}
	}
	return eq;
}

bool transform1(const vector< vector<bool> >& p1, const vector< vector<bool> >& p2) {
	vector< vector<bool> > tp(n, vector<bool>(n, 0));
	REP(i, n) REP(j, n) tp[j][n-1-i] = p1[i][j];
	//print(tp);
	return equal(tp, p2);
}

bool transform2(const vector< vector<bool> >& p1, const vector< vector<bool> >& p2) {
	vector< vector<bool> > tp(n, vector<bool>(n, 0));
	REP(i, n) REP(j, n) tp[n-1-i][n-1-j] = p1[i][j];
	//print(tp);
	return equal(tp, p2);
}

bool transform3(const vector< vector<bool> >& p1, const vector< vector<bool> >& p2) {
	vector< vector<bool> > tp(n, vector<bool>(n, 0));
	REP(i, n) REP(j, n) tp[n-1-j][i] = p1[i][j];
	//print(tp);
	return equal(tp, p2);
}

bool transform4(const vector< vector<bool> >& p1, const vector< vector<bool> >& p2) {
	vector< vector<bool> > tp(n, vector<bool>(n, 0));
	REP(i, n) REP(j, n) tp[i][n-1-j] = p1[i][j];
	//print(tp);
	return equal(tp, p2);
}

bool transform5(const vector< vector<bool> >& p1, const vector< vector<bool> >& p2) {
	vector< vector<bool> > tp(n, vector<bool>(n, 0));
	REP(i, n) REP(j, n) tp[i][n-1-j] = p1[i][j];
	if(transform1(tp, p2)) return true;
	if(transform2(tp, p2)) return true;
	if(transform3(tp, p2)) return true;
	return false;
}

int main() {
    ifstream fin("transform.in");
    ofstream fout("transform.out");
    fin >> n;
    vector< vector<bool> > p1(n, vector<bool>(n, 0)), p2(n, vector<bool>(n, 0));
    char c;
    REP(i, n) {
    	REP(j, n) {
    		fin >> c;
    		p1[i][j] = (c == '@');
    	}
    }
    REP(i, n) {
    	REP(j, n) {
    		fin >> c;
    		p2[i][j] = (c == '@');
    	}
    }

    if (transform1(p1, p2)) {
    	fout << 1 << endl;
    } else if (transform2(p1, p2)) {
    	fout << 2 << endl;
    } else if (transform3(p1, p2)) {
    	fout << 3 << endl;
    } else if (transform4(p1, p2)) {
    	fout << 4 << endl;
    } else if (transform5(p1, p2)) {
    	fout << 5 << endl;
    } else if (equal(p1, p2)) {
    	fout << 6 << endl;
    } else {
    	fout << 7 << endl;
    }

    return 0;
}