#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
	vector<int> primes;
	vector<bool> p(100000001, 1);
	p[0] = p[1] = 0;

	for(int i = 2; i <= 10000; ++i) {
		if(p[i]) {
			for(int j = 2*i; j <= 10000000; j += i) {
				p[j] = 0;
			}
		}
	}

	for(int i = 0; i <= 10000000; ++i) {
		if(p[i]) {
			primes.push_back(i);
		}
	}

	cout << primes.size() << endl;

	return 0;
}