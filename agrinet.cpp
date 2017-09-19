/*
ID: aman.ka1
PROG: agrinet
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
    ifstream fin("agrinet.in");
    ofstream fout("agrinet.out");
    int n;
    fin >> n;
    int g[100][100] = {{0}};
    REP(i, n) REP(j, n) fin >> g[i][j];
    vector<bool> inTree(n, 0);
    vector<int> prev(n, -1);
    vector<int> dist(n, INF);
    int cur = 0, next;
    REP(i, n-1) {
    	//DEBUG(cur);
    	inTree[cur] = 1;
    	REP(j, n) {
    		if(cur != j && !inTree[j] && g[cur][j] < dist[j]) {
    			dist[j] = g[cur][j];
    			prev[j] = cur;
    		}
    	}

    	//REP(j, n) cout << dist[j] << " ";
    	//cout << endl;

    	next = -1;
    	REP(j, n) {
    		if(!inTree[j] && next == -1) {
    			next = j;
    		}
    		if(!inTree[j] && dist[j] < dist[next]) {
    			next = j;
    		}
    	}

    	cur = next;
    }
    int s = 0;
    FOR(i, 1, n-1) {
    	s += g[i][prev[i]];
    }
    fout << s << endl;

    return 0;
}
