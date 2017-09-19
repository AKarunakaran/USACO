/*
ID: aman.ka1
PROG: fact4
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
    ifstream fin("fact4.in");
    ofstream fout("fact4.out");
    int n;
    fin >> n;
    vector<int> dig(n+1, 1);
    ull cur = 1;
    FOR(i, 2, n) {
    	cur = (cur*i)%1000000;
    	while(cur % 10 == 0) cur /= 10;
    	dig[i] = cur % 10;
    }
    //REP(i, n+1) cout << dig[i] << " ";
    //cout << endl;
    fout << dig[n] << endl;

    return 0;
}
