/*
ID: aman.ka1
PROG: theme
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

int n;

int pairConv(int a, int b) {
	return n*a+b;
}

int main() {
    ifstream fin("theme.in");
    ofstream fout("theme.out");
    int ans = 0;
    fin >> n;
    vector<int> notes(n);
    REP(i, n) fin >> notes[i];
    vector<int> diff(n, 89);
    FOR(i, 1, n-1) diff[i] = notes[i]-notes[i-1];
    unordered_map<int, int> longM;

    FORD(i, n-1, 1) {
    	FORD(j, i-1, 0) {
    		if(diff[i] == diff[j]) {
    			if(longM.find(pairConv(i+1, j+1)) == longM.end()) {
    				longM[pairConv(i, j)] = 1;
    			} else {
    				longM[pairConv(i, j)] = min(i-j-1, 1+longM[pairConv(i+1, j+1)]);
    				ans = max(ans, longM[pairConv(i, j)]);
    			}
    		}
    	}
    }
    /*REP(i, n) {
    	REP(j, n) cout << dp[i][j] << " ";
    	cout << endl;
    }*/
    fout << ((ans+1 >= 5) ? ans+1 : 0) << endl;
    

    return 0;
}
