#include "pch.h"
#include <iostream>
#include <locale>

using namespace std;

double f(double t, double y) {
	return sin(t) + y;
}

double Runge_Kutta(double t0, double y0, int n, double tn) {
	double h = (tn - t0) / n;
	double k1, k2, k3, k4, tm = t0, ym = y0;
	for (int i = 0; i < n; i++) {
		k1 = f(tm, ym);
		k2 = f(tm + h / 2, ym + (h*k1) / 2);
		k3 = f(tm + h / 2, ym + (h*k2) / 2);
		k4 = f(tm + h, ym + h*k3);
		ym += (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
		tm += h;
	}
	return ym;
}

int main()
{
	setlocale(LC_ALL, "");
	double t0, y0, tn, res;
	int n;
	cout << "Введите начальные условия" << endl;
	cout << "Введите t0: ";
	cin >> t0;
	cout << "Введите y0: ";
	cin >> y0;
	cout << "Введите точку tn в которой будет производиться вычисление: ";
	cin >> tn;
	cout << "Введите величину разбиения n: ";
	cin >> n;
	res = Runge_Kutta(t0, y0, n, tn);
	cout << "Результат вычисления: " << res << endl;
	return 0;
}

