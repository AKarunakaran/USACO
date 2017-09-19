/*
ID: aman.ka1
PROG: shopping
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

int dp[6][6][6][6][6];
vector<pair<vector<pair<int, int>>, int>> deals;

int main() {
    ifstream fin("shopping.in");
    ofstream fout("shopping.out");
    REP(i, 6) REP(j, 6) REP(k, 6) REP(m, 6) REP(n, 6) dp[i][j][k][m][n] = INF;
    dp[0][0][0][0][0] = 0;
    int s, b, n, c, k;
    fin >> s;
    deals.resize(s);
    REP(i, s) {
    	fin >> n;
    	auto& d = deals[i].first;
    	d.resize(n);
    	REP(j, n) fin >> d[j].first >> d[j].second;
    	fin >> deals[i].second;
    }
    fin >> b;
    vector<int> need(5, 0), prices(b), prods(b);
    REP(i, b) {
    	fin >> prods[i];
    	fin >> need[i] >> prices[i];
    }

    REP(i, s) {
    	auto& d = deals[i].first;
    	vector<bool> checked(5, 0);
    	REP(j, d.size()) {
    		REP(k, b) {
    			if(d[j].first == prods[k]) {
    				checked[k] = 1;
    				d[j].first = k;
    				break;
    			}
    		}
    	}
    	REP(j, 5) if(!checked[j]) d.push_back({j, 0});
    	sort(d.begin(), d.end());
    }

    /*REP(i, s) {
    	cout << deals[i].second << " ";
    	REP(j, deals[i].first.size()) {
    		cout << '{' << deals[i].first[j].first << ", " << deals[i].first[j].second << "}, ";
    	}
    	cout << endl;
    }*/

    FOR(i, 0, need[0]) {
		FOR(j, 0, need[1]) {
			FOR(k, 0, need[2]) {
				FOR(m, 0, need[3]) {
					FOR(r, 0, need[4]) {
						REP(q, s) {
							auto& d = deals[q].first;
							if(i >= d[0].second && j >= d[1].second && k >= d[2].second && m >= d[3].second && r >= d[4].second) {
								dp[i][j][k][m][r] = min(dp[i][j][k][m][r], deals[q].second+dp[i-d[0].second][j-d[1].second][k-d[2].second][m-d[3].second][r-d[4].second]);
							}
						}
						if(i > 0) dp[i][j][k][m][r] = min(dp[i][j][k][m][r], prices[0]+dp[i-1][j][k][m][r]);
						if(j > 0) dp[i][j][k][m][r] = min(dp[i][j][k][m][r], prices[1]+dp[i][j-1][k][m][r]);
						if(k > 0) dp[i][j][k][m][r] = min(dp[i][j][k][m][r], prices[2]+dp[i][j][k-1][m][r]);
						if(m > 0) dp[i][j][k][m][r] = min(dp[i][j][k][m][r], prices[3]+dp[i][j][k][m-1][r]);
						if(r > 0) dp[i][j][k][m][r] = min(dp[i][j][k][m][r], prices[4]+dp[i][j][k][m][r-1]);
					}
				}
			}
		}
    }

    /*FOR(i, 0, need[0]) {
    	FOR(j, 0, need[1]) {
    		cout << dp[i][j][0][0][0] << " ";
    	}
    	cout << endl;
    }*/

    fout << dp[need[0]][need[1]][need[2]][need[3]][need[4]] << endl;

    return 0;
}
