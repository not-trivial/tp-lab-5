#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <fstream>
#include "Student.h"
#include "Deanery.h"
#include "Group.h"
using namespace std;

int main()
{
	Deanery exp;
	string file1 = "../data/names.txt";
	string file2 = "../data/titles.txt";
	exp.create_students(file1);
	exp.create_groups(file2);
	exp.add_mark(5);

	exp.statistics();
	exp.deduction();
	exp.fout("../data/fout.txt");

	exp.print_data();

	system("pause");
    return 0;
}