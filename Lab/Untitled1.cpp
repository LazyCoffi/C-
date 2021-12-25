#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
	double a = -1.0;
	double sum = 0;
	double x[20] = {0, 19, 25, 31, 38, 44};
	double y[20] = {0, 19, 32.3, 49, 73.3, 97.8}; 
	for (int i = 1; i <= 9; i ++) {
		sum += x[i] * x[i] * y[i];
	}
	cout << sum;
}
