#include "Group.h"

Group::Group(string title) {
	this->title = title;
}

void Group::add_Student(Student* student) {
	(this->students).push_back(student);
	(this->num)++;
}

void Group::choose_head() {
	int index_head;
	srand(time(0));
	index_head = rand() % (this->num - 1);
	head = students[index_head];
}

Student* Group::find_student(int id) {
	for (int i = 0; i < this->num; i++) {
		if ((this->students[i])->id == id) {
			return this->students[i];
		}
	}
	return NULL;
}

Student* Group::find_student(string fio) {
	for (int i = 0; i < this->num; i++) {
		if ((this->students[i])->fio == fio) {
			return this->students[i];
		}
	}
	return NULL;
}

float Group::average_score() {
	float sum = 0;
	for (int i = 0; i < this->num; i++) {
		sum += (this->students[i])->average_score();
	}
	return sum / (this->num);
}

void Group::delete_student(Student* student) {
	students.erase(remove(students.begin(),students.end(),student),students.end());
	//remove-erase-idiom: remove помещает все, требующие удаления значения в конец, а erase удаляет их
	if (student == head) {
		this->choose_head();
	}
	(this->num)--;
}