#include "Deanery.h"

void Deanery::create_students(string file_name) {
	ifstream file(file_name);
	string line;
	int ident = -1;
	int numbSt_int;
	int numbSt_ost;
	if (file.is_open()) {
		while (getline(file, line)) {
			ident++;
			(this->students).push_back(new Student(ident, line));

		}
		file.close();
	}
	else
		cout << "file is not open" << endl;
}

void Deanery::create_groups(string file_name) {
	ifstream file(file_name);
	string line;
	int numbSt_int;
	int numbSt_ost;
	if (file.is_open()) {
		while (getline(file, line))
			(this->groups).push_back(new Group(line));
		file.close();
		if (!students.empty()) {
			numbSt_int = (this->students).size() / (this->groups).size();
			numbSt_ost = (this->students).size() % (this->groups).size();
			for (int i = 0; i < groups.size(); i++) {
				for (int j = 0; j < numbSt_int; j++) {
					this->students[i*numbSt_int + j]->add_in_Group(groups[i]);
					this->groups[i]->add_Student(students[i*numbSt_int + j]);
				}
			}
			for (int i = 0; i < numbSt_ost; i++) {
				this->students[(this->groups).size()*numbSt_int + i]->add_in_Group(groups[i]);
				this->groups[i]->add_Student(students[(this->groups).size()*numbSt_int + i]);
			}
		}
	}
	else
		cout << "file is not open" << endl;
	
}

void Deanery::add_mark(int k) {	//добавить по k рандомных оценок всем студентам
	srand(time(0));
	int mark;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < (this->students).size(); j++) {
			mark = rand() % 11;	//10-бальная система оценивания
			this->students[j]->add_mark(mark);
		}
	}
}

void Deanery::statistics() {
	int prev_numb = 0;	//количество студентов в предыдущих(по порядку в векторе) группах
	for (int i = 0; i < (this->groups).size(); i++) {
		cout << groups[i]->title << " - " << groups[i]->average_score() << endl;
		for (int j = prev_numb; j < prev_numb + (this->groups[i])->num; j++) {
			cout << students[j]->id << ' ' << students[j]->fio << " - " << students[j]->average_score() << endl;
		}
		prev_numb += groups[i]->num;
	}
}

void Deanery::transfer(Student* student, Group* to_group) {
	student->group->delete_student(student);
	student->add_in_Group(to_group);
	to_group->add_Student(student);
}

void Deanery::deduction() {
	for (int i = 0; i < (this->students).size(); i++) {
		if (students[i]->average_score() < 4) {
			students[i]->group->delete_student(students[i]);
			students.erase(remove(students.begin(), students.end(), students[i]), students.end());
		}
	}
}

void Deanery::fout(string file_name) {
	ofstream file;
	file.open(file_name);
	int prev_numb = 0;	//количество студентов в предыдущих(по порядку в векторе) группах
	for (int i = 0; i < (this->groups).size(); i++) {
		file << groups[i]->title << " - " << groups[i]->average_score() << endl;
		for (int j = prev_numb; j < prev_numb + (this->groups[i])->num; j++) {
			file << students[j]->id << ' ' << students[j]->fio << " - " << students[j]->average_score() << endl;
		}
		prev_numb += groups[i]->num;
	}
	file.close();
}

void Deanery::heads() {
	for (int i = 0; i < (this->groups).size(); i++) {
		groups[i]->choose_head();
	}
}

void Deanery::print_data() {
	int prev_numb = 0;	//количество студентов в предыдущих(по порядку в векторе) группах
	for (int i = 0; i < (this->groups).size(); i++) {
		cout << groups[i]->title << endl;
		for (int j = prev_numb; j < prev_numb + (this->groups[i])->num; j++) {
			cout << students[j]->id << ' ' << students[j]->fio;
			for (int k = 0; k < (this->students[i])->marks.size(); k++) {
				cout << ' ' << students[i]->marks[k];
			}
			cout << endl;
		}
		prev_numb += groups[i]->num;
	}
}