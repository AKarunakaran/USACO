/*
ID: aman.ka1
PROG: wormhole
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

int n;

bool loop(const vector<int>& wpt, const vector<int>& wkt) {
	REP(i, n) {
		int p = wpt[i];
		do {
			p = wkt[p];
			if(p == -1) break;
			p = wpt[p];
		} while (p != wpt[i]);
		if(p == wpt[i]) return true;

		p = wkt[i];
		if(p != -1) {
			do {
				p = wpt[p];
				p = wkt[p];
			} while (p != -1 && p != wkt[i]);
			if(p == wkt[i]) return true;
		}
	}
	return false;
}

void perm(vector<int>& wpt, const vector<int>& wkt, int& ans) {
	int idx = -1;
	REP(i, n) {
		if(wpt[i] == -1) {
			idx = i;
			break;
		}
	}
	if(idx == -1) {
		//REP(i, n) cout << wpt[i] << " ";
		//cout << endl;
		if(loop(wpt, wkt)) {
			++ans;
		}
		return;
	}

	FOR(i, idx+1, n) {
		if(wpt[i] == -1) {
			wpt[idx] = i;
			wpt[i] = idx;
			perm(wpt, wkt, ans);
			wpt[i] = -1;
			wpt[idx] = -1;
		}
	}
}

int main() {
    ifstream fin("wormhole.in");
    ofstream fout("wormhole.out");
    fin >> n;
    vector< pair<int, int> > warp(n);
    vector<int> wpt(n, -1);
    vector<int> wkt(n, -1);
    REP(i, n) fin >> warp[i].second >> warp[i].first;
    sort(warp.begin(), warp.end());
    REP(i, n-1)
    	if(warp[i].first == warp[i+1].first)
    		wkt[i] = i+1;
	int ans = 0;
	//REP(i, n) cout << wkt[i] << " ";
	//cout << endl;
    perm(wpt, wkt, ans);
    fout << ans << endl;

    return 0;
}