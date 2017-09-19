/*
ID: aman.ka1
PROG: holstein
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
//#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
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

int v, g;

void knap(const vector<int>& vit, const vector<vector<int>>& feeds, vector<bool> cur, vector<bool>& sol, int k) {
	int curSize = 0;
	int solSize = 0;
	REP(i, g) {
		curSize += cur[i];
		solSize += sol[i];
	}
	if(k == g) {
		//REP(i, g) cout << cur[i] << " ";
		//cout << endl;
		//REP(i, g) cout << sol[i] << " ";
		//cout << endl;
		int need = 0;
		vector<int> sum(v, 0);
		REP(i, g) {
			REP(j, v) {
				if(cur[i]) sum[j] += feeds[i][j];
			}
		}
		//REP(i, v) cout << sum[i] << " ";
		//cout << endl << endl;
		REP(i, v) {
			need += max(0, vit[i]-sum[i]);
		}
		if(need) return;
		if(solSize == 0 || curSize < solSize) {
			sol = cur;
		} else if(curSize == solSize) {
			REP(i, g) {
				if(sol[i] && !cur[i]) break;
				if(cur[i] && !sol[i]) {
					sol = cur;
					break;
				}
			}
		}
		return;
	}
	knap(vit, feeds, cur, sol, k+1);
	cur[k] = 1;
	knap(vit, feeds, cur, sol, k+1);
}

int main() {
    ifstream fin("holstein.in");
    ofstream fout("holstein.out");
    fin >> v;
    vector<int> vit(v);
    REP(i, v) fin >> vit[i];
    fin >> g;
    vector< vector<int> > feeds(g, vector<int> (v));
    REP(i, g) REP(j, v) fin >> feeds[i][j];
    vector<bool> sol(g, 0);	
    vector<bool> cur(g, 0);
    knap(vit, feeds, cur, sol, 0);
    int solSize = 0;
    REP(i, g) solSize += sol[i];
    fout << solSize;
    REP(i, g) if(sol[i]) fout << " " << i+1;
    fout << endl;

    return 0;
}
