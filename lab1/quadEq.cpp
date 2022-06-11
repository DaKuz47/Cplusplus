#include <vector>
#include <iostream>
using namespace std;
//Дискременант
double diskremenant(double const a, double const b, double const c) {
	return b * b - 4 * a * c;
}

//Корни уравнения
vector<double> quad_eq_roots(vector<double> const coef) {
	vector<double> roots;
	double const a = coef[0];
	double const b = coef[1];
	double const c = coef[2];
	//Если пара a не 0 то считаем, дискременант
	//Если дискременант < 0 -корней нет, массив roots пуст
	if (a != 0) {			    
		double const D = diskremenant(a, b, c);					
		if(D >= 0) {
			roots.push_back((-1 * b + sqrt(D)) / (2 * a));
			if (D != 0) {
				roots.push_back((-1 * b - sqrt(D)) / (2 * a));
			}
		}
	}
	//Если только b не ноль, то получаем линейное уравнение
	//Если b нуль - либо корней нет, либо их бесконечное кол-во Массив roots пуст
	else if (b != 0) {										
		roots.push_back(-1 * c / b);
	}
	return roots;
}
