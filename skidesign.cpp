/*
ID: aman.ka1
PROG: skidesign
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
    ifstream fin("skidesign.in");
    ofstream fout("skidesign.out");
    int n;
    fin >> n;
    vector<int> hills(n);
    REP(i, n) fin >> hills[i];
    sort(hills.begin(), hills.end());
    int ans = INF;
    FOR(i, hills[0], hills.back()-17) {
    	int cur = 0, dif;
    	REP(j, n) {
    		//cout << i << " " << i+17 << " " << hills[j] << endl;
    		if(hills[j] < i || hills[j] > i+17) {
    			dif = min(abs(hills[j]-i), abs(hills[j]-(i+17)));
    			cur += dif*dif;
    		}
    	}
    	ans = min(ans, cur);
    }
    if(ans == INF) fout << 0 << endl;
    else fout << ans << endl;
    return 0;
}
