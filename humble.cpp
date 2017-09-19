/*
ID: aman.ka1
PROG: humble
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
    ifstream fin("humble.in");
    ofstream fout("humble.out");
    int n, k;
    fin >> k >> n;
    vector<int> primes(k);
    REP(i, k) fin >> primes[i];
    sort(primes.begin(), primes.end());
    vector<ll> sol;
    sol.push_back(1);
    vector<int> idx(k, 0);
    while(sol.size() <= n) {
    	ll next = INF;
    	REP(i, k) {
    		while(sol[idx[i]]*primes[i] <= sol.back()) ++idx[i];
    		next = min(next, sol[idx[i]]*primes[i]);
    	}
    	sol.push_back(next);
    }
    fout << sol[n] << endl;

    return 0;
}
