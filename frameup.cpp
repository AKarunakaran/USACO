/*
ID: aman.ka1
PROG: frameup
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

int h, w;

struct letFrame {
	int maxR, maxC, minR, minC;
};

void perm(vector<vector<char>>& g, string& cur, vector<bool>& done, int toGo, vector<letFrame>& letters, vector<string>& sol) {
	//DEBUG(toGo);
	if(toGo == 0) {
		sol.push_back(cur);
		return;
	}
	REP(l, 26) {
		if(done[l]) continue;
		int minC = letters[l].minC, maxC = letters[l].maxC, minR = letters[l].minR, maxR = letters[l].maxR;
		//DEBUG(minC);
		//DEBUG(maxC);
		//DEBUG(minR);
		//DEBUG(maxR);
		bool good = true;
		FOR(i, minR, maxR) {
			if((g[i][minC] != '?' && g[i][minC] != ('A' + l)) || (g[i][maxC] != '?' && g[i][maxC] != ('A' + l))) {
				good = false;
				break;
			}
		}
		FOR(i, minC, maxC) {
			if((g[minR][i] != '?' && g[minR][i] != ('A' + l)) || (g[maxR][i] != '?' && g[maxR][i] != ('A' + l))) {
				good = false;
				break;
			}
		}
		if(good) {
			//DEBUG(char('A'+l));
			cur[toGo-1] = 'A'+l;
			vector<pair<char, pair<int, int>>> toRestore;
			FOR(i, minR, maxR) {
				if(g[i][minC] != '?') toRestore.push_back({g[i][minC], {i, minC}});
				if(g[i][maxC] != '?') toRestore.push_back({g[i][maxC], {i, maxC}});
				g[i][minC] = g[i][maxC] = '?';
			}
			FOR(i, minC, maxC) {
				if(g[minR][i] != '?') toRestore.push_back({g[minR][i], {minR, i}});
				if(g[maxR][i] != '?') toRestore.push_back({g[maxR][i], {maxR, i}});
				g[minR][i] = g[maxR][i] = '?';
			}
			done[l] = 1;
			perm(g, cur, done, toGo-1, letters, sol);
			cur[toGo-1] = ' ';
			REP(i, toRestore.size()) {
				int r = toRestore[i].second.first, c = toRestore[i].second.second;
				g[r][c] = toRestore[i].first;
			}
			done[l] = 0;
		}
	}
}

int main() {
    ifstream fin("frameup.in");
    ofstream fout("frameup.out");
    fin >> h >> w;
    vector<vector<char>> g(h, vector<char>(w));
    REP(i, h) REP(j, w) fin >> g[i][j];
    vector<bool> done(26, 1);
    vector<letFrame> letters(26, {-1, -1, INF, INF});
    REP(i, h) REP(j, w) if(g[i][j] != '.') done[g[i][j]-'A'] = 0;
    int lettersToGo = 0;
    REP(i, 26) if(!done[i]) ++lettersToGo;
    vector<string> sol;
    string cur = "";
    REP(i, lettersToGo) cur.push_back(' ');
    REP(i, h) {
		REP(j, w) {
			if(g[i][j] != '.') {
				auto& frame = letters[g[i][j]-'A'];
				frame.maxR = max(frame.maxR, i);
				frame.maxC = max(frame.maxC, j);
				frame.minR = min(frame.minR, i);
				frame.minC = min(frame.minC, j);
			}
		}
	}
    perm(g, cur, done, lettersToGo, letters, sol);
    sort(sol.begin(), sol.end());
    REP(i, sol.size()) fout << sol[i] << endl;

    return 0;
}
