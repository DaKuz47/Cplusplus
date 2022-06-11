#include "school.h"
#include <fstream>


using namespace std;

int main() {
	schoolClass cl("10B");
	Teacher T;
	ifstream fin("students.txt");
	ifstream fitask("tasks.txt");
	//Считываем список класса
	string student;
	while (getline(fin, student)) {
		//Распределение успеваемости
		Student* st;
		int ran = rand() % 10 + 1;
		if (ran <= 2) {
			st = new GoodStudent(student);
		}
		else if (ran <= 8) {
			st = new NormalStudent(student);
		}
		else {
			st = new BadStudent(student);
		}
		cl.add_student(st);
	}
	//Считываем задания
	double num;
	vector<double> task;
	int i = 0;
	while ((fitask >> num)) {
		task.push_back(num);
		i++;
		if (i == 3) {
			T.add_task(task);
			task.clear();
			i = 0;
		}
	}
	//Проверка работ всего класса
	T.check_whole_class(&cl);

	return 0;
}