/*
ID: aman.ka1
PROG: numtri
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

int tri[1000][1000];
int dp[1000][1000];

int main() {
    ifstream fin("numtri.in");
    ofstream fout("numtri.out");
    int r, in;
    fin >> r;
    REP(i, r) {
    	REP(j, i+1) {
    		fin >> tri[i][j];
    		dp[i][j] = -1;
    	}
    }
    dp[0][0] = tri[0][0];
    FOR(i, 1, r-1) {
    	dp[i][0] = tri[i][0] + dp[i-1][0];
    	dp[i][i] = tri[i][i] + dp[i-1][i-1];
    }
    FOR(i, 2, r-1) {
    	FOR(j, 1, i-1) {
    		dp[i][j] = tri[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
    	}
    }

    /*FOR(i, 0, r-1) {
    	FOR(j, 0, i) {
    		cout << dp[i][j] << " ";
    	}
    	cout << endl;
    }*/
    int ans = 0;
    REP(i, r) ans = max(ans, dp[r-1][i]);
    fout << ans << endl;

    return 0;
}
