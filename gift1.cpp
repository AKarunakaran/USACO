/*
ID: aman.ka1
PROG: gift1
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
#include <unordered_map>
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
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");
    int p, g, m, idx, idx2;
    fin >> p;
    string s, s2;
    unordered_map<string, int> idcs;
    vector<string> names(p);
    vector<int> money(p, 0);
    vector<int> give(p, 0);
    vector<int> rec(p, 0);
    REP(i, p) {
    	fin >> s;
    	cout << s << endl;
    	names[i] = s;
    	idcs[s] = i;
    }
    REP(i, p) {
    	fin >> s >> m >> g;
    	cout << s << " " << g << " " << m << endl;
    	if(g != 0) {
    		idx = idcs[s];
	    	money[idx] = m;
	    	give[idx] = m/g*g;
	    	REP(j, g) {
	    		fin >> s2;
	    		cout << j << " " << s2 << endl;
	    		idx2 = idcs[s2];
	    		rec[idx2] += m/g;
	    	}
    	}
    }
    REP(i, p) fout << names[i] << " " << rec[i] - give[i] << endl;

    return 0;
}