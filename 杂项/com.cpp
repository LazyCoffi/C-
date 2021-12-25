#include <iostream>
#include <cmath>
using namespace std;

double f(double x, double y) {
	double e = 2.718281828;
	return x + pow(e, -x);
}

int main() {
	double y = 0, h = 0.1;
	for (double x = 0.1, i = 1; x < 2.05; x += 0.1, i ++) {
		y = f(x, y);
		cout << i << " " << y << endl;
	}
} 
