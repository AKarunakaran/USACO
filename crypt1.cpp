/*
ID: aman.ka1
PROG: crypt1
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

int toNum(const vector<int>& v, int a, int b) {
	int num = 0;
	FOR(i, a, b) {
		num += (pow(10,i-a)*v[i]);
	}
	return num;
}

bool contains(const vector<int>& v, int a) {
	REP(i, v.size()) if(v[i] == a) return true;
	return false;
}

bool pass(int n, const vector<int>& p, int l) {
	REP(i, l) {
		if(!contains(p, n%10)) return false;
		n/= 10;
	}
	return n == 0;
}

void perm(vector<int>& sol, const vector<int>& p, int& num, int k) {
	if(k == 5) {
		if(pass(toNum(sol, 0, 2)*sol[3], p, 3) && pass(toNum(sol, 0, 2)*sol[4], p, 3) && pass(toNum(sol, 0, 2)*toNum(sol, 3, 4), p, 4)) {
			++num;
			//REP(i, 5) cout << sol[i] << " ";
			//cout << endl;
		}
		return;
	}
	REP(i, p.size()) {
		sol.push_back(p[i]);
		perm(sol, p, num, k+1);
		sol.pop_back();
	}
}

int main() {
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");
    int n;
    fin >> n;
    vector<int> p(n);
    REP(i, n) fin >> p[i];
    vector<int> sol;
    int num = 0;
    perm(sol, p, num, 0);
    fout << num << endl;

    return 0;
}