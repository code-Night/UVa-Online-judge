//============================================================================
// Name        : UVa-11516.cpp
// Author      : Ali Hafez
// Version     :
// Copyright   : Open Source
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const double EPS = 1e-3;


vector <int> houses ;
bool print = false ;
int num;
int APS;

bool f(double x) {
	int taken = 0;
	double place = x + houses[0];
	taken++;
	for (int i = 1; i < num; i++) {
		if (houses[i] >= place + x) {
			taken++;
			place = x + houses[i];
		}
	}
	return taken <= APS;
}

double first_true() {
	double lo = 0;
	double hi = houses[num - 1];
	double mid;
	while (hi - lo > EPS) {
		mid = (lo + hi) / 2;
		if (f(mid)) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	return hi;
}

int main() {
	int x;
	cin >> x;
	for (int j = 0; j < x; j++) {
		cin >> APS >> num;
		houses.resize(num) ;

		for (int i = 0; i < num; i++) {
			cin >> houses[i];
		}
		if(print)
			cout << endl ;
		sort(houses.begin(),houses.end());
		printf("%0.1lf", first_true());
		print = true ;
	}
	cout << endl ;
	return 0;
}
