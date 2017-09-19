/*
ID: aman.ka1
PROG: zerosum
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

int n;

bool zero(vector<char>& v) {
	//REP(i, n-1) cout << i+1 << v[i];
	//cout << n << endl;
	int sum = 0;
	int k;
	char prev = '+';
	int i = 0;
	while(i < n) {
		k = i+1;
		while(v[i] == ' ' && i < n) {
			++i;
			k = k*10 + (i+1);
		}
		//cout << k << " " << prev << endl;
		if(prev == '+') sum += k;
		else sum -= k;
		prev = v[i];
		++i;
	}
	return (sum == 0);
}

void perm(vector<char>& cur, ostream& fout) {
	if(cur.size() == n-1) {
		if(zero(cur)) {
			REP(i, n-1) fout << i+1 << cur[i];
			fout << n << endl;
		}
		return;
	}

	cur.push_back(' ');
	perm(cur, fout);
	cur.pop_back();

	cur.push_back('+');
	perm(cur, fout);
	cur.pop_back();

	cur.push_back('-');
	perm(cur, fout);
	cur.pop_back();

}

int main() {
	ifstream fin("zerosum.in");
	ofstream fout("zerosum.out");
    fin >> n;
    vector<char> cur;
    perm(cur, fout);

    return 0;
}
