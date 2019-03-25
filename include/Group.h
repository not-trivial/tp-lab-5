#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <fstream>
#include "Student.h"
using namespace std;

class Group {
private:
	string title;
	vector <Student*> students;
	Student* head;
	int num;
public:
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
