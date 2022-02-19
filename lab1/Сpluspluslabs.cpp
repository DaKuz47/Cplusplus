#include <vector>
#include <iostream>
using namespace std;
//diskiminant calculation
double diskremenant(double a, double b, double c) {
	return b * b - 4 * a * c;
}

//roots calculationes
vector<double> quad_eq_roots(double a, double b, double c) {
	vector<double> roots{0};
	if ((a != 0 && b != 0) || (a != 0 && c != 0)) {			//if roots[0] = 0 - no roots
		double D = diskremenant(a, b, c);					//1 - 1 or 2 roots
		if (D < 0) {										//2 - infinity roots
			roots[0] = 0;
		}
		else {
			roots[0] = 1;
			roots.push_back((-1 * b + sqrt(D)) / (2 * a));
			if (D != 0) {
				roots.push_back((-1 * b - sqrt(D)) / (2 * a));
			}
		}
	}
	else if (a == 0 && b != 0 && c != 0) {
		roots[0] = 1;
		roots.push_back(-1 * c / b);
	}
	else if (a + b + c == 0) {
		roots[0] = 2;
	}
	else if (c != 0) {
		roots[0] = 0;
	}
	else {
		roots[0] = 1;
		roots.push_back(0);
	}
	return roots;
}

int main()
{
	double a = 0, b = 0, c = 0;
	cout << "Enter the coefficient of the quadtratic equation" << endl;
	cin >> a >> b >> c;
	vector<double> roots = quad_eq_roots(a, b, c);
	if (roots[0] == 0) {
		cout << "no routs" << endl;
	}
	else if (roots[0] == 2) {
		cout << "roots is any number" << endl;
	}
	else {
		cout << "roots: ";
		roots.erase(roots.begin());
		for (auto x : roots) {
			cout << x << " ";
		}
		cout << endl;
	}
}

