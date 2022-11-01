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
	// ������� 1
	char choice = '0';
	do {
		cout << "������� ���������� ���������: " << endl;
		cin >> n;
	} while (n <= 0);
	students = new Student[n];
	while (choice != '5')
	{
		try
		{
			cout << "1 - ������ ������� \n2 - ����� ���� ��������� \n3 - ������������� ������� \n4 - ������� ������� \n5 - ����� \n����� ���� : ";
				cin >> choice;
			if (choice == '1')
			{
				if (index == n)
					throw exception("������ ��� ��������");
				cin >> students[index];
				index++;
				sort();
			}
			else if (choice == '2')
			{
				if (index == 0)
					throw exception("������ ����");
				for (int i = 0; i < index; i++)
					cout << i + 1 << ": " << students[i];
			}
			else if (choice == '3')
			{
				int i;
				cout << "������� ����� ��������: ";
				cin >> i;
				i--;
				if (i < 0 || i >= index)
					throw exception("�������� �����");
				cout << "������������� ����: \n\t1 - ������� \n\t2 - ��������\n\t3 - ������ \n\t4 - ������� � ������\n\t����� ���� : ";
					cin >> choice;
				switch (choice)
				{
				case '1':
				{
					string buf;
					cout << "����� �������: ";
					cin >> buf;
					students[i].setSurname(buf);
				}
				break;
				case '2':
				{
					string buf;
					cout << "����� ��������: ";
					cin >> buf;
					students[i].setInitials(buf);
				}
				break;
				case '3':
				{
					int buf;
					cout << "����� ������: ";
					cin >> buf;
					students[i].setGroup(buf);
				}
				break;
				case '4':
				{
					string bufStr1, bufStr2, bufStr3;
					int bufInt1, bufInt2, bufInt3;
					char buf;
					cout << "������� ����� �������� �� 1 �� 3: ";
					cin >> buf;
					students[i].getEducation(bufStr1, bufInt1, bufStr2,
						bufInt2, bufStr3, bufInt3);
					if (buf == '1')
					{
						cout << "������� ����� �������: ";
						cin >> bufStr1;
						cout << "������� ����� ������: ";
						cin >> bufInt1;
					}
					else if (buf == '2')
					{
						cout << "������� ����� �������: ";
						cin >> bufStr2;
						cout << "������� ����� ������: ";
						cin >> bufInt2;
					}
					else if (buf == '3')
					{
						cout << "������� ����� �������: ";
						cin >> bufStr3;
						cout << "������� ����� ������: ";
						cin >> bufInt3;
					}
					else
						throw exception("�������� ����� ��������");
					students[i].setEducation(bufStr1, bufInt1, bufStr2,
						bufInt2, bufStr3, bufInt3);
				}
				break;
				default:
					throw exception("�������� ����� ����");
				}
				choice = '3';
			}
			else if (choice == '4')
			{
				int i;
				cout << "������� ����� ��������: ";
				cin >> i;
				i--;
				if (i < 0 || i >= index)
					throw exception("�������� �����");
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
				throw exception("�������� ����� ����");
			}
		}
		catch (const exception& exp)
		{
			cout << "����������: " << exp.what() << endl;
		}
		system("pause");
		system("cls");
	}
	exc();
	delete[]students;
	// ������� 2
	system("pause");
	system("cls");
	ifstream fin;
	string bufStr;
	int cnt = 0;
	fin.open("file.txt");
	try
	{
		if (!fin.is_open())
			throw exception("���� �����������");
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
			cout << "����� ����� ���" << endl;
	}
	catch (exception& exp)
	{
		cout << "����������: " << exp.what() << endl << endl;
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
	cout << "��������, ������� ������ 2: " << endl;
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
		cout << "\t����� ��������� ���" << endl;
}