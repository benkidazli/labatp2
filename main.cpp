#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include "Student.h"
using namespace std;
Student* students;
int n, index = 0;
void sort();
void exc();
int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// Задание 1
	char choice = '0';
	do {
		cout << "Введите количество студентов: " << endl;
		cin >> n;
	} while (n <= 0);
	students = new Student[n];
	while (choice != '5')
	{
		try
		{
			cout << "1 - Ввести элемент \n2 - Вывод всех элементов \n3 - Редактировать элемент \n4 - Удалить элемент \n5 - Выход \nПункт меню : ";
				cin >> choice;
			if (choice == '1')
			{
				if (index == n)
					throw exception("Массив уже заполнен");
				cin >> students[index];
				index++;
				sort();
			}
			else if (choice == '2')
			{
				if (index == 0)
					throw exception("Массив пуст");
				for (int i = 0; i < index; i++)
					cout << i + 1 << ": " << students[i];
			}
			else if (choice == '3')
			{
				int i;
				cout << "Введите номер элемента: ";
				cin >> i;
				i--;
				if (i < 0 || i >= index)
					throw exception("Неверный номер");
				cout << "Редактируемое поле: \n\t1 - Фамилия \n\t2 - Инициалы\n\t3 - Группа \n\t4 - Предмет и оценку\n\tПункт меню : ";
					cin >> choice;
				switch (choice)
				{
				case '1':
				{
					string buf;
					cout << "Новая фамилия: ";
					cin >> buf;
					students[i].setSurname(buf);
				}
				break;
				case '2':
				{
					string buf;
					cout << "Новые инициалы: ";
					cin >> buf;
					students[i].setInitials(buf);
				}
				break;
				case '3':
				{
					int buf;
					cout << "Новая группа: ";
					cin >> buf;
					students[i].setGroup(buf);
				}
				break;
				case '4':
				{
					string bufStr1, bufStr2, bufStr3;
					int bufInt1, bufInt2, bufInt3;
					char buf;
					cout << "Введите номер предмета от 1 до 3: ";
					cin >> buf;
					students[i].getEducation(bufStr1, bufInt1, bufStr2,
						bufInt2, bufStr3, bufInt3);
					if (buf == '1')
					{
						cout << "Введите новый предмет: ";
						cin >> bufStr1;
						cout << "Введите новую оценку: ";
						cin >> bufInt1;
					}
					else if (buf == '2')
					{
						cout << "Введите новый предмет: ";
						cin >> bufStr2;
						cout << "Введите новую оценку: ";
						cin >> bufInt2;
					}
					else if (buf == '3')
					{
						cout << "Введите новый предмет: ";
						cin >> bufStr3;
						cout << "Введите новую оценку: ";
						cin >> bufInt3;
					}
					else
						throw exception("Неверный номер предмета");
					students[i].setEducation(bufStr1, bufInt1, bufStr2,
						bufInt2, bufStr3, bufInt3);
				}
				break;
				default:
					throw exception("Неверный пункт меню");
				}
				choice = '3';
			}
			else if (choice == '4')
			{
				int i;
				cout << "Введите номер элемента: ";
				cin >> i;
				i--;
				if (i < 0 || i >= index)
					throw exception("Неверный номер");
				for (int j = i; j < index; j++)
					students[j] = students[j + 1];
				index--;
			}
			else if (choice == '5')
			{
				break;
			}
			else
			{
				throw exception("Неверный пункт меню");
			}
		}
		catch (const exception& exp)
		{
			cout << "Исключение: " << exp.what() << endl;
		}
		system("pause");
		system("cls");
	}
	exc();
	delete[]students;
	// Задание 2
	system("pause");
	system("cls");
	ifstream fin;
	string bufStr;
	int cnt = 0;
	fin.open("file.txt");
	try
	{
		if (!fin.is_open())
			throw exception("Файл отсутствует");
		while (getline(fin, bufStr))
		{
			for (int i = 0; i < bufStr.size(); i++)
			{
				if (((int)bufStr[i] >= 48 && (int)bufStr[i] <= 57) &&
					((int)bufStr[i + 1] >= 48 && (int)bufStr[i + 1] <= 57))
					if ((i + 2 == bufStr.size() || (int)bufStr[i + 2] < 48
						|| (int)bufStr[i + 2] > 57) &&
						(i == 0 || (int)bufStr[i - 1] < 48 ||
							(int)bufStr[i - 1] > 57))
					{
						cout << bufStr << endl;
						cnt++;
						continue;
					}
			}
		}
		if (cnt == 0)
			cout << "Таких строк нет" << endl;
	}
	catch (exception& exp)
	{
		cout << "Исключение: " << exp.what() << endl << endl;
	}
	fin.close();
	return 0;
}
void sort() {
	string bufStr1, bufStr2, bufStr3;
	int bufInt1, bufInt2, bufInt3;
	float sr1, sr2;
	Student bufStudent;
	for (int i = 0; i < index - 1; i++)
	{
		for (int j = 0; j < index - i - 1; j++)
		{
			students[j].getEducation(bufStr1, bufInt1, bufStr2, bufInt2, bufStr3,
				bufInt3);
			sr1 = (float)(bufInt1 + bufInt2 + bufInt3) / 3;
			students[j + 1].getEducation(bufStr1, bufInt1, bufStr2, bufInt2,
				bufStr3, bufInt3);
			sr2 = (float)(bufInt1 + bufInt2 + bufInt3) / 3;
			if (sr1 > sr2)
			{
				bufStudent = students[j];
				students[j] = students[j + 1];
				students[j + 1] = bufStudent;
			}
		}
	}
}
void exc() {
	string bufStr1, bufStr2, bufStr3;
	int bufInt1, bufInt2, bufInt3;
	int cnt = 0;
	cout << "Студенты, имеющие оценку 2: " << endl;
	for (int i = 0; i < index; i++)
	{
		students[i].getEducation(bufStr1, bufInt1, bufStr2, bufInt2, bufStr3,
			bufInt3);
		if (bufInt1 == 2 || bufInt2 == 2 || bufInt3 == 3)
		{
			cout << "\t" << cnt + 1 << ": " << students[i].getSurname() << ", "
				<< students[i].getGroup() << endl;
			cnt++;
		}
	}
	if (cnt == 0)
		cout << "\tТаких студентов нет" << endl;
}