#include <vector>
#include <iostream>
using namespace std;
//diskiminant calculation
double diskremenant(double a, double b, double c) {
	return b * b - 4 * a * c;
}
enum roots_count {
	INF = -1,
	ZERO,
	ONE,
	TWO
};
//roots calculationes
vector<double> quad_eq_roots(vector<double> coef) {
	double a = coef[0];
	double b = coef[1];
	double c = coef[2];
	vector<double> roots{0};
	//Если пара a не 0 и ещё что-то не ноль, то считаем, как обычно
	if ((a != 0 && b != 0) || (a != 0 && c != 0)) {			
		double D = diskremenant(a, b, c);			
		if (D < 0) {						
			roots[0] = ZERO;
		}
		else {
			roots[0] = ONE;
			roots.push_back((-1 * b + sqrt(D)) / (2 * a));
			if (D != 0) {
				roots.push_back((-1 * b - sqrt(D)) / (2 * a));
				roots[0] = TWO;
			}
		}
	}
	//Если только a ноль, то получаем линейное уравнение
	else if (a == 0 && b != 0 && c != 0) {
		roots[0] = ONE;
		roots.push_back(-1 * c / b);
	}
	//Если все нули
	else if (a + b + c == 0) {
		roots[0] = INF;
	}
	// Если только c не ноль
	else if (c != 0) {
		roots[0] = ZERO;
	}
	//Если не ноль только a или только b
	else {
		roots[0] = ONe;
		roots.push_back(0);
	}
	return roots;
}

