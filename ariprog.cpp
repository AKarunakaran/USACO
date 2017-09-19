/*
ID: aman.ka1
PROG: ariprog
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
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");
    int n, m;
    fin >> n >> m;
    int bsql = 2*m*m;
    vector<bool> bsq(bsql+1, 0);
    vector< pair<int, int> > sol;

    FOR(i, 0, m)
    	FOR(j, i, m)
    		bsq[i*i+j*j] = 1;

    
    /*int a, i, cnt;
    FOR(b, 1, 41667) {
    	FOR(a, 0, b-1) {
    		if(a+(n-1)*b > 2*m*m) break;
    		cnt = 0;
	    	i = a;
	    	while(i <= 2*m*m) {
	    		if(bsq[i]) {
	    			++cnt;
	    			if(cnt >= n) {
	    				sol.push_back({b, i-(n-1)*b});
	    			}
	    		} else
	    			cnt = 0;
	    		i += b;
	    	}
    	}
    }*/

    FOR(a, 0, bsql) {
        if(bsq[a]) {
            FOR(b, 1, (bsql-a)/(n-1)) {
                int i = 0;
                for(; i < n; ++i) {
                    if(!bsq[a+i*b]) break;
                }
                if(i == n) sol.push_back({b, a});
            }
        }
    }
    sort(sol.begin(), sol.end());

    if(sol.size()) REP(i, sol.size()) fout << sol[i].second << " " << sol[i].first << endl;
    else fout << "NONE" << endl;

    return 0;
}
