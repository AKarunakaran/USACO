/*
ID: aman.ka1
PROG: kimbits
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
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }

/////////////////////////////////////////////////////////////////////

int main() {
    ifstream fin("kimbits.in");
    ofstream fout("kimbits.out");
    ll n, l, i;
    fin >> n >> l >> i;
    vector<vector<ll>> dp(n+1, vector<ll>(l+1, 0));
    FOR(j, 0, n) dp[j][0] = 1;
    FOR(j, 0, l) dp[0][j] = 1;
    FOR(j, 1, n) {
        FOR(k, 1, l) {
            dp[j][k] = dp[j-1][k] + dp[j-1][k-1];
        }
    }
    /*REP(j, n+1) {
        REP(k, l+1) {
            cout << dp[j][k] << " ";
        }
        cout << endl;
    }*/

    ll k = l;
    FORD(j, n-1, 0) {
        //DEBUG(i);
        //DEBUG(dp[j][k]);
        if(i > dp[j][k]) {
            i -= dp[j][k];
            --k;
            fout << 1;
        } else {
            fout << 0;
        }
    }
    fout << endl;

    return 0;
}
