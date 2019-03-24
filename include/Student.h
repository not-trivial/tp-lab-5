#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <fstream>
#include "Group.h"
using namespace std;

class Student {
private:
	int num;
public:
	int id;
	string fio;
	Group* group;
	vector<int> marks;
	
	friend Group;
	friend Deanery;

	Student(int id, string fio);
	void add_in_Group(Group* group);
	void add_mark(int mark);
	float average_score();
};