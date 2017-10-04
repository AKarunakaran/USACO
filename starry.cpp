/*
ID: aman.ka1
PROG: starry
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

void print(vector<vector<bool>> v) {
    REP(i, v.size()) {
        REP(j, v[i].size()) cout << v[i][j];
        cout << endl;
    }
    cout << endl;
}

vector<vector<bool>> s, checked;
vector<vector<char>> ans;

struct c {
	int height, width;
	vector<vector<bool>> st;
};

vector<c> clusters;

bool clusterEq(c& a, c& b) {
	REP(i, a.height) REP(j, a.width) if(a.st[i][j] != b.st[i][j]) return false;
	return true;
}

void reflectXCluster(c& a) {
	REP(i, a.height) {
		REP(j, a.width/2) {
			bool temp = a.st[i][j];
			a.st[i][j] = a.st[i][a.width-1-j];
			a.st[i][a.width-1-j] = temp;
		}
	}
}

void reflectYCluster(c& a) {
	REP(j, a.width) {
		REP(i, a.height/2) {
			bool temp = a.st[i][j];
			a.st[i][j] = a.st[a.height-1-i][j];
			a.st[a.height-1-i][j] = temp;
		}
	}
}

void rotateCluster(c& a) {
    vector<vector<bool>> newSt(a.width, vector<bool> (a.height));
    REP(i, a.width) REP(j, a.height) newSt[i][j] = a.st[a.height-1-j][i];
    a.st = newSt;
    int temp = a.height;
    a.height = a.width;
    a.width = temp;
}

bool sameCluster(c& a, c& b) {
	if(!((a.height == b.height && a.width == b.width) || (a.height == b.width && a.width == b.height))) return false;
	c comp = a;
    //print(b.st);
    //print(comp.st);
	if(a.height != b.height) rotateCluster(comp);
    //print(comp.st);
	if(clusterEq(comp, b)) return true;
	reflectXCluster(comp);
    //print(comp.st);
	if(clusterEq(comp, b)) return true;
	reflectYCluster(comp);
    //print(comp.st);
	if(clusterEq(comp, b)) return true;
	reflectXCluster(comp);
    //print(comp.st);
	if(clusterEq(comp, b)) return true;
    if(a.height == a.width) {
        rotateCluster(comp);
        //print(comp.st);
        if(clusterEq(comp, b)) return true;
        reflectXCluster(comp);
        //print(comp.st);
        if(clusterEq(comp, b)) return true;
        reflectYCluster(comp);
        //print(comp.st);
        if(clusterEq(comp, b)) return true;
        reflectXCluster(comp);
        //print(comp.st);
        if(clusterEq(comp, b)) return true;
    }
	return false;
}

int main() {
    ifstream fin("starry.in");
    ofstream fout("starry.out");
    int h, w;
    fin >> w >> h;
    s.resize(h, vector<bool>(w));
    REP(i, h) {
    	REP(j, w) {
    		char ch;
    		fin >> ch;
    		s[i][j] = (ch == '1');
    	}
    }
    checked.resize(h, vector<bool>(w, 0));
    ans.resize(h, vector<char>(w, '0'));
    REP(i, h) {
    	REP(j, w) {
    		if(!checked[i][j] && s[i][j]) {
    			c newCluster;
    			int maxX = j, maxY = i, minX = j, minY = i;
    			queue<pair<int, int>> next;
    			next.push({i, j});
                checked[i][j] = 1;
    			while(!next.empty()) {
    				pair<int, int> cur = next.front();
    				next.pop();
    				int x = cur.second, y = cur.first;
                    ans[y][x] = '1';
    				maxX = max(maxX, x);
    				maxY = max(maxY, y);
                    minX = min(minX, x);
                    minY = min(minY, y);
    				if(y > 0 && x > 0 && s[y-1][x-1] && !checked[y-1][x-1]) {
    					next.push({y-1, x-1});
    					checked[y-1][x-1] = 1;
    				}
    				if(y > 0 && s[y-1][x] && !checked[y-1][x]) {
    					next.push({y-1, x});
    					checked[y-1][x] = 1;
    				}
					if(y > 0 && x < w-1 && s[y-1][x+1] && !checked[y-1][x+1]) {
						next.push({y-1, x+1});
						checked[y-1][x+1] = 1;
					}
					if(x > 0 && s[y][x-1] && !checked[y][x-1]) {
						next.push({y, x-1});
						checked[y][x-1] = 1;
					}
					if(x < w-1 && s[y][x+1] && !checked[y][x+1]) {
						next.push({y, x+1});
						checked[y][x+1] = 1;
					}
					if(y < h-1 && x > 0 && s[y+1][x-1] && !checked[y+1][x-1]) {
						next.push({y+1, x-1});
						checked[y+1][x-1] = 1;
					}
					if(y < h-1 && s[y+1][x] && !checked[y+1][x]) {
						next.push({y+1, x});
						checked[y+1][x] = 1;
					}
					if(y < h-1 && x < w-1 && s[y+1][x+1] && !checked[y+1][x+1]) {
						next.push({y+1, x+1});
						checked[y+1][x+1] = 1;
					}
    			}
    			newCluster.height = maxY-minY+1;
    			newCluster.width = maxX-minX+1;
    			newCluster.st.resize(newCluster.height, vector<bool>(newCluster.width));
    			REP(k, newCluster.height) REP(l, newCluster.width) newCluster.st[k][l] = (ans[minY+k][minX+l] == '1') && s[minY+k][minX+l];
    			bool flag = false;
    			int num = -1;
    			REP(k, clusters.size()) {
    				if(sameCluster(clusters[k], newCluster)) {
    					flag = true;
    					num = k;
    					break;
    				}
    			}
    			if(!flag) {
                    num = clusters.size();
                    clusters.push_back(newCluster);
                }
                char ch = num+'a';
                //DEBUG(ch);
                FOR(k, minY, maxY) FOR(l, minX, maxX) if(ans[k][l] == '1') ans[k][l] = ch;
                
                /*REP(k, h) {
                    REP(l, w) cout << ans[k][l];
                    cout << endl;
                }
                cout << endl;*/
    		}
    	}
    }
    REP(i, h) {
        REP(j, w) fout << ans[i][j];
        fout << endl;
    }

    return 0;
}
