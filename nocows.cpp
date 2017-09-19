/*
ID: aman.ka1
PROG: nocows
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
    ifstream fin("nocows.in");
    ofstream fout("nocows.out");
    int n, k;
    fin >> n >> k;
    if(n < 2*k-1 || (k <= 7 && n >= two(k)) || n%2 == 0) {
    	fout << 0 << endl;
    	return 0;
    }
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    dp[1][1] = 1;
    FOR(i, 1, n) {
    	FOR(j, 2, k) {
    		if(i < 2*j-1 || (i <= 7 && i >= two(j)) || i%2 == 0) continue;
    		//DEBUG(i);
    		//DEBUG(j);
    		FOR(m, 1, i-1) {
    			FOR(n, 1, j-2) {
    				dp[i][j] = (dp[i][j]+2*dp[m][j-1]*dp[i-1-m][n])%9901;
    			}
    			dp[i][j] = (dp[i][j]+dp[m][j-1]*dp[i-1-m][j-1])%9901;
    		}
    	}
    }
    /*REP(i, n+1) {
    	REP(j, k+1) {
    		cout << dp[i][j] << " ";
    	}
    	cout << endl;
    }*/
    fout << dp[n][k] << endl;

    return 0;
}
