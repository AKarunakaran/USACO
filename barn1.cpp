/*
ID: aman.ka1
PROG: barn1
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
    ifstream fin("barn1.in");
    ofstream fout("barn1.out");
    
    int m, s, c;
    fin >> m >> s >> c;
    vector<int> cs(c);
    vector<int> sp(c-1);

    REP(i, c) fin >> cs[i];
    sort(cs.begin(), cs.end());

    REP(i, c-1) sp[i] = cs[i+1]-cs[i]-1;
	sort(sp.begin(), sp.end(), [](int left, int right){return left > right;});
	REP(i, c-1) cout << sp[i] << " ";
	cout << endl;
	cout << cs.back() << " " << cs[0] << endl;
    
    int sum = cs.back()-cs[0]+1;
    REP(i, min(m-1, c-1)) sum -= sp[i];
    
    fout << sum << endl;

    return 0;
}