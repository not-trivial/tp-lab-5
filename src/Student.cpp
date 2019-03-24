#include "Student.h"

Student::Student(int id, string fio) {
	this->id = id;
	this->fio = fio;
}

void Student::add_in_Group(Group* group) {
	this->group = group;
}

void Student::add_mark(int mark) {
	(this->marks).push_back(mark);
	(this->num)++;
}

float Student::average_score() {
	float sum = 0;
	for (int i = 0; i < this->num; i++) {
		sum += marks[i];
	}
	return sum / (this->num);
}
