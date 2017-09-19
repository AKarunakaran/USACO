/*
ID: aman.ka1
PROG: job
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

int main() {
    ifstream fin("job.in");
    ofstream fout("job.out");
    int n, na, nb, ans;
    fin >> n >> na >> nb;
    vector<int> a(na), b(nb), af(na, 0), bf(nb, 0), aj(n, 0), bj(n, 0);
    REP(i, na) fin >> a[i];
    REP(i, nb) fin >> b[i];
    REP(i, n) {
        int ef = INF, bestJob;
        REP(j, na) {
            if(af[j] + a[j] < ef) {
                ef = af[j]+a[j];
                bestJob = j;
            }
        }
        af[bestJob] += a[bestJob];
        ans = af[bestJob];
        aj[i] = ef;
    }
    fout << ans << " ";
    FORD(i, n-1, 0) {
        int ef = INF, bestJob;
        REP(j, nb) {
            if(bf[j] + b[j] < ef) {
                ef = bf[j]+b[j];
                bestJob = j;
            }
        }
        bf[bestJob] += b[bestJob];
        bj[i] = ef;
    }
    ans = 0;
    REP(i, n) ans = max(ans, aj[i]+bj[i]);
    fout << ans << endl;

    return 0;
}
