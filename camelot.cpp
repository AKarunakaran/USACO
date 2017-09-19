/*
ID: aman.ka1
PROG: camelot
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

int R, C;

void dijk(vector<vector<int>>& g, int r, int c) {
    queue<pair<int, int>> next;
    g[r][c] = 0;
    next.push({r, c});
    while(!next.empty()) {
        int curR = next.front().first, curC = next.front().second;
        next.pop();
        if(curR >= 2 && curC >= 1 && 1+g[curR][curC] < g[curR-2][curC-1]) {
            next.push({curR-2, curC-1});
            g[curR-2][curC-1] = 1+g[curR][curC];
        }
        if(curR >= 2 && curC <= C-2 && 1+g[curR][curC] < g[curR-2][curC+1]) {
            next.push({curR-2, curC+1});
            g[curR-2][curC+1] = 1+g[curR][curC];
        }
        if(curR >= 1 && curC <= C-3 && 1+g[curR][curC] < g[curR-1][curC+2]) {
            next.push({curR-1, curC+2});
            g[curR-1][curC+2] = 1+g[curR][curC];
        }
        if(curR <= R-2 && curC <= C-3 && 1+g[curR][curC] < g[curR+1][curC+2]) {
            next.push({curR+1, curC+2});
            g[curR+1][curC+2] = 1+g[curR][curC];
        }
        if(curR <= R-3 && curC <= C-2 && 1+g[curR][curC] < g[curR+2][curC+1]) {
            next.push({curR+2, curC+1});
            g[curR+2][curC+1] = 1+g[curR][curC];
        }
        if(curR <= R-3 && curC >= 1 && 1+g[curR][curC] < g[curR+2][curC-1]) {
            next.push({curR+2, curC-1});
            g[curR+2][curC-1] = 1+g[curR][curC];
        }
        if(curR <= R-2 && curC >= 2 && 1+g[curR][curC] < g[curR+1][curC-2]) {
            next.push({curR+1, curC-2});
            g[curR+1][curC-2] = 1+g[curR][curC];
        }
        if(curR >= 1 && curC >= 2 && 1+g[curR][curC] < g[curR-1][curC-2]) {
            next.push({curR-1, curC-2});
            g[curR-1][curC-2] = 1+g[curR][curC];
        }
    }
}

int main() {
    ifstream fin("camelot.in");
    ofstream fout("camelot.out");
    int kr, kc, inR;
    char inC;
    fin >> R >> C;
    fin >> inC >> kr;
    kc = inC - 'A';
    --kr;
    vector<pair<int, int>> knights;
    while(fin.good()) {
    	fin >> inC >> inR;
    	knights.push_back({inR-1, inC-'A'});
    }
    knights.pop_back();
    int ans = INF;
    vector<vector<vector<int>>> kbfs(knights.size(), vector<vector<int>>(R, vector<int>(C, INF)));
    REP(i, knights.size()) dijk(kbfs[i], knights[i].first, knights[i].second);
    REP(r, R) {
        REP(c, C) {
            bool good = true;
            REP(i, knights.size()) if(kbfs[i][r][c] == INF) good = false;
            if(!good) continue;
            vector<vector<int>> g(R, vector<int>(C, INF));
            dijk(g, r, c);
            int minD, sum = 0;
            REP(i, knights.size()) sum += kbfs[i][r][c];
            minD = sum + max(abs(r-kr), abs(c-kc));
            FOR(i, kr-2, kr+2) {
                if(i < 0 || i >= R) continue;
                FOR(j, kc-2, kc+2) {
                    if(j < 0 || j >= C) continue;
                    REP(k, knights.size()) {
                        if(kbfs[k][i][j] == INF) continue;
                        minD = min(minD, sum - kbfs[k][r][c] + g[i][j] + kbfs[k][i][j] + max(abs(i-kr), abs(j-kc)));
                    }
                }
            }
            ans = min(ans, minD);
        }
    }
    fout << ans << endl;

    return 0;
}
