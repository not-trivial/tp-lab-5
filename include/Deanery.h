#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <fstream>
using namespace std;
class Student;
class Group;

class Deanery {
public:
	vector <Student*> students;
	vector <Group*> groups;
	
	friend Student;
	friend Group;
	
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
