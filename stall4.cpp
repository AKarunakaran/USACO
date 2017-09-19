/*
ID: aman.ka1
PROG: stall4
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
    ifstream fin("stall4.in");
    ofstream fout("stall4.out");
    int n, m, numS, s;
    fin >> n >> m;
    vector<vector<bool>> g(n+m+2, vector<bool>(n+m+2, 0));
    REP(i, n) {
    	fin >> numS;
    	REP(j, numS) {
    		fin >> s;
    		g[i+1][s+n] = 1;
    	}
    }
    FOR(i, 1, n) g[0][i] = 1;
    FOR(i, n+1, n+m) g[i][n+m+1] = 1;

    int ans = 0;
    while(1) {
    	/*REP(i, n+m+2) {
    		REP(j, n+m+2) cout << g[i][j] << " ";
    		cout << endl;
    	}*/
    	vector<int> prev(n+m+2, -1);
    	vector<int> color(n+m+2, 0);
    	stack<int> next;
    	next.push(0);
    	while(!next.empty()) {
    		int cur = next.top();
    		next.pop();
    		if(cur == n+m+1) break;
    		color[cur] = 2;
    		FOR(i, 1, n+m+1) {
    			if(color[i] == 0 && g[cur][i]) {
    				next.push(i);
    				prev[i] = cur;
    				color[i] = 1;
    			}
    		}
    	}
    	if(prev[n+m+1] == -1) break;
    	int cur = n+m+1;
    	++ans;
    	while(cur != 0) {
    		g[prev[cur]][cur] = 0;
    		g[cur][prev[cur]] = 1;
    		cur = prev[cur];
    	}
    }
    fout << ans << endl;

    return 0;
}
