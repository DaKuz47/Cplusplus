#include <vector>
#include <iostream>


using namespace std;

#include "Header.h"

int main() {
	vector<double> coef(3);
	cout << "Input coefs of quadratique equation a, b, c: ";
	cin >> coef[0] >> coef[1] >> coef[2];
	vector<double> roots = quad_eq_roots(coef);

	if (roots.empty()){
		cout << "No roots or infinity roots" << endl;
	}
	else {
		cout << "roots: ";
		for (auto x : roots) {
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}