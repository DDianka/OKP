// КурсоваяОКП.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
 // setlocale(LC_ALL, "rus");

struct User
{
	string login; 
	string password; 
	string fName;
	string lName;
};
const int RESERVE_SIZE = 5;
void writeEndFileUsers(User new_user);
void readFileUsers(User* arr_of_users, int& number_of_users);
int getCountOfStucturesInFile(string file_path);

int main()
{
	
	int actionCode;
	bool canContinue = true;
	User user;
	User arr_of_users[RESERVE_SIZE];
	int number_of_users = 5;

	while (canContinue)
	{
		cout << "1.Register" << endl << "2.Authorize" << endl;
		cin >> actionCode;
		system("CLS");
		switch (actionCode)
		{
			case 1:
			{	
				canContinue = false;
				cout << "Enter your Firsname: ";
				cin >> user.fName;
				cout << "Enter your Lastname: ";
				cin >> user.lName;
				cout << "Enter login: ";
				cin >> user.login;
				cout << "Enter password: ";
				cin >> user.password;
				break;
			}
			case 2:
			{	
				canContinue = false;
				cout << "Enter login: ";
				cin >> user.login;
				cout << "Enter password: ";
				cin >> user.password;
				break;
			}
			default:
			{
				cout << "Wrong input: " << actionCode << ". Try again entering 1 or 2." << endl;
				break;
			}
		}
	}
	
	if (actionCode == 1) 
	{
		cout << "write in file" << endl;
		writeEndFileUsers(user);
	}	
	else 
	{
		cout << "read from file 1" << endl;
		readFileUsers(arr_of_users, number_of_users);

		cout << "read from file 2" << endl;

	}
}

void writeEndFileUsers(User new_user)
{
	//Открываем файл для дозаписи:
	ofstream fadd("users.txt", ios::binary | ios::app);
	fadd.write((char*)& new_user, sizeof(new_user)); //Записали структуру
	fadd.close();
}

void readFileUsers(User* arr_of_users, int& number_of_users)
{
	ifstream fin("users.txt", ios::binary | ios::in);
	if (!fin.is_open()) cout << "Указанный файл не существует!" << endl;
	else
	{
		// определяем количество строк в файле
		int sizeOfFileWithStudents =
			getCountOfStucturesInFile("users.txt");
		/* если выделенная память под статический массив вмещает все
		строчки в файле */
		if (sizeOfFileWithStudents <= RESERVE_SIZE)
		{
			// будем считывать все строчки
			number_of_users = sizeOfFileWithStudents;
		}
		else
		{
			number_of_users = RESERVE_SIZE;
			cout << "There is not enough memory for read all data!" <<
				endl;
		}

		/* читаем сразу number_of_students-строчек из файла и
		сохраняем их в массиве */
		fin.read((char*)& arr_of_users[0],
			sizeof(User) * number_of_users);
	}
	fin.close();
}

int getCountOfStucturesInFile(string file_path)
{
	//Открываем файл и перемещаем указатель в конец файла
	ifstream file("users.txt", ios::ate | ios::binary);
	/*file.tellg() возвращает значение типа int, которое показывает,
	сколько указателем пройдено в байтах от начала файла до текущей
	позиции */
	int number_of_strings = file.tellg() / sizeof(User);
	file.close();
	return number_of_strings;
}