/*
ID: aman.ka1
PROG: money
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
    ifstream fin("money.in");
    ofstream fout("money.out");
    int v, n;
    fin >> v >> n;
    vector<int> coins(v);
    REP(i, v) fin >> coins[i];
    vector<vector<ull>> dp(v+1, vector<ull>(n+1, 0));
    FOR(i, 0, v) {
    	dp[i][0] = 1;
    }
    FOR(i, 1, v) {
    	FOR(j, 1, n) {
    		int k = 0;
    		while(j-k*coins[i-1] >= 0) {
    			dp[i][j] += dp[i-1][j-k*coins[i-1]];
    			++k;
    		}
    	}
    }
    /*REP(j, v+1) {
    	REP(i, n+1) cout << dp[j][i] << " ";
    	cout << endl;
    }*/
    fout << dp[v][n] << endl;

    return 0;
}
