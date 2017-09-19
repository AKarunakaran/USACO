/*
ID: aman.ka1
PROG: game1
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
    ifstream fin("game1.in");
    ofstream fout("game1.out");
    int n;
    fin >> n;
    vector<vector<int>> sum(n, vector<int>(n, 0)), dp(n, vector<int>(n, 0));
    REP(i, n) {
    	fin >> sum[i][i];
    	dp[i][i] = sum[i][i];
    }
    REP(i, n-1) {
    	FOR(j, i+1, n-1) {
    		sum[i][j] = sum[i][j-1]+sum[j][j];
    	}
    }
    FOR(i, 1, n-1) {
    	REP(j, n-i) {
    		dp[j][j+i] = sum[j][j+i]-min(dp[j+1][j+i], dp[j][j+i-1]);
    	}
    }

    fout << dp[0][n-1] << " " << sum[0][n-1]-dp[0][n-1] << endl;

    return 0;
}
