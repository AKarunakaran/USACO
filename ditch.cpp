/*
ID: aman.ka1
PROG: ditch
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
    ifstream fin("ditch.in");
    ofstream fout("ditch.out");
    int n, m, v1, v2, d;
    fin >> n >> m;
    vector<vector<int>> g(m+1, vector<int>(m+1, 0));
    REP(i, n) {
    	fin >> v1 >> v2 >> d;
    	g[v1][v2] += d;
    }

    int cur = 1, ans = 0;
    while(1) {
    	/*FOR(i, 1, m) {
    		FOR(j, 1, m) cout << g[i][j] << " ";
    		cout << endl;
    	}*/
    	vector<int> prev(m+1, 0);
    	vector<int> color(m+1, 0);
    	stack<int> next;
    	next.push(1);
    	while(!next.empty()) {
    		int cur = next.top();
    		next.pop();
    		if(cur == m) break;
    		color[cur] = 2;
    		FOR(i, 1, m) {
    			if(color[i] == 0 && g[cur][i]) {
    				next.push(i);
    				prev[i] = cur;
    				color[i] = 1;
    			}
    		}
    	}
    	if(prev[m] == 0) break;
    	int cur = m, pathCap = INF;
    	while(cur != 1) {
    		pathCap = min(pathCap, g[prev[cur]][cur]);
    		cur = prev[cur];
    	}
    	//cout << pathCap << endl;
    	ans += pathCap;
    	cur = m;
    	while(cur != 1) {
    		g[prev[cur]][cur] -= pathCap;
    		g[cur][prev[cur]] += pathCap;
    		cur = prev[cur];
    	}
    }
    fout << ans << endl;

    return 0;
}
