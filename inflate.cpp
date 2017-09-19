/*
ID: aman.ka1
PROG: inflate
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
    ifstream fin("inflate.in");
    ofstream fout("inflate.out");
    int m, n;
    fin >> m >> n;
    vector<pair<int, int>> probs(n);
    REP(i, n) fin >> probs[i].first >> probs[i].second;
    sort(probs.begin(), probs.end(), [](pair<int, int>& left, pair<int, int>& right){return left.second < right.second;});
    vector<int> dp(m+1, 0);
    FOR(i, 1, m) {
    	REP(j, n) {
    		if(probs[j].second > i) break;
    		dp[i] = max(dp[i], probs[j].first+dp[i-probs[j].second]);
    	}
    }
    fout << dp[m] << endl;

    return 0;
}
