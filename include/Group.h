#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <fstream>
using namespace std;
class Student;
class Deanery;

class Group {
private:
	int num;
public:
	string title;
	vector <Student*> students;
	Student* head;

	friend Student;
	friend Deanery;

	Group(string title);
	void add_Student(Student* student);
	void choose_head();
	Student* find_student(int id);
	Student* find_student(string fio);
	float average_score();
	void delete_student(Student* student);
};
