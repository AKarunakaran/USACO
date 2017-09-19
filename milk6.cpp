/*
ID: aman.ka1
PROG: milk6
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
#include <unordered_map>
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

struct truck {
    int beg;
    int end;
    int cost;
    int idx;
};

int pairConv(int a, int b) {
	return a*n+b;
}

int flow(vector<vector<int>> g) {
    int f = 0;
    while(1) {
        vector<int> prev(n+1, 0);
        vector<int> color(n+1, 0);
        stack<int> next;
        next.push(1);
        while(!next.empty()) {
            int cur = next.top();
            next.pop();
            if(cur == n) break;
            color[cur] = 2;
            FOR(i, 1, n) {
                if(color[i] == 0 && g[cur][i]) {
                    next.push(i);
                    prev[i] = cur;
                    color[i] = 1;
                }
            }
        }
        if(prev[n] == 0) break;
        int cur = n, pathCap = INF, bestIdx = 0;
        while(cur != 1) {
            if(g[prev[cur]][cur] < pathCap) {
                pathCap = g[prev[cur]][cur];
            }
            cur = prev[cur];
        }
        //cout << pathCap << endl;
        f += pathCap;
        cur = n;
        while(cur != 1) {
            g[prev[cur]][cur] -= pathCap;
            g[cur][prev[cur]] += pathCap;
            cur = prev[cur];
        }
    }
    return f;
}

int main() {
    ifstream fin("milk6.in");
    ofstream fout("milk6.out");
    int m;
    fin >> n >> m;
    vector<vector<int>> g(n+1, vector<int>(n+1, 0));
    vector<truck> trucks(m);
    REP(i, m) {
    	int s, e, c;
    	fin >> s >> e >> c;
    	g[s][e] += c;
    	trucks[i] = {s, e, c, i+1};
    }
    sort(trucks.begin(), trucks.end(), [](truck& left, truck& right){return left.cost > right.cost || (left.cost == right.cost && left.idx < right.idx);});

    int ans = flow(g);
    int cur = ans;
    vector<int> sol;
    REP(i, m) {
        truck& curTruck = trucks[i];
        if(cur < curTruck.cost) continue;
        g[curTruck.beg][curTruck.end] -= curTruck.cost;
        int testF = flow(g);
        if(cur-testF == curTruck.cost) {
            sol.push_back(curTruck.idx);
            cur = testF;
        } else {
            g[curTruck.beg][curTruck.end] += curTruck.cost;
        }
    }

    sort(sol.begin(), sol.end());

    fout << ans << " " << sol.size() << endl;
    REP(i, sol.size()) fout << sol[i] << endl;

    return 0;
}
