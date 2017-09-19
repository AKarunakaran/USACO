/*
ID: aman.ka1
PROG: milk
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
    ifstream fin("milk.in");
    ofstream fout("milk.out");
    int n, m;
    fin >> n >> m;
    vector< pair<int, int> > f(m);
    REP(i, m) fin >> f[i].first >> f[i].second;
    sort(f.begin(), f.end());
    int c = 0, i = 0;
    while(n > 0) {
    	c += f[i].first*min(f[i].second, n);
    	n -= min(f[i].second, n);
    	++i;
    }
    fout << c << endl;

    return 0;
}