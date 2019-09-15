// hwApp2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


#include <iostream>
using namespace std;


int main()
{
	int month;
	cout << "Enter month number: " << endl;
	cin >> month;
	switch (month) {
		case 12: case 1: case 2: cout << "Winter"; break;
		case 3: case 4: case 5: cout << "Spring"; break;
		case 6: case 7: case 8: cout << "Summer"; break;
		case 9: case 10: case 11: cout << "Autumn"; break;
		default: cout << "Wrong input"; break;
	}
}


