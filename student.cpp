#include "Student.h"

Student::Student() {
	cout << "Конструктор без параметров" << endl;
}

Student::Student(Student& obj) {
	cout << "Конструктор копирования" << endl;
	string bufStr1, bufStr2, bufStr3;
	int bufInt1, bufInt2, bufInt3;
	setSurname(obj.getSurname());
	setInitials(obj.getInitials());
	setGroup(obj.getGroup());
	obj.getEducation(bufStr1, bufInt1, bufStr2, bufInt2, bufStr3, bufInt3);
	setEducation(bufStr1, bufInt1, bufStr2, bufInt2, bufStr3, bufInt3);
}

Student::~Student() {
	cout << "Деструктор" << endl;
}

void Student::setSurname(string buf) {
	if (buf == "")
		throw exception("Неверная фамилия");
	surname = buf;
}

string Student::getSurname() { return surname; }
void Student::setInitials(string buf) {
	if (buf == "" || buf.size() != 4 || buf.find('.') == -1)
		throw exception("Неверные инициалы");
	initials = buf;
}

string Student::getInitials() { return initials; }
void Student::setGroup(int buf) {
	if (buf < 1000 || buf > 10000)
		throw exception("Неверный номер группы");
	group = buf;
}

int Student::getGroup() { 
	return group; 
}

void Student::setEducation(string bufStr1, int bufInt1, string bufStr2, int bufInt2,
	string bufStr3, int bufInt3) {
	if (bufStr1 == "" || bufStr2 == "" || bufStr3 == "")
		throw exception("Неверный предмет");
	if (bufInt1 < 2 || bufInt1 > 5 || bufInt2 < 2 || bufInt2 > 5 || bufInt3 < 2 ||
		bufInt3 > 5)
		throw exception("Неверная оценка");
	education[0].item = bufStr1;
	education[0].grade = bufInt1;
	education[1].item = bufStr2;
	education[1].grade = bufInt2;
	education[2].item = bufStr3;
	education[2].grade = bufInt3;
}

void Student::getEducation(string& bufStr1, int& bufInt1, string& bufStr2, int&
	bufInt2, string& bufStr3, int& bufInt3) {
	bufStr1 = education[0].item;
	bufInt1 = education[0].grade;
	bufStr2 = education[1].item;
	bufInt2 = education[1].grade;
	bufStr3 = education[2].item;
	bufInt3 = education[2].grade;
}

istream& operator>> (istream& in, Student& object) {
	string bufStr1, bufStr2, bufStr3;
	int bufInt1, bufInt2, bufInt3;
	cout << "Введите фамилию: ";
	in >> bufStr1;
	object.setSurname(bufStr1);
	cout << "Введите инициалы (И.О.): ";
	in >> bufStr1;
	object.setInitials(bufStr1);
	cout << "Введите номер группы: ";
	in >> bufInt1;
	object.setGroup(bufInt1);
	cout << "Введите\n\tпредмет1: ";
	in >> bufStr1;
	cout << "\tоценка1: ";
	in >> bufInt1;
	cout << "\tпредмет2: ";
	in >> bufStr2;
	cout << "\tоценка2: ";
	in >> bufInt2;
	cout << "\tпредмет3: ";
	in >> bufStr3;
	cout << "\tоценка3: ";
	in >> bufInt3;
	object.setEducation(bufStr1, bufInt1, bufStr2, bufInt2, bufStr3, bufInt3);
	cout << "Студент внесен в список" << endl;
	return in;
}

ostream& operator<< (ostream& out, Student& object) {
	string bufStr1, bufStr2, bufStr3;
	int bufInt1, bufInt2, bufInt3;
	out << "Студент: " << object.getSurname() << " " << object.getInitials() << endl;
	out << "Группа: " << object.getGroup() << endl;
	object.getEducation(bufStr1, bufInt1, bufStr2, bufInt2, bufStr3, bufInt3);
	out << "Предметы: " << "\n\t1 - " << bufStr1 << "\t" << bufInt1 <<
		"\n\t2 - " << bufStr2 << "\t" << bufInt2 <<
		"\n\t3 - " << bufStr3 << "\t" << bufInt3 << endl;
	return out;
}