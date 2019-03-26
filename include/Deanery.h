#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <fstream>
#include "Student.h"
#include "Group.h"
using namespace std;

class Deanery {
private:
	vector <Student*> students;
	vector <Group*> groups;
public:	
	void create_students(string file_name);
	void create_groups(string file_name);
	void add_mark(int k);
	void statistics();
	void transfer(Student* student, Group* to_group);
	void deduction();
	void fout(string file_name);
	void heads();
	void print_data();
};
