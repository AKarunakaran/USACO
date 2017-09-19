/*
ID: aman.ka1
PROG: comehome
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
const int INF = 1000000;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }

/////////////////////////////////////////////////////////////////////

bool all(const vector<bool>& v) {
	REP(i, v.size()) if(!v[i]) return false;
	return true;
}

int main() {
    ifstream fin("comehome.in");
    ofstream fout("comehome.out");
    int p, d, n = 52;
    char a, b;
    fin >> p;
    vector<bool> in(n, 0);
    vector<vector<int>> g(n, vector<int>(n, INF));
    REP(i, p) {
    	fin >> a >> b >> d;
    	int idxA, idxB;
    	if(a >= 'A' && a <= 'Z') idxA = a-'A'+26;
		else idxA = a-'a';
    	if(b >= 'A' && b <= 'Z') idxB = b-'A'+26;
    	else idxB = b-'a';
    	in[idxA] = in[idxB] = 1;
    	g[idxA][idxB] = g[idxB][idxA] = min(g[idxA][idxB], d);
    }
    REP(i, n) g[i][i] = 0;
    vector<bool> checked(n, 0);
    vector<int> dist(n, INF);
    REP(i, n) if(!in[i]) checked[i] = 1;
    int cur = 51;
    dist[cur] = 0;
    while(1) {
    	//REP(i, n) if(in[i]) cout << dist[i] << " ";
    	//cout << endl;
    	//REP(i, n) if(in[i]) cout << checked[i] << " ";
    	//cout << endl << endl;
    	if(cur >= 26 && cur <= 50) {
    		fout << char(cur-26+'A') << " " << dist[cur] << endl;
    		return 0;
    	}
    	checked[cur] = 1;
    	REP(i, n) {
    		if(in[i] && g[cur][i] + dist[cur] < dist[i]) {
    			dist[i] = g[cur][i] + dist[cur];
    		}
    	}
    	REP(i, n) {
    		if(in[i] && !checked[i]) {
    			cur = i;
    			break;
    		}
    	}
    	REP(i, n) {
    		if(in[i] && !checked[i] && dist[i] < dist[cur]) {
    			cur = i;
    		}
    	}
    }

    return 0;
}
