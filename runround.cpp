/*
ID: aman.ka1
PROG: runround
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
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }

/////////////////////////////////////////////////////////////////////

void gen(vector<ll>& unique, deque<int>& unused, ll k) {
	if(unused.empty()) return;
	REP(i, unused.size()) {
		k = k*10+unused.front();
		if(k <= 9682415) {
			unique.push_back(k);
			unused.pop_front();
			gen(unique, unused, k);
			unused.push_back(k%10);
		}
		k /= 10;
	}
}

bool run(int n) {
	int k = n, d = 0;
	while(k) {
		k/=10;
		++d;
	}
	vector<int> digs(d, 0);
	FORD(i, d-1, 0) {
		digs[i] = n%10;
		n/=10;
	}
	vector<bool> checked(d, 0);
	int i = 0;
	while(!checked[i]) {
		checked[i] = 1;
		i = (i+digs[i])%d;
	}
	if(i != 0) return false;
	REP(j, d) if(!checked[j]) return false;
	return true;
}

int main() {
    ifstream fin("runround.in");
    ofstream fout("runround.out");
    ll n;
    fin >> n;
    vector<ll> unique;
    deque<int> unused;
    REP(i, 9) unused.push_back(i+1);
    ll k = 0;
    gen(unique, unused,  k);
    sort(unique.begin(), unique.end());
    //REP(i, unique.size()) cerr << unique[i] << endl;
    int start = 0;
    while(unique[start] <= n) ++start;
    while(!run(unique[start])) {
    	//cerr << unique[start] << endl;
    	++start;
    }
    fout << unique[start] << endl;

    return 0;
}
