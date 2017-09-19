/*
ID: aman.ka1
PROG: nuggets
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

int gcd(int a, int b) {
	while(b) {
		int c = a%b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
    ifstream fin("nuggets.in");
    ofstream fout("nuggets.out");
    int n;
    fin >> n;
    vector<int> nuggets(n);
    REP(i, n) fin >> nuggets[i];
    sort(nuggets.begin(), nuggets.end());
    int g = nuggets[0];
    FOR(i, 1, n-1) g = gcd(g, nuggets[i]);
    if(g != 1) {
    	fout << 0 << endl;
    	return 0;
    }
    vector<bool> canMake(nuggets[0]*nuggets.back()+1, 0);
    canMake[0] = 1;
    REP(i, canMake.size()) {
    	if(canMake[i]) {
    		REP(j, n) {
    			if(i+nuggets[j] < canMake.size()) canMake[i+nuggets[j]] = 1;
    		}
    	}
    }
    int ans = 0;
    REP(i, canMake.size()) {
    	if(!canMake[i]) {
    		ans = i;
    	}
    }
    fout << ans << endl;

    return 0;
}
