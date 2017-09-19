/*
ID: aman.ka1
PROG: fence6
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

struct seg {
	int size;
	vector<pair<int, int>> first;
	vector<pair<int, int>> second;
};

int n;
vector<seg> segs;

void DFS(int s, vector<bool>& used, int k, int f, int cur, int& best) {
    //cout << s << " " << k << " " << cur << " " << best << endl;
    if(cur > best) return;
    if(used[s]) {
        best = min(best, cur);
        return;
    }
    if(f == 0) {
        auto& v = segs[k].first;
        REP(i, v.size()) {
            int next = v[i].first;
            if(!used[next]) {
                used[next] = 1;
                DFS(s, used, next, 1-v[i].second, cur+segs[next].size, best);
                used[next] = 0;
            }
        }
    } else {
        auto& v = segs[k].second;
        REP(i, v.size()) {
            int next = v[i].first;
            if(!used[next]) {
                used[next] = 1;
                DFS(s, used, next, 1-v[i].second, cur+segs[next].size, best);
                used[next] = 0;
            }
        }
    }
}

int main() {
    ifstream fin("fence6.in");
    ofstream fout("fence6.out");
    int sz1, sz2, k;
    fin >> n;
    segs.resize(n+1);
    REP(i, n) {
    	fin >> k;
    	fin >> segs[k].size >> sz1 >> sz2;
    	segs[k].first.resize(sz1, {0, 0});
    	segs[k].second.resize(sz2, {0, 0});
    	REP(j, sz1) fin >> segs[k].first[j].first;
    	REP(j, sz2) fin >> segs[k].second[j].first;
    }
    FOR(i, 1, n) {
    	REP(j, segs[i].first.size()) {
    		int s = segs[i].first[j].first;
    		bool f = 0;
    		REP(k, segs[s].first.size()) {
    			if(segs[s].first[k].first == i) {
    				f = 1;
    				break;
    			}
    		}
    		segs[i].first[j].second = 1-f;
    	}
    	REP(j, segs[i].second.size()) {
    		int s = segs[i].second[j].first;
    		bool f = 0;
    		REP(k, segs[s].first.size()) {
    			if(segs[s].first[k].first == i) {
    				f = 1;
    				break;
    			}
    		}
    		segs[i].second[j].second = 1-f;
    	}
    }
    /*FOR(i, 1, n) {
    	cout << i << endl;
    	REP(j, segs[i].first.size()) {
    		cout << "{" << segs[i].first[j].first << ", " << segs[i].first[j].second << "}, ";
    	}
    	cout << endl;
    	REP(j, segs[i].second.size()) {
    		cout << "{" << segs[i].second[j].first << ", " << segs[i].second[j].second << "}, ";
    	}
    	cout << endl << endl;
    }*/
    int ans = INF;
    FOR(i, 1, n) {
        vector<bool> used(n+1, 0);
        DFS(i, used, i, 0, 0, ans);
        FOR(j, 0, n) used[j] = 0;
        DFS(i, used, i, 1, 0, ans);
    }
    fout << ans << endl;

    return 0;
}
