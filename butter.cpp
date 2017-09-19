/*
ID: aman.ka1
PROG: butter
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

int dist[801], p;

class Heap {
public:
    void push(int val) {
    	data.push_back(val);
    	fixUp();
    }

    void pop() {
    	data[0] = data.back();
	    data.pop_back();
	    fixDown(0);
    }

    int top() {
    	return data[0];
    }

    bool empty() {
    	return data.empty();
    }

    void update() {
    	for(size_t i = data.size()/2; i > 0; --i) {
	        fixDown(i-1);
	    }
    }

    void copy(const vector<int>& v, int i) {
    	data = v;
    	data[0] = i;
    	data[i-1] = 1;
    }

private:
	std::vector<int> data;
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
    void fixUp() {
        size_t k = data.size()-1;
        while(k > 0 && dist[data[(k-1)/2]] > dist[data[k]]) {
            swap(data[(k-1)/2], data[k]);
            k = (k-1)/2;
        }
    }
    void fixDown(size_t k) {
        size_t heapSize = data.size();
        while(2*k + 1 < heapSize && 2*k + 2 < heapSize && (dist[data[k]] > dist[data[2*k+1]] || dist[data[k]] > dist[data[2*k+2]])) {
            if(dist[data[2*k+1]] > dist[data[2*k+2]]) {
                swap(data[k], data[2*k+2]);
                k = 2*k+2;
            } else {
                swap(data[k], data[2*k+1]);
                k = 2*k+1;
            }
        }
        if(2*k + 1 < heapSize && dist[data[k]] > dist[data[2*k+1]]) {
            swap(data[k], data[2*k+1]);
        }
    }
};

int main() {
    ifstream fin("butter.in");
    ofstream fout("butter.out");
    int n, c, start, end, l, ans = INF;
    fin >> n >> p >> c;
    vector<int> numC(p+1, 0);
    vector<vector<pair<int, int>>> g(p+1);
    vector<bool> checked(p+1, 0);

    REP(i, n) {
    	fin >> start;
    	++numC[start];
    }
    REP(i, c) {
    	fin >> start >> end >> l;
    	g[start].push_back({end, l});
    	g[end].push_back({start, l});
    }
    Heap next;
    vector<int> startV(p, 0);
    REP(i, p) startV[i] = i+1;
    FOR(i, 1, p) {
    	//if(numC[i] == 0) continue;
    	FOR(j, 1, p) {
    		checked[j] = 0;
    		dist[j] = INF;
    	}
    	dist[i] = 0;
    	next.copy(startV, i);
    	int sum = 0;
    	while(!next.empty()) {
    		int cur = next.top();
    		next.pop();
    		checked[cur] = 1;
    		sum += dist[cur]*numC[cur];
    		if(sum > ans) break;
    		REP(j, g[cur].size()) {
    			if(checked[g[cur][j].first]) continue;
    			if(g[cur][j].second + dist[cur] < dist[g[cur][j].first]) {
    				dist[g[cur][j].first] = g[cur][j].second + dist[cur];
    			}
    		}
    		next.update();
    	}
    	//FOR(j, 1, p) sum += dist[j]*numC[j];

    	ans = min(sum, ans);
    }
    fout << ans << endl;

    return 0;
}
