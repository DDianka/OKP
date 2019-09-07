// ConsoleAppForOKP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void log(int x, int y) {
	cout << "x: " << x << ", y: " << y << endl;
}

void firstWay() {
	int x = 2, y = 3, z;

	z = x; 
	x = y;
	y = z;
	log(x, y);
}

void secondWay() {
	int x = 2, y = 3;
	
	swap(x, y);
	log(x, y);
}

void thirdWay() {
	int x = 2, y = 3;

	x = x + y;
	y = y - x;
	y = -y;
	x = x - y;
	log(x, y);
}

void getLastNumber(int number) {
	cout << number % 10;
}

int main() {
	// firstWay();
	// secondWay();
	// thirdWay();

	// getLastNumber(321);


}

