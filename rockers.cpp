/*
ID: aman.ka1
PROG: rockers
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

int t, m;

int main() {
    ifstream fin("rockers.in");
    ofstream fout("rockers.out");
    int n, min;
    fin >> n >> t >> m;
    vector<int> songs;
    REP(i, n) {
    	fin >> min;
    	if(min <= t) songs.push_back(min);
    }
    n = songs.size();
    vector<bool> used(n, 0);
    int best = 0, upper = two(n);
    REP(i, upper) {
    	vector<int> disks(m, t);
    	int d = 0, cnt = 0;
    	REP(j, n) {
    		if(i & two(j)) {
    			if(songs[j] <= disks[d]) {
    				disks[d] -= songs[j];
    				++cnt;
    			} else if(d < m-1) {
    				++d;
    				disks[d] -= songs[j];
    				++cnt;
    			}
    		}
    	}
    	best = max(best, cnt);
    }
    fout << best << endl;

    return 0;
}
