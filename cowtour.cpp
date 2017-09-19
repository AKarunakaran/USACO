/*
ID: aman.ka1
PROG: cowtour
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
inline bool EQ(double a, double b) { return fabs(a-b) < 0.000001; }
const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }

/////////////////////////////////////////////////////////////////////

double dist(pair<int, int>& a, pair<int, int>& b) {
	return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

int main() {
    ifstream fin("cowtour.in");
    ofstream fout("cowtour.out");
    cout << fixed << setprecision(6);
    fout << fixed << setprecision(6);
    int n;
    fin >> n;
    vector<pair<int, int>> d(n);
    int x, y;
    REP(i, n) {
    	fin >> x >> y;
    	d[i].first = x;
    	d[i].second = y;
    }
    vector<vector<double>> sPath(n, vector<double>(n, INF));
    char connect;
    REP(i, n) {
    	REP(j, n) {
    		fin >> connect;
    		if(connect == '1') {
    			sPath[i][j] = dist(d[i], d[j]);
    		}
    	}
    }

    REP(k, n) {
    	REP(i, n) {
    		REP(j, n) {
    			if(i == j) {
    				sPath[i][j] = 0;
    				continue;
    			}
    			if(sPath[i][k] + sPath[k][j] < sPath[i][j]) {
    				sPath[i][j] = sPath[i][k] + sPath[k][j];
    			}
    		}
    	}
    }

    vector<double> maxD(n, 0);
    REP(i, n) {
    	REP(j, n) {
    		if(!EQ(sPath[i][j], INF)) {
                maxD[i] = max(maxD[i], sPath[i][j]);
            }
    	}
    }
    //REP(i, n) cout << maxD[i] << " ";
    //cout << endl;

    vector<double> diam(n, -1);
    vector<int> curField;
    REP(i, n) {
        if(diam[i] == -1) {
            curField.push_back(i);
            REP(j, n) {
                if(!EQ(sPath[i][j], INF)) {
                    curField.push_back(j);
                }
            }
            REP(j, curField.size()) {
                REP(k, curField.size()) {
                    diam[i] = max(diam[i], sPath[curField[j]][curField[k]]);
                }
            }
            REP(j, curField.size()) {
                diam[curField[j]] = diam[i];
            }
            curField.resize(0);
        }
    }

    //REP(i, n) cout << diam[i] << " ";
    //cout << endl;

    double ans = INF, cur;
    FOR(i, 0, n-2) {
    	FOR(j, i+1, n-1) {
    		//if(maxD[i] == 0 || maxD[j] == 0) continue;
    		//cout << maxD[i] << " " << maxD[j] << " " << dist(d[i], d[j]) << " " << max(diam[i], diam[j]) << endl;
    		if(EQ(sPath[i][j], INF)) {
    			cur = maxD[i]+maxD[j]+dist(d[i], d[j]);
    			ans = min(ans, max(cur, max(diam[i], diam[j])));
    		}
    	}
    }

    fout << ans << endl;

    return 0;
}
