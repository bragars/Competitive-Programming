#include <iostream>
using namespace std;
//Dynamic programming

// Exponencial complexity
int fib(int n) {
	if (n <= 1) 
		return n;
	return fib(n - 1) + fib(n - 2);
}

// Polynominal complexity
int fib_dp(int n) {
	int f[100] = {}; f[0] = 0; f[1] = 1;

	for (int i = 2; i <= n; i++)
		f[i] = f[i - 1] + f[i - 2];

	return f[n];
}

int main() {
	// Executes the app
	cout << fib(10) << "\n";
	cout << fib_dp(10) << "\n";
}
