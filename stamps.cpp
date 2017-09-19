/*
ID: aman.ka1
PROG: stamps
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
    ifstream fin("stamps.in");
    ofstream fout("stamps.out");
    int k, n;
    fin >> k >> n;
    vector<int> stamps(n);
    REP(i, n) fin >> stamps[i];
    sort(stamps.begin(), stamps.end());
    int sz = k*stamps.back();
    vector<int> good(sz+1, INF);
    good[0] = 0;
    int i = 1;
    while(i <= sz) {
    	REP(j, n) {
    		if(i-stamps[j] < 0) break;
    		good[i] = min(good[i], good[i-stamps[j]]+1);
    	}
    	if(good[i] > k) break;
    	++i;
    }
    //REP(i, sz+1) cout << good[i] << " ";
    //cout << endl;
    fout << i-1 << endl;

    return 0;
}
