#include <cmath>
#include <iostream>
using namespace std;

bool isPrime(long long);
void perfect(long long);

int main() {

	cout << "enter a number:" << endl;
	long long n;
	cin >> n;
	perfect(n);

	return 0;
}

bool isPrime(long long n) {
	if ((n < 2 || n % 2 == 0) && n != 2) {
		return false;
	}

	for (long long i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

void perfect(long long n) {
	for (long long p = 2; p * p <= n; p++) {
		if (isPrime(p)) {
			long long mp = pow(2, p) - 1;
			if (n < pow(2, p - 1) * mp) {
				return;
			}
			if (isPrime(mp)) {
				long long perfectNum = pow(2, p - 1) * mp;
				cout << perfectNum << endl;
			}
		}
	}
}