#include <iostream>

using namespace std;

unsigned long long fiboarr[50] = { 0, 1, };

unsigned long long fibo(int n) {
	if (n == 0 || n == 1) return fiboarr[n];
	else if (fiboarr[n] == 0) fiboarr[n] = fibo(n - 1) + fibo(n - 2);
	return fiboarr[n];
}

void ex1003() {
	int T;
	cin >> T;

	int tmp;
	for (int i = 0; i < T; i++) {
		cin >> tmp;
		if (tmp == 0) cout << "1 0" << '\n';
		else cout << fibo(tmp - 1) << ' ' << fibo(tmp) << '\n';
	}
}