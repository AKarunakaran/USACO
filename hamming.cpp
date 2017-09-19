/*
ID: aman.ka1
PROG: hamming
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

int n, b, d;

bool ham(int a, int b) {
	int mask = 1;
	int dist = 0;
	REP(i, b) {
		if((a & mask) != (b & mask)) ++dist;
		if(dist == d) return true;
		mask = mask << 1;
	}
	return false;
}

bool clique(const vector<int>& sol, const vector<vector<bool>>& g) {
	FOR(i, 0, sol.size()-2) {
		FOR(j, i+1, sol.size()-1) {
			if(!g[sol[i]][sol[j]]) return false;
		}
	}
	return true;
}

int main() {
    ifstream fin("hamming.in");
    ofstream fout("hamming.out");
    fin >> n >> b >> d;
    int upper = two(b);
    vector<vector<bool>> g(upper, vector<bool>(upper, 0));
    FOR(i, 0, upper-2) {
    	FOR(j, i+1, upper-1) {
    		g[i][j] = ham(i, j);
    	}
    }
    vector<int> sol;
    sol.push_back(0);
    int i = 1;
    while(sol.size() < n) {
        if(sol.empty()) {
            fout << "NONE" << endl;
            return 0;
        }
    	if(i == upper) {
    		i = sol.back();
    		sol.pop_back();
    	}
        bool add = true;
        REP(j, sol.size()) {
            if(!g[sol[j]][i]) {
                add = false;
                break;
            }
        }
        if(add) sol.push_back(i);
    	++i;
    }
    i = 0;
    while(i < n-1) {
    	fout << sol[i] << ((i % 10 == 9) ? '\n': ' ');
    	++i;
    }
    fout << sol.back() << endl;

    return 0;
}
