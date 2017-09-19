/*
ID: aman.ka1
PROG: heritage
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

ifstream fin("heritage.in");
ofstream fout("heritage.out");

string in, pre;

struct Node {
	Node* left;
	Node* right;
	char let;
};

void post(Node* n) {
	if(n->left) post(n->left);
	if(n->right) post(n->right);
	fout << n->let;
}

Node* tree(int startP, int endP, int startI, int endI) {
	Node* root = new Node{0, 0, pre[startP]};
	/*cout << pre[startP] << endl;
	cout << startP << " " << endP << "  " << startI << " " << endI << endl;
	cout << endl;*/
	if(startI < endI && startP < endP) {
		int i = startI;
		while(in[i] != pre[startP]) ++i;
		int lSz = i-startI;
		int rSz = endI-i;
		if(lSz) root->left = tree(startP+1, startP+lSz, startI, i-1);
		if(rSz) root->right = tree(endP-rSz+1, endP, i+1, endI);
	}
	return root;
}

int main() {
    fin >> in >> pre;
    Node* ans = tree(0, in.size()-1, 0, in.size()-1);
    post(ans);
    fout << endl;
    return 0;
}
