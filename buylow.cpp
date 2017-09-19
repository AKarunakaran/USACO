/*
ID: aman.ka1
PROG: buylow
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
#include <unordered_set>
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

struct bigInt {
	vector<int> d;
	bool neg;
};

void print(bigInt& n, ostream& os) {
	FORD(i, n.d.size()-1, 0) os << n.d[i];
}

bigInt zero() {
	vector<int> d(1, 0);
	return {d, 0};
}

bigInt one() {
	vector<int> d(1, 1);
	return {d, 0};
}

bigInt add(bigInt& a, bigInt& b) {
	if(a.d.size() > b.d.size()) b.d.resize(a.d.size(), 0);
	else if(a.d.size() < b.d.size()) a.d.resize(b.d.size(), 0);

	vector<int> newD;
	bool c = 0;
	REP(i, a.d.size()) {
		newD.push_back(a.d[i] + b.d[i] + c);
		if(newD[i] > 9) {
			newD[i] -= 10;
			c = 1;
		} else {
			c = 0;
		}
	}
	if(c) newD.push_back(1);

	return {newD, 0};
}

int main() {
    ifstream fin("buylow.in");
    ofstream fout("buylow.out");
    int n;
    fin >> n;
    vector<int> s(n+1);
    vector<pair<int, bigInt>> dp(n+1, {0, zero()});
    dp[0].second = one();
    s[0] = INF;
    REP(i, n) fin >> s[i+1];
    FOR(i, 1, n) {
    	int maxS = 0;
    	FOR(j, 0, i-1) {
    		if(s[j] > s[i]) maxS = max(maxS, dp[j].first+1);
    	}
    	dp[i].first = maxS;
    	unordered_set<int> ends;
    	FORD(j, i-1, 0) {
    		if(s[j] > s[i] && dp[j].first == maxS-1 && ends.find(s[j]) == ends.end()) {
    			dp[i].second = add(dp[i].second, dp[j].second);
    			ends.insert(s[j]);
    		}
    	}
    }
    int ans1 = 0;
    bigInt ans2 = zero();
    FOR(i, 1, n) ans1 = max(ans1, dp[i].first);
    unordered_set<int> ends;
    FORD(i, n, 1) {
    	if(dp[i].first == ans1 && ends.find(s[i]) == ends.end()) {
    		ans2 = add(ans2, dp[i].second);
    		ends.insert(s[i]);
    	}
    }

    /*FOR(i, 1, n) cout << s[i] << "\t";
    cout << endl;
    FOR(i, 1, n) cout << dp[i].first << "\t";
    cout << endl;
    FOR(i, 1, n) {
    	print(dp[i].second, cout);
    	cout << "\t";
    }
    cout << endl;*/

    fout << ans1 << " ";
    print(ans2, fout);
    fout << endl;

    return 0;
}
