/*
ID: aman.ka1
PROG: race3
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

int dijkstra(const vector< vector<int> >& g, int src, int tgt, int ex, vector<bool>& chk) {
    vector<int> dist(g.size(), INF);
    bool reset = false;
    if(chk.size() == 0) {
        chk.resize(g.size(), 0);
        reset = true;
    }
    dist[src] = 0;
    chk[src] = 1;
    queue<int> next;
    next.push(src);
    while(!next.empty()) {
        int cur = next.front();
        if(cur == tgt) {
            if(reset) chk.resize(0);
            return dist[cur];
        }
        next.pop();
        REP(i, g[cur].size()) {
            if(g[cur][i] != ex && !chk[g[cur][i]]) {
            	chk[g[cur][i]] = 1;
            	next.push(g[cur][i]);
                dist[g[cur][i]] = dist[cur] + 1;
            }
        }
    }
    if(reset) chk.resize(0);
    return INF;
}

int main() {
    ifstream fin("race3.in");
    ofstream fout("race3.out");
    //Remove each vertex and try to do start->finish to find unavoidable points
    //Try each unavoidable point as splitting point
    	//do BFS on 0->splitting test, and then BFS on splitting test->end
    	//if two sets of reachable vertices are disjoint, then it's splitting point    
    int temp = -2, n = 0;
    vector<vector<int>> g(50);
    while(temp == -2) {
    	fin >> temp;
    	if(temp == -1) break;
    	while(temp != -2) {
    		g[n].push_back(temp);
    		fin >> temp;
    	}
    	++n;
    }
    g.resize(n);
    --n;
    vector<int> unavoidable;
    vector<bool> chk;
    FOR(i, 1, n-1) if(dijkstra(g, 0, n, i, chk) == INF) unavoidable.push_back(i);

    vector<int> splitting;
    REP(i, unavoidable.size()) {
        vector<bool> chkA(n+1, 0), chkB(n+1, 0);
        dijkstra(g, 0, -1, unavoidable[i], chkA);
        dijkstra(g, unavoidable[i], -1, -1, chkB);
	    bool good = true;
	    REP(i, n+1) {
	    	if(chkA[i] == chkB[i]) {
	    		good = false;
	    		break;
	    	}
	    }
	    if(good) splitting.push_back(unavoidable[i]);
    }

    fout << unavoidable.size();
    REP(i, unavoidable.size()) fout << " " << unavoidable[i];
    fout << endl;
    
    fout << splitting.size();
    REP(i, splitting.size()) fout << " " << splitting[i];
    fout << endl;

    return 0;
}
