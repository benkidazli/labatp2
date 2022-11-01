#pragma once
#include <string>
#include <iostream>
using namespace std;
struct Education {
	string item;
	int grade;
};
class Student
{
	string surname;
	string initials;
	int group;
	Education education[3];
public:
	Student();
	Student(Student& obj);
	~Student();
	void setSurname(string buf);
	string getSurname();
	void setInitials(string buf);
	string getInitials();
	void setGroup(int buf);
	int getGroup();
	void setEducation(string bufStr1, int bufInt1, string bufStr2, int bufInt2, string
		bufStr3, int bufInt3);
	void getEducation(string& bufStr1, int& bufInt1, string& bufStr2, int& bufInt2,
		string& bufStr3, int& bufInt3);
	friend istream& operator>> (istream& in, Student& object);
	friend ostream& operator<< (ostream& out, Student& object);
};
