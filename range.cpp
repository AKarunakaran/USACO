/*
ID: aman.ka1
PROG: range
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
    ifstream fin("range.in");
    ofstream fout("range.out");
    int n;
    fin >> n;
    vector<vector<bool>> g(n, vector<bool>(n));
    char c;
    REP(i, n) {
    	REP(j, n) {
    		fin >> c;
    		g[i][j] = (c == '1');
    	}
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<int> ans(n+1, 0);
    
    REP(i, n) REP(j, n) dp[i][j] = g[i][j];

    FOR(m, 2, n) {
    	REP(i, n-m+1) {
    		REP(j, n-m+1) {
    			if(dp[i][j] == m-1 && dp[i+1][j] == m-1 && dp[i][j+1] == m-1 && g[i+m-1][j+m-1]) {
    				++dp[i][j];
    			}
    		}
    	}
    }

    REP(i, n) REP(j, n) FOR(k, 2, dp[i][j]) ++ans[k];
    FOR(i, 2, n) {
    	if(ans[i] == 0) break;
    	fout << i << " " << ans[i] << endl;
    }

    return 0;
}
