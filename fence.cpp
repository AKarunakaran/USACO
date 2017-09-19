/*
ID: aman.ka1
PROG: fence
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

vector<vector<int>> g(501);
vector<int> sol;
stack<int> st;

void findCirc(int loc) {
	//cout << loc << endl;
	if(g[loc].size() == 0) {
		sol.push_back(loc);
	} else {
		while(g[loc].size()) {
			int minV = 0, next = g[loc][0];
			REP(i, g[loc].size()) {
				if(g[loc][i] < next) {
					next = g[loc][i];
					minV = i;
				}
			}
			REP(i, g[next].size()) {
				if(g[next][i] == loc) {
					g[next].erase(g[next].begin() + i);
					break;
				}
			}
			g[loc].erase(g[loc].begin() + minV);
			findCirc(next);
		}
		sol.push_back(loc);
	}
}

int main() {
    ifstream fin("fence.in");
    ofstream fout("fence.out");
    int f, a, b, n = 0, cur;
    fin >> f;
    REP(i, f) {
    	fin >> a >> b;
    	g[a].push_back(b);
    	g[b].push_back(a);
    	n = max(n, max(a, b));
    }

    int start = 1;
    FOR(i, 1, n) {
    	if(g[i].size() % 2 == 1) {
    		start = i;
    		break;
    	}
    }

    findCirc(start);

    FORD(i, sol.size()-1, 0) fout << sol[i] << endl;

    return 0;
}
