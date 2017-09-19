/*
ID: aman.ka1
PROG: prefix
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
    ifstream fin("prefix.in");
    ofstream fout("prefix.out");
    vector<string> prim;
    string in, s;
    fin >> in;
    while(in != ".") {
    	prim.push_back(in);
    	fin >> in;
    }
    fin >> s;
    fin >> in;
    while(fin.good()) {
    	s += in;
    	fin >> in;
    }
    vector<bool> dp(s.size()+1, 0);
    dp[0] = 1;
    int k = 0;
    REP(i, dp.size()) {
    	if(dp[i]) {
    		k = i;
    		REP(j, prim.size()) {
    			int k = 0;
	    		while(k < prim[j].size()) {
	    			if(s[i+k] != prim[j][k]) break;
	    			++k;
	    		}
	    		if(k == prim[j].size()) dp[i+prim[j].size()] = 1;
	    	}
	    	//REP(j, dp.size()) cout << dp[j];
	    	//cout << endl;
    	}
    }
    fout << k << endl;

    return 0;
}
